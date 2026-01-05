#include <AccelStepper.h>

#define BASE_STEP_PIN 4
#define BASE_DIR_PIN  5

#define SHOULDER_STEP_PIN 6
#define SHOULDER_DIR_PIN  7

#define ELBOW_STEP_PIN 8
#define ELBOW_DIR_PIN  9

#define WRIST_STEP_PIN 10
#define WRIST_DIR_PIN  11

AccelStepper baseMotor(1, BASE_STEP_PIN, BASE_DIR_PIN);
AccelStepper shoulderMotor(1, SHOULDER_STEP_PIN, SHOULDER_DIR_PIN);
AccelStepper elbowMotor(1, ELBOW_STEP_PIN, ELBOW_DIR_PIN);
AccelStepper wristMotor(1, WRIST_STEP_PIN, WRIST_DIR_PIN);

void setup() {
  Serial.begin(9600);
  
  baseMotor.setMaxSpeed(800);
  baseMotor.setAcceleration(400);
  
  shoulderMotor.setMaxSpeed(800);
  shoulderMotor.setAcceleration(400);
  
  elbowMotor.setMaxSpeed(800);
  elbowMotor.setAcceleration(400);
  
  wristMotor.setMaxSpeed(800);
  wristMotor.setAcceleration(400);
}

void loop() {
  if (Serial.available() > 0) {
    String command = Serial.readStringUntil('\n');
    parseAndMove(command);
  }

  baseMotor.run();
  shoulderMotor.run();
  elbowMotor.run();
  wristMotor.run();
}

void parseAndMove(String command) {
  int values[4];
  int startIndex = 0;
  int commaIndex;

  for (int i = 0; i < 4; i++) {
    commaIndex = command.indexOf(',', startIndex);
    if (commaIndex != -1) {
      values[i] = command.substring(startIndex, commaIndex).toInt();
      startIndex = commaIndex + 1;
    } else {
      values[i] = command.substring(startIndex).toInt();
    }
  }

  baseMotor.moveTo(values[0]);
  shoulderMotor.moveTo(values[1]);
  elbowMotor.moveTo(values[2]);
  wristMotor.moveTo(values[3]);
}