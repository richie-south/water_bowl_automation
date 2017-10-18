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
const unsigned long catShouldDrinkUpDelay = 480000; // 8 min, delay that minimizes the risk of cat drinking water while refilling
const int valveOpenInterval = 7000; // max time the valve should be open
boolean isActive = true; // ability to "stop" the program
const int in = 4;

void setup() {
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
    delay(catShouldDrinkUpDelay);

    if (isWaterUnderMinLevel()) {

      timeElapsed = 0;
      myservo.write(valveFullyOpen + 40);

      while(isWaterUnderMinLevel() && timeElapsed < valveOpenInterval) {
      }

      if (timeElapsed >= valveOpenInterval) {
        isActive = false;
      }

      myservo.write(valveClosedPos);
    }
  }

  timeElapsed = 0;
  delay(checkIntervall);
}
