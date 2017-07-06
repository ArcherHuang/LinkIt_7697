#define DoPIN 0 
#define RePIN 3 
#define MiPIN 4 
#define FaPIN 5 
#define SoPIN 8 
#define LaPIN 9 
#define TiPIN 14
#define buzzerPIN 15

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  pinMode(buzzerPIN, OUTPUT);
  pinMode(DoPIN, INPUT);
  pinMode(RePIN, INPUT);
  pinMode(MiPIN, INPUT);
  pinMode(FaPIN, INPUT);
  pinMode(SoPIN, INPUT);
  pinMode(LaPIN, INPUT);
  pinMode(TiPIN, INPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  
  byte doPinValue = digitalRead(DoPIN);
  byte rePinValue = digitalRead(RePIN);
  byte miPinValue = digitalRead(MiPIN);
  byte faPinValue = digitalRead(FaPIN);
  byte soPinValue = digitalRead(SoPIN);
  byte laPinValue = digitalRead(LaPIN);
  byte tiPinValue = digitalRead(TiPIN);
  
  if( doPinValue == 0 ){
    Serial.println("Do");
    tone(15, 262);
  } else if ( rePinValue == 0 ){
    Serial.println("Ra");
    tone(15, 294);
  } else if ( miPinValue == 0 ){
    Serial.println("Mi");
    tone(15, 330);
  } else if ( faPinValue == 0 ){
    Serial.println("Fa");
    tone(15, 349);
  } else if ( soPinValue == 0 ){
    Serial.println("So");
    tone(15, 392);
  } else if ( laPinValue == 0 ){
    Serial.println("La");
    tone(15, 440);
  } else if ( tiPinValue == 0 ){
    Serial.println("Ti");
    tone(15, 494);
  } else {
    noTone(buzzerPIN);
  }
}
