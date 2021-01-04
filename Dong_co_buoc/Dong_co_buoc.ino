#include<Stepper.h>
const int in1=4;
const int in2=5;
const int in3=6;
const int in4=7;
Stepper  motor(512, in1, in2, in3, in4);
void setup(){
  
}
void loop(){
  motor.setSpeed(6);
  motor.step(512);
}
