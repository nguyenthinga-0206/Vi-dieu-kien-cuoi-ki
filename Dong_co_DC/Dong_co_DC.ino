int enA =5;
int in3=8;
int in4=9 ;
void setup(){
  pinMode(enA,OUTPUT);
  pinMode(in3,OUTPUT);
  pinMode(in4,OUTPUT);
  
}
void loop(){
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
  analogWrite(enA,125);
  delay(5000);
  
}
