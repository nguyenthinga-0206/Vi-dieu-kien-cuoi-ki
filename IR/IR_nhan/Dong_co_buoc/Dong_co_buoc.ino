/*
 - Động cơ bước: 
    + in1,2,3,4 lần lượt mắc Pin8,9,10,11
    + Âm nối GND
    + Dương nối 5V
 */
#include <IRremote.h>
#include<Stepper.h>

int remote_pin = 3;
IRrecv irrecv(remote_pin);
decode_results results;
int in1=8;
int in2=9;
int in3=10;
int in4=11;
Stepper  motor(2038, in1, in2, in3, in4);
void setup() {
  // put your setup code here, to run once:
  irrecv.enableIRIn();
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(irrecv.decode(&results))
  {
    if(results.value == 1)
    {
       motor.setSpeed(6);
       motor.step(2038);
    }
    else{      
    }
    irrecv.resume(); 
  }  
}
