/* XBee Echo
Reply with whatever you recieve over the serial port */

int incomingByte = 0;

void setup(){
  Serial.begin(9600);
}

void loop(){
  while (Serial.available()){
    incomingByte = Serial.read();
    Serial.write(incomingByte);
    Serial.println(incomingByte);
  }
}
