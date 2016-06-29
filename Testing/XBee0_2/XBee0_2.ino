/*
XBeeEcho
Reply with whatever you receive over the serial port
*/
int pinLed = 5;

void setup(){
  Serial.begin(9600);
}

void loop(){
  while (Serial.available()) {
    // reply with whatever you receive
    Serial.write(Serial.read());
    // blink when receives something
    Serial.println(" Woot!");
    digitalWrite(pinLed,HIGH);
    delay(100);
    digitalWrite(pinLed,LOW);
  }
}
