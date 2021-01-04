/*
 - Động cơ DC:
    + 2 chân 12V(dây xanh) nối 5V
    + chân GND(dây tim) nối GND
    + 5V(dây đỏ) nối VIN
 - IR nhận:
    + Chân S nối Pin9
    + Chân giữa nối 5V
    + Chân âm(-) nối GND
 */
#include<IRremote.h>
int remotePin= 3; //IR nhan
int in3=6,in4 =7; // ứng với In3,In4
int  motor =5; 
int motor_speed =100; //tốc độ quay
bool state = 0;
IRrecv irrecv(remotePin);
decode_results results;

void setup() {
  // put your setup code here, to run once:
  irrecv.enableIRIn();
  pinMode(in3,OUTPUT);
  pinMode(in4,OUTPUT);
  pinMode(motor,OUTPUT);
}
void loop(){
  if(state){
    digitalWrite(in3,1);
    digitalWrite(in4,0);
  }  
  else{
    digitalWrite(in3,0);
    digitalWrite(in4,0);
  }
  analogWrite(motor, motor_speed);
  if(irrecv.decode(&results)){
    event();
    irrecv.resume();
  }
}
void event(){
  switch(results.value){
    case 0:
      state = 0;
      return;
    case 1:
      motor_speed = 255;
      break;
  }
  state = 1;
}
