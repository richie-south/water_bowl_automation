#include <Servo.h>
#include <elapsedMillis.h>

Servo myservo;
elapsedMillis timeElapsed;

const int analogInPin = A0;
const int minWaterLevel = 280;
const int maxWaterLevel = 300;

const int valveClosedPos = 93;
const int valveFullyOpen = 10;

const int checkIntervall = 10000;
const int catShouldDrinkUpDelay = (1000 * 60) * 8; // delay that minimizes the risk of cat drinking water while refilling
const int valveOpenInterval = 8 * 1000; // max time the valve should be open
boolean isActive = true; // ability to "stop" the program
const int in = 4;

void setup() {
  Serial.begin(9600);
  pinMode(in, in);

  myservo.attach(9);
  myservo.write(valveClosedPos);
}

boolean isWaterUnderMinLevel() {
  int rd = digitalRead(in);
  return rd == HIGH;
}

void loop() {
  if (!isActive) {
    return false;
  }

  if (isWaterUnderMinLevel()) {
    Serial.println("isWaterUnderMinLevel: true");
    delay(checkIntervall);

    if (isWaterUnderMinLevel()) {
      Serial.println("again isWaterUnderMinLevel: true");
      Serial.println("open valve");

      timeElapsed = 0;
      myservo.write(valveFullyOpen + 40);


      while(isWaterUnderMinLevel() && timeElapsed < valveOpenInterval) {
        Serial.println("while isWaterUnderMinLevel: true");
      }

      if (timeElapsed >= valveOpenInterval) {
        Serial.println("Time has gone over board!");
        isActive = false;
      }

      Serial.println("close valve");
      myservo.write(valveClosedPos);
    }
  } else {

    Serial.println("was not under min level");
  }

  timeElapsed = 0;
  delay(checkIntervall);
}
