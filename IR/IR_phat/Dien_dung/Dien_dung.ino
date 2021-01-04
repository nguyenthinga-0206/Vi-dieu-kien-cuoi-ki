#include<IRremote.h>
IRsend irsend;
//int led = 8;
int ttp = 7;
void setup()
{
  //pinMode(led, OUTPUT); A  
  pinMode(ttp, INPUT);
  Serial.begin(9600);
}
void loop()
{
 if(digitalRead(ttp)== LOW)
  {
    irsend.sendRC5(0,8);
  //digitalWrite(led,HIGH);
  }  
  else
  {
    irsend.sendRC5(1,8);
  //digitalWrite(led, LOW); 
  }
  Serial.println(digitalRead(ttp));
}
