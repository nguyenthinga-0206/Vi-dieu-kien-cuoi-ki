#include<IRremote.h>
/*
 - Chân giữa nối Pin2
 
 */
IRsend irsend;
const int pir =10;
int val = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(pir,INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  val = digitalRead(pir);
  if(val==0)
  { 
    irsend.sendRC5(0,8);
  }
  else{
    irsend.sendRC5(1,8);
  }
  Serial.println(val);
  delay(50);

}
