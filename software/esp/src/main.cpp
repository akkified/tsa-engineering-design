#include <Arduino.h>
#include <driver/twai.h>

// ========================================
// CHANGE THIS FOR EACH ESP32
// ========================================
#define MY_MOTOR_ID 0x100    // ESP32 #1 = 0x100, #2 = 0x101, #3 = 0x102
#define BROADCAST_ID 0x1FF   // Responds to broadcast too
// ========================================

// Motor pins
#define STEP_PIN 26
#define DIR_PIN 27
#define EN_PIN 25

// Motor constants
#define MOTOR_STEPS 200
#define GEAR_RATIO 112
#define MICROSTEPS 16

int step_delay = 60;

void setup() {
  Serial.begin(115200);
  
  // Motor setup
  pinMode(STEP_PIN, OUTPUT);
  pinMode(DIR_PIN, OUTPUT);
  pinMode(EN_PIN, OUTPUT);
  
  digitalWrite(EN_PIN, LOW);
  digitalWrite(DIR_PIN, HIGH);
  
  // CAN setup
  twai_general_config_t g_config = TWAI_GENERAL_CONFIG_DEFAULT(GPIO_NUM_4, GPIO_NUM_22, TWAI_MODE_NORMAL);
  twai_timing_config_t t_config = TWAI_TIMING_CONFIG_500KBITS();
  twai_filter_config_t f_config = TWAI_FILTER_CONFIG_ACCEPT_ALL();
  
  if (twai_driver_install(&g_config, &t_config, &f_config) != ESP_OK) {
    Serial.println("TWAI install FAILED");
    while(1);
  }
  
  if (twai_start() != ESP_OK) {
    Serial.println("TWAI start FAILED");
    while(1);
  }
  
  Serial.print("Motor Node Ready - ID: 0x");
  Serial.println(MY_MOTOR_ID, HEX);
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
  twai_message_t msg;
  esp_err_t result = twai_receive(&msg, pdMS_TO_TICKS(100));
  
  if (result == ESP_OK && msg.data_length_code >= 5) {
    // Only respond to MY_MOTOR_ID or BROADCAST_ID
    if (msg.identifier == MY_MOTOR_ID || msg.identifier == BROADCAST_ID) {
      
      long steps = msg.data[0] | 
                   ((long)msg.data[1] << 8) | 
                   ((long)msg.data[2] << 16) | 
                   ((long)msg.data[3] << 24);
      
      byte direction = msg.data[4];
      
      Serial.printf("CMD received: %ld steps, dir=%d\n", steps, direction);
      
      digitalWrite(DIR_PIN, direction == 0 ? HIGH : LOW);
      step_motor(steps);
      
      Serial.println("Done");
    }
  }
}