#include <Arduino.h>
#include <driver/twai.h>

void setup() {
  Serial.begin(115200);
  delay(2000);
  
  Serial.println("Starting CAN receiver...");

  twai_general_config_t g_config = TWAI_GENERAL_CONFIG_DEFAULT(GPIO_NUM_4, GPIO_NUM_16, TWAI_MODE_NORMAL);
  twai_timing_config_t  t_config = TWAI_TIMING_CONFIG_500KBITS();
  twai_filter_config_t  f_config = TWAI_FILTER_CONFIG_ACCEPT_ALL();

  if (twai_driver_install(&g_config, &t_config, &f_config) != ESP_OK) {
    Serial.println("TWAI install FAILED");
    while(1);
  }

  if (twai_start() != ESP_OK) {
    Serial.println("TWAI start FAILED");
    while(1);
  }

  Serial.println("CAN Ready - Waiting for messages...");
}

void loop() {
  twai_message_t msg;
  
  esp_err_t result = twai_receive(&msg, pdMS_TO_TICKS(1000));
  
  if (result == ESP_OK) {
    Serial.print("Received ID 0x");
    Serial.print(msg.identifier, HEX);
    Serial.print(": ");
    for (int i = 0; i < msg.data_length_code; i++) {
      Serial.print(msg.data[i], HEX);
      Serial.print(" ");
    }
    Serial.println();
  } else if (result == ESP_ERR_TIMEOUT) {
    // Print status every timeout
    twai_status_info_t status;
    twai_get_status_info(&status);
    Serial.print("Waiting... state:");
    Serial.print(status.state);
    Serial.print(" tx_err:");
    Serial.print(status.tx_error_counter);
    Serial.print(" rx_err:");
    Serial.println(status.rx_error_counter);
  } else {
    Serial.print("Receive error: ");
    Serial.println(result);
  }
}