#include <SoftwareSerial.h>
SoftwareSerial BTSerial(10, 11);
int nut =7;
void setup()
{
  pinMode(13,OUTPUT);
  pinMode (nut, INPUT);
  BTSerial.begin(9600);
  Serial.begin(9600);
}
void loop()
{
  int ni = digitalRead(nut);
  Serial.println(ni);
  if(ni==1)
  {
    //digitalWrite(13,HIGH);
     BTSerial.write('1'); 
  }
  else{
    //digitalWrite(13,LOW);
     BTSerial.write('0'); 
  }
  delay(500);
  
}


//#include <SoftwareSerial.h>
//SoftwareSerial BTSerial(10, 11);
//
//void setup() {
//  Serial.begin(9600);
//  BTSerial.begin(9600);
//}
//
//void loop() {  
//  BTSerial.write('1');
//  delay(2000);
//  BTSerial.write('0');
//  delay(2000);
//}
