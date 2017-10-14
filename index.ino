#include <Servo.h>

Servo myservo;
const int analogInPin = A0;
const int minWaterLevel = 280;
const int maxWaterLevel = 300;

const int valveClosedPos = 93;
const int valveFullyOpen = 10;

void setup() {
  Serial.begin(9600);
  myservo.attach(9);
  myservo.write(valveClosedPos);
}

boolean isWaterUnderMinLevel(int minLevel) {
  int sensorValue = analogRead(analogInPin);
  Serial.println(sensorValue);
  return sensorValue <= minLevel;
}

void loop() {
  if (isWaterUnderMinLevel(minWaterLevel)) {
    Serial.println("isWaterUnderMinLevel: true");
    delay(15000);

    if (isWaterUnderMinLevel(minWaterLevel)) {
      Serial.println("again isWaterUnderMinLevel: true");
      Serial.println("open valve");
      myservo.write(valveFullyOpen + 40);

      while(isWaterUnderMinLevel(maxWaterLevel)) {
        Serial.println("while isWaterUnderMinLevel: true");
      }

      Serial.println("close valve");
      myservo.write(valveClosedPos);
    }
  }
  delay(15000);
  // get water sensor level

  // if level is under 140, wait for 5 minutes

  // check water level again
  // if level is under 140, open servo
  // read water level every 100mm
  // when water level is over 140 close servo

}
