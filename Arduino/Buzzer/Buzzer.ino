/*
 * Generated using BlocklyDuino:
 *
 * https://github.com/MediaTek-Labs/BlocklyDuino-for-LinkIt
 *
 * Date: Sun, 03 Sep 2017 02:59:35 GMT
 */



int item;

void setup()
{
  pinMode(14, INPUT);
  Serial.begin(9600);

  pinMode(LED_BUILTIN, OUTPUT);
}


void loop()
{
  item = digitalRead(14);
  if (item == 0) {
    Serial.print("HIGH");
    digitalWrite(LED_BUILTIN, HIGH);
    tone(3, 262);
    delay(2000);

  } else {
    digitalWrite(LED_BUILTIN, LOW);
    noTone(3);
  }
}
