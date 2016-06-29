/*
XBeeEcho
Reply with whatever you receive over the serial port
*/
int pinLed = 4;

void setup(){
  Serial.begin(9600);
}

void loop(){
  while (Serial.available()) {
    // reply with whatever you receive
    Serial.write(Serial.read());
    // blink when receives something
    //Serial.print('Woot!');
    digitalWrite(pinLed,HIGH);
    delay(100);
    digitalWrite(pinLed,LOW);
  }
}
