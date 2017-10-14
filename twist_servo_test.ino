#include <Servo.h>

Servo myservo;

int closedPos = 93;
int fullyOpen = 10;
int pos = 0;

void setup() {
  myservo.attach(9);
}

void loop() {
  for (pos = fullyOpen; pos <= closedPos; pos += 1) {
    myservo.write(pos);
    delay(26);
  }
}
