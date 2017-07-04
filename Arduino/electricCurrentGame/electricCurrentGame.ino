void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  pinMode(14,INPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  
  byte isboon = digitalRead(14);
//  Serial.println(isboon);
  
  if(isboon==0){
    digitalWrite(LED_BUILTIN, HIGH);
    Serial.println("HIGH");
  }else{
    digitalWrite(LED_BUILTIN, LOW);
  }

}
