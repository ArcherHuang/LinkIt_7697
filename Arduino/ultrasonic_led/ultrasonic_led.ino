#include <Ultrasonic.h>

Ultrasonic ultrasonic(2, 3);

void setup() {
  Serial.begin(9600);
  pinMode(4, OUTPUT);
}

void loop() {
  int distance = ultrasonic.distanceRead();
  Serial.print("Distance in CM: ");
  // Pass INC as a parameter to get the distance in inches
  Serial.println(distance);
  if (distance < 5) {
    digitalWrite(4, HIGH);
  } else {
    digitalWrite(4, LOW);
  }
  delay(100);
}
