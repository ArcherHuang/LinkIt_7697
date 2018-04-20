#include <LRemote.h>
 
LRemoteSwitch switchButton;

void setup() {
  // put your setup code here, to run once:

  // Initialize GPIO
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, 0);

  // Setup the Remote Control's UI canvas
  LRemote.setName("setName");
  LRemote.setOrientation(RC_PORTRAIT);
  LRemote.setGrid(3, 5);
  
  // Add an on/off switch
  switchButton.setText("USR LED");
  switchButton.setPos(0, 1);
  switchButton.setSize(1, 1);
  switchButton.setColor(RC_BLUE);
  LRemote.addControl(switchButton);
  LRemote.begin();

  Serial.println("begin() returned");
}

void loop() {
  // put your main code here, to run repeatedly:

  if(!LRemote.connected()) {
    Serial.println("waiting for connection");
    delay(1000);
  } else {
    delay(15);
  }
  
  LRemote.process();
  if(switchButton.isValueChanged()){
    digitalWrite(LED_BUILTIN, switchButton.getValue());
  }
}
