/*
 - Động cơ DC:
    + 2 chân 12V(dây xanh) nối 5V
    + chân GND(dây tim) nối GND
    + 5V(dây đỏ) nối VIN
 - IR nhận:
    + Chân S nối Pin3
    + Chân giữa nối 5V
    + Chân âm(-) nối GND
 - Còi:
    + Chân ngắn nối GND
    + Chân dài nối Pin2
 - Đèn:
    + Chân ngắn nối với GND
    + Chân dài lần lượt nối Pin8,9,10
 */
#include<IRremote.h>
int remotePin= 3; //IR nhan
int in3=6,in4 =7; // ứng với In3,In4
int  motor =5; 
int motor_speed; //tốc độ quay
IRrecv irrecv(remotePin);
decode_results results;

int loa = 2;
int tro = A0;
int i;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  irrecv.enableIRIn();
  pinMode(in3,OUTPUT);
  pinMode(in4,OUTPUT);
  pinMode(motor,OUTPUT);
  pinMode(loa,OUTPUT);
  for(i = 8; i <= 10; i++)
    pinMode(i, OUTPUT);
}
void loop(){
  motor_speed = map(analogRead(tro), 0, 1023, 0, 255);
  //Serial.println(motor_speed);
  if(irrecv.decode(&results))
  {
    int input = results.value;
    if(input == 1){
      digitalWrite(8,HIGH);
      digitalWrite(9,HIGH);
      delay(100);
      digitalWrite(8,LOW);
      digitalWrite(9,LOW);
      delay(100);
      if(input == 2){
        digitalWrite(in3,0);
        digitalWrite(in4,1);
      }
      else{
        digitalWrite(in3,1);
        digitalWrite(in4,0);
      }
      analogWrite(motor, motor_speed);
      if(input == 3){
        digitalWrite(10,HIGH);
      }
      if(input == 4){
      digitalWrite(10,HIGH);
      tone(loa,2000);
      digitalWrite(in3,0);
      digitalWrite(in4,0);
      }   
    }
    irrecv.resume();
  }
}
