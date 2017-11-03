#include <Servo.h>
#include <elapsedMillis.h>

Servo myservo;
const int valveClosedPos = 93;
const int valveFullyOpen = 10;
const int checkIntervall = 10000;
const unsigned long catShouldDrinkUpDelay = 480000; // 8 min, delay that minimizes the risk of cat drinking water while refilling
const unsigned long sleepAfterFill = 18000000;
const int in = 4;
boolean isActive = true; // ability to "stop" the program

void setup() {
  pinMode(in, in);
  myservo.attach(9);
  myservo.write(valveClosedPos);
}

boolean isWaterUnderMinLevel() {
  return digitalRead(in) == HIGH;
}

void fillWater() {
  elapsedMillis timeElapsed = 0;
  const int valveOpenInterval = 9000; // max time the valve should be open
  myservo.write(valveFullyOpen + 30);

  // checks water level and time valve has been open
  while(isWaterUnderMinLevel() && timeElapsed < valveOpenInterval) {
    // filling bowl with water
  }

  // "stops" program if valve has been open to loong
  if (timeElapsed >= valveOpenInterval) {
    isActive = false;
  }

  myservo.write(valveClosedPos);
}

void loop() {
  if (!isActive) {
    return false;
  }

  if (isWaterUnderMinLevel()) {
    delay(catShouldDrinkUpDelay);

    if (isWaterUnderMinLevel()) {
      fillWater();
      delay(sleepAfterFill);
    }
  }
  delay(checkIntervall);
}
