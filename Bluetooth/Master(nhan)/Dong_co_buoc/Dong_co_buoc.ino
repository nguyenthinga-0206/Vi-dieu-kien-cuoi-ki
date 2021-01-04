#include <SoftwareSerial.h>
SoftwareSerial BTSerial(10, 11);

#include <Stepper.h>

int in1=4;
int  in2= 5;
int in3=6;
int  in4= 7;
 
Stepper stepper(500, in1, in2,in3, in4); 
void setup() {
  Serial.begin(9600);
  BTSerial.begin(9600);
  //pinMode(13, OUTPUT);
}

void loop() 
{
  if (BTSerial.available()) {
    char input=BTSerial.read();
    Serial.write(input);
    if (input == '1')
    {
      stepper.setSpeed(50); // 6 rpm
      stepper.step(500); // quay ngược chiều đồng hồ 
    }
    if (input == '0') 
   {
   //stepper.setSpeed(50); // 6 rpm
  //  stepper.step(-500); // quay ngược chiều đồng hồ
   }htuk  
  
  }
}
