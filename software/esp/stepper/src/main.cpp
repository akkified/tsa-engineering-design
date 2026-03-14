#include <Arduino.h>
#include <driver/twai.h>
#include <esp_task_wdt.h>

#define MY_MOTOR_ID  0x100
#define BROADCAST_ID 0x1FF

#define STEP_PIN 26
#define DIR_PIN  27
#define EN_PIN   25

#define MOTOR_STEPS 200
#define GEAR_RATIO  112
#define MICROSTEPS  16

int step_delay = 60;
bool can_ready = false;

void setup() {
  Serial.begin(115200);
  delay(2000); // Give serial time to connect

  // Disable watchdog so CAN init doesn't get killed
  esp_task_wdt_deinit();

  // Motor setup
  pinMode(STEP_PIN, OUTPUT);
  pinMode(DIR_PIN,  OUTPUT);
  pinMode(EN_PIN,   OUTPUT);
  digitalWrite(EN_PIN, LOW);
  digitalWrite(DIR_PIN, HIGH);

  // CAN setup
  twai_general_config_t g_config = TWAI_GENERAL_CONFIG_DEFAULT(GPIO_NUM_4, GPIO_NUM_22, TWAI_MODE_NORMAL);
  twai_timing_config_t  t_config = TWAI_TIMING_CONFIG_500KBITS();
  twai_filter_config_t  f_config = TWAI_FILTER_CONFIG_ACCEPT_ALL();

  if (twai_driver_install(&g_config, &t_config, &f_config) != ESP_OK) {
    Serial.println("TWAI install FAILED - running without CAN");
    return; // Don't while(1) - let loop() run safely
  }

  if (twai_start() != ESP_OK) {
    Serial.println("TWAI start FAILED - running without CAN");
    return;
  }

  can_ready = true;
  Serial.printf("Motor Node Ready - ID: 0x%03X\n", MY_MOTOR_ID);
}

void step_motor(long steps) {
  for (long i = 0; i < steps; i++) {
    digitalWrite(STEP_PIN, HIGH);
    delayMicroseconds(step_delay);
    digitalWrite(STEP_PIN, LOW);
    delayMicroseconds(step_delay);
  }
}

void loop() {
  if (!can_ready) {
    Serial.println("CAN not ready - waiting...");
    delay(2000);
    return;
  }

  twai_message_t msg;
  if (twai_receive(&msg, 0) == ESP_OK) { // Non-blocking
    if (msg.data_length_code >= 5 &&
       (msg.identifier == MY_MOTOR_ID || msg.identifier == BROADCAST_ID)) {

      long steps = msg.data[0]
                 | ((long)msg.data[1] << 8)
                 | ((long)msg.data[2] << 16)
                 | ((long)msg.data[3] << 24);

      byte direction = msg.data[4];

      Serial.printf("CMD: %ld steps, dir=%d\n", steps, direction);
      digitalWrite(DIR_PIN, direction == 0 ? HIGH : LOW);
      step_motor(steps);
      Serial.println("Done");
    }
  }

  delay(1); // Yield to system tasks
}