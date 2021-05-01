/*
  *
  * Modificacion para Arduino
  * Envia dato al puerto serial
  * solo valores positivos
  *
  */
 
 float vPow = 4.6;
 float r1 = 100000.0;
 float r2 = 10000.0;

 
 void setup() {
   Serial.begin(9600);
   delay(500);
 }
 
 void loop() {
   float v = (analogRead(0) * vPow) / 1024.0;
   float v2 = v / (r2 / (r1 + r2));
        
   
   // Envia codigo ANSI al puerto serial
   Serial.println(v2);
   Serial.print("V= ");
   delay(500);
 }
