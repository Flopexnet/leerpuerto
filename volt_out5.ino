/*
  *
  * Lectura de 5 lecturas de voltaje
  * Voltimetro DC Arduino
  * VALORES POSITIVOS
  *
  */
 
 float vPowa = 4.95;
 float r1a = 100000.0;
 float r2a = 10000.0;
 
 float vPowb = 4.92;
 float r1b = 100000.0;
 float r2b = 10000.0;
 
 float vPowc = 4.92;
 float r1c = 100000.0;
 float r2c = 10000.0;
 
 float vPowd = 4.92;
 float r1d = 100000.0;
 float r2d = 10000.0;
 
 float vPowe = 4.90;
 float r1e = 100000.0;
 float r2e = 10000.0;

 
 void setup() {
   Serial.begin(9600);
   delay(500);
 }
 
 void loop() {
   float va = (analogRead(0) * vPowa) / 1024.0;
   float v2a = va / (r2a / (r1a + r2a));
   delay(100);
   float vb = (analogRead(1) * vPowb) / 1024.0;
   float v2b = vb / (r2b / (r1b + r2b));
   delay(100);
   float vc = (analogRead(2) * vPowc) / 1024.0;
   float v2c = vc / (r2c / (r1c + r2c));
   delay(100);    
   float vd = (analogRead(3) * vPowd) / 1024.0;
   float v2d = vd / (r2d / (r1d + r2d));
   delay(100);
   float ve = (analogRead(4) * vPowe) / 1024.0;
   float v2e = ve / (r2e / (r1e + r2e));
   delay(100);     
   
   // Envia datos al puerto serial
   
   Serial.print("V1= ");
   Serial.println(v2a);
   
   Serial.print("V2= ");
   Serial.println(v2b);
   
   Serial.print("V3= ");
   Serial.println(v2c);
   
   Serial.print("V4= ");
   Serial.println(v2d);
   
   Serial.print("V5= ");
   Serial.println(v2e);
   
   delay(1160);
   
 }
