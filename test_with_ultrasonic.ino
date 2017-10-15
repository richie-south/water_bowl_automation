#include <Servo.h>
Servo myservo;

const int trigPin = 9;
const int echoPin = 10;

long duration;
int distance;

const int minWaterLevel = 8;
const int maxWaterLevel = 5;

const int valveClosedPos = 93;
const int valveFullyOpen = 10;

void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  myservo.attach(11);
  myservo.write(valveClosedPos);
  Serial.begin(9600); // Starts the serial communication
}

boolean isWaterUnderMinLevel(int minLevel){
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance= duration*0.034/2;

  Serial.println(distance);
  return distance >= minLevel;
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
  delay(8000);
}

