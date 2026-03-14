#include <SPI.h>
#include <mcp2515_can.h>

const int SPI_CS_PIN = 9;
mcp2515_can CAN(SPI_CS_PIN);

// Motor CAN IDs
#define MOTOR_1_ID 0x100
#define MOTOR_2_ID 0x101
#define MOTOR_3_ID 0x102
#define ALL_MOTORS_ID 0x1FF  // Broadcast to all

void setup() {
  Serial.begin(115200);
  while (!Serial);
  
  while (CAN_OK != CAN.begin(CAN_500KBPS)) {
    Serial.println("CAN init failed, retrying...");
    delay(100);
  }
  
  Serial.println("CAN Motor Controller Ready");
  Serial.println("Commands:");
  Serial.println("  1 - Motor 1 quarter turn");
  Serial.println("  2 - Motor 2 quarter turn");
  Serial.println("  3 - Motor 3 quarter turn");
  Serial.println("  a - ALL motors quarter turn");
  Serial.println("  r - Reverse all motors");
}

void sendMotorCommand(unsigned long canId, long steps, byte direction) {
  unsigned char data[5];
  
  data[0] = steps & 0xFF;
  data[1] = (steps >> 8) & 0xFF;
  data[2] = (steps >> 16) & 0xFF;
  data[3] = (steps >> 24) & 0xFF;
  data[4] = direction;
  
  byte result = CAN.sendMsgBuf(canId, 0, 5, data);
  
  if (result == CAN_OK) {
    Serial.print("Sent to 0x");
    Serial.print(canId, HEX);
    Serial.print(": ");
    Serial.print(steps);
    Serial.println(" steps");
  } else {
    Serial.println("Send FAILED");
  }
}

void loop() {
  if (Serial.available()) {
    char cmd = Serial.read();
    
    long quarter_turn = 200L * 112 * 16 / 4;  // 89600 steps
    
    switch (cmd) {
      case '1':
        sendMotorCommand(MOTOR_1_ID, quarter_turn, 0);
        break;
      case '2':
        sendMotorCommand(MOTOR_2_ID, quarter_turn, 0);
        break;
      case '3':
        sendMotorCommand(MOTOR_3_ID, quarter_turn, 0);
        break;
      case 'a':
        sendMotorCommand(ALL_MOTORS_ID, quarter_turn, 0);
        break;
      case 'r':
        sendMotorCommand(ALL_MOTORS_ID, quarter_turn, 1);
        break;
    }
  }
}