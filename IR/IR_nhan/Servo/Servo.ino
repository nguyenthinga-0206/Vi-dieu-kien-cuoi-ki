/*
 - Servo: 
    + Dây cam nối Pin9
    + Dây đỏ nối 5V
    + Dây nâu nối GND
 */
#include <IRremote.h>
#include<Servo.h>
Servo myservo;
int pos =0;
int remote_pin = 3;
bool state = 0;
IRrecv irrecv(remote_pin);
decode_results results;
void setup() {
  // put your setup code here, to run once:
  irrecv.enableIRIn();
  //Serial.begin(9600);
  myservo.attach(9);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(irrecv.decode(&results))
  {
    //event();

    if(results.value == 1)
    {
       for(pos=0;pos<=180;pos+=2)
      {
        myservo.write(pos);
        delay(15);
        
      }
//      for(pos=179;pos>=1;pos-=1)
//      {
//        myservo.write(pos);
//        delay(5);
//      } 
    }
    else{      
    }
    irrecv.resume(); 
  }  
}
