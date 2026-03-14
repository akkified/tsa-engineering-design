#include <Arduino.h>

void setup() {
  Serial.begin(115200);
  delay(1000); // allow serial monitor to connect
}

void loop() {
  Serial.println("Hello World");
  delay(1000);
}
