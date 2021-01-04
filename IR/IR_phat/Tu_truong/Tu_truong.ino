 /*
  - A0 nối với A0
  - D0 nối  với Pin2
  */
 
 #include<IRremote.h>
 IRsend irsend;
int pushButton =2;
void setup(){
  Serial.begin(9600);
  pinMode(pushButton, INPUT);
  
}
void  loop(){
  int buttonState = digitalRead(pushButton);
  
  if(buttonState==1)//ko có nam chaam ->ko xoay
  {
    irsend.sendRC5(0,8);
  }
  else{ //có nam châm ->xoay
    irsend.sendRC5(1,8);
  }
  
  Serial.println(buttonState);
  delay(2000);
}
