void setup()
{
  Serial.begin(9600);
}


void loop()
{
  Serial.print("光感:");
  Serial.println(analogRead(A0));
  delay(1000);
}
