/*
 - VRX nối A0
 - VRY nối A1
 - SW nối Pin2
 */
#include<IRremote.h>
IRsend irsend;
int bientroX=A0;
int bientroY= A1;
int  button = 2;

void setup() {
  // put your setup code here, to run once:
pinMode(button,INPUT);
//pinMode(A0,INPUT);
//pinMode(A1,INPUT);
Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
   int x =analogRead(bientroX);
   int y = analogRead(bientroY);
   int KEY  =digitalRead(button);
   if(y<1000&&x<1000){
    irsend.sendRC5(1,8);
   }
   else{
    irsend.sendRC5(0,8);
   }
   
   Serial.print("X=");
   Serial.println(x);
   Serial.print("Y=");
   Serial.println(y);
   Serial.print("KEY=");
   Serial.println(KEY);
   Serial.println();
   delay(2000);
   
}
