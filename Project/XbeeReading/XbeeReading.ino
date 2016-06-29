/*
Taller de arte interactivo
Aaron Montoya - Nicolas Pena
noviembre 2013
*/

// inicializacion de sensores
int sensorDigital0 = 0;
int sensorAnalogo0 = 0;
int sensorAnalogo1 = 0;

// bloque setup
void setup() { 
 
  // comunicacion serial a 9600 bits por segundo
  Serial.begin(9600);
  
  // pin13 se define como entrada digital
  pinMode(13, OUTPUT);      
}

// bloque loop
void loop() {   

  // lectura de sensor analogo en pin A0
  sensorAnalogo0 = analogRead(A0);
  
  // lectura de sensor analogo en pin A1
  sensorAnalogo1 = analogRead(A1);
  

  
  // imprimir en pantalla los valores:
  Serial.println(sensorA0);
  Serial.println(sensorA1);
  
  // delay de 1 ms, para mejorar estabilidad de lectura
  delay(1);        
  
}


