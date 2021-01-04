/*
- Động cơ DC:
    + 2 chân 12V(dây xanh) nối 5V
    + chân GND(dây tim) nối GND
    + 5V(dây đỏ) nối VIN
- Đèn nối bt:
    + Chân ngắn nối GND
    + Chân dài nối điện trở với Pin[4,5,6,7]
- modun IR nhận:
    + Chân âm nối với GND
    + Chân giữa nối 5V
    + Chân đầu S nối với Pin3
 */
#include <IRremote.h>
int remote_pin = 3;
IRrecv irrecv(remote_pin);
decode_results results;
//int led[] = {4, 5, 6, 7};
//int n = sizeof(led) / sizeof(led[0]);
//bool on = 1;
//int current_led = 0, incr = 1, delay_time = 255;
int in3=9,in4 =10; // ứng với In3,In4
int  motor =11;
int value = 255; 
void setup(){
  irrecv.enableIRIn();
  pinMode(in3,OUTPUT);
  pinMode(in4,OUTPUT);
  pinMode(motor,OUTPUT);
//  for(int i = 0; i <n; i++)
//    pinMode(led[i], OUTPUT);  
}
void loop() {
  // put your main code here, to run repeatedly:
//  digitalWrite(in3,HIGH);
//  digitalWrite(in4,LOW);
//  analogWrite(motor, tocdo);
  if(irrecv.decode(&results))
  {
    int value = results.value;
    digitalWrite(in3,HIGH);
    digitalWrite(in4,LOW);
    analogWrite(motor, value);
//    if(value==1)
//    {
//      incr = 0-incr;
//    }
//    else{
//      delay_time = value;
//    }
    irrecv.resume();
  }
//  current_led= (current_led + n) % n;
//  digitalWrite(led[current_led],1);
//  delay(delay_time);
//  digitalWrite(led[current_led],0);
//  current_led += incr;
}
