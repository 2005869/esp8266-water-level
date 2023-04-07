#include <Arduino.h>

int sensorPin = A0;
int digitalPin = D1;

int level = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  pinMode(digitalPin, OUTPUT);
  digitalWrite(digitalPin, LOW);

}

void loop() {
  // put your main code here, to run repeatedly:

  digitalWrite(digitalPin, HIGH);
  delay(1000);
  level = analogRead(sensorPin);
  digitalWrite(digitalPin, LOW);
  Serial.print("Level of water: ");
  Serial.println(level);
  delay(10000);
}