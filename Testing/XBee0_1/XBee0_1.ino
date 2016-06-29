#include <SoftwareSerial.h>
// For the electronic wiring , you should :
// Connect pinRx to the Pin2 of XBee(Tx , Dout)
// Connect pinTx to the Pin3 of XBee(Rx , Din)

// Define the pins on Arduino for XBee comminication
uint8_t pinRx = 0 , pinTx = 1, pinLED = 5;// the pin on Arduino
long BaudRate = 9600 , sysTick = 0;
char GotChar;
// Initialize SoftwareSerial
SoftwareSerial mySerial( pinRx , pinTx );

void setup()  
{ // You shall see these messages in Arduino Serial Monitor
// This part is the official library , it will be used for talking to
// PC serial port
  Serial.begin(BaudRate);
  Serial.println("XBee Communication Test Start !");
  Serial.print("BaudRate:");
  Serial.println(BaudRate);
  Serial.print("NewSoftSerial Rx Pin#");
  Serial.println(pinRx,DEC);
  Serial.print("NewSoftSerial Tx Pin#");
  Serial.println(pinTx,DEC);

  // This part is the NewSoftSerial for talking to XBee
  mySerial.begin(BaudRate);
  mySerial.println("Powered by NewSoftSerial !");
  
  // LED pin initialize
  pinMode(pinLED, OUTPUT);
}

void loop()                    
{
  sysTick++ ; // a system timer
/* //for debug
  Serial.print("Xbee Timer :");
  Serial.println(sysTick);
  mySerial.print("Xbee Timer :");
  mySerial.println(sysTick);
*/
// Monitor Rx from PC , if the data is available then read
// it to "GotChar".    Then ask XBee send the data out 
// wirelessly.
  if ( Serial.available() ) {
      GotChar = Serial.read();
      mySerial.print(GotChar);
  }
// Monitor data from XBee , if the data is available then 
// read it to "GotChar".    Then send it back to PC.
  if ( mySerial.available() ) {
      GotChar = mySerial.read();
      //Serial.print(GotChar,BYTE);
      digitalWrite(pinLED,HIGH);
      delay(200);
      digitalWrite(pinLED,LOW);
      
  }
}

