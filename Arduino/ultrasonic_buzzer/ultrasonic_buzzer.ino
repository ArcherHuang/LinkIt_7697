#include <Ultrasonic.h>

#define buzzerPIN 4
Ultrasonic ultrasonic(2, 3);

void setup() {
  Serial.begin(9600);
  pinMode(buzzerPIN, OUTPUT);
}

void loop() {
  int distance = ultrasonic.distanceRead();
  Serial.print("Distance in CM: ");
  // Pass INC as a parameter to get the distance in inches
  Serial.println(distance);
  if (distance < 5) {
    tone(buzzerPIN, 262);
  } else {
    noTone(buzzerPIN);
  }
  delay(100);
}
