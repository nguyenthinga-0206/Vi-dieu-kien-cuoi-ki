/*
 - Nút bấm :
      + 1 chân nối với chân số 7
      + 1 chân nối với chân (+)( nối tiếp  chân  5v)

  - Đèn hồng ngoại :
      + chân (+) nối  với điện trở ,điện trở nối với chân số 3
      + 1 chân nối với (-) ,nối với GND

 - Biên trở:
      + Chân  giữa nối với chân A0;
      + Chân có ôm nối với chân (+) nối với chân 5v
      + Chân còn lại của biến trở nối chân (-) nối với chân GND
*/
#include<IRremote.h>
IRsend irsend;
int btn=7;
int bientro = A0;
void setup() {
  // put your setup code here, to run once:
  pinMode(btn,INPUT);
  Serial.begin(9600);
}

void loop() {
   //put your main code here, to run repeatedly:
  bool flag = 1;
  int btn_val= digitalRead(btn);
  if(btn_val)
  {
    irsend.sendRC5(btn_val,8);
    flag = 0;
    
  }
  if (flag)
  {
    int bientro_val = analogRead(bientro);
    bientro_val = map(bientro_val,0,1023,0,255);
    irsend.sendRC5(bientro_val,10);
    
  }
  delay(50);

}
