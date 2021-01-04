/*
 - VRX nối A0
 - VRY nối A1
 - SW nối Pin2
 */
#include <SoftwareSerial.h>
SoftwareSerial BTSerial(10, 11);//TX/RX

int vrx=A0;
int vry= A1;
int  sw = 2;
void setup()
{
  BTSerial.begin(9600);
  Serial.begin(9600);
  pinMode(vrx, INPUT); 
  pinMode(vry, INPUT);
  pinMode(sw, INPUT_PULLUP); // neu chi la INPUT thi phai mac dien tro
}
void loop()
{
  int x = analogRead(vrx);
  int y = analogRead(vry);
  int KEY  = digitalRead(sw);
  if(KEY = 1)
  {
    if(x > 1000)
    {
      //digitalWrite(13,HIGH);
      BTSerial.write('1'); 
    }
    else
    {
      //digitalWrite(13,LOW);
      BTSerial.write('2'); 
    }
  }
  else
  {
    //digitalWrite(13,HIGH);
    BTSerial.write('0'); 
  }
   Serial.print("X=");
   Serial.println(x);
   Serial.print("Y=");
   Serial.println(y);
   Serial.print("KEY=");
   Serial.println(KEY);
   Serial.println();
 delay(1200);
}
