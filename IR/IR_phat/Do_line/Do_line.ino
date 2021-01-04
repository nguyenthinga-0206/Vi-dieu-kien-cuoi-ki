/*
 - Out nối Pin10
 */
#include<IRremote.h>
IRsend irsend;
#define LINE 10
int  val = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  val = digitalRead(LINE);
  if(val==0)
  {
    irsend.sendRC5(0,8);
  }
  else{
    irsend.sendRC5(1,8);
  }
  Serial.println(val);
  delay(1000);
}
