/*
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
int led[] = {4, 5,6, 7};
int n = sizeof(led) / sizeof(led[0]);
bool on = 1;
int current_led = 0, incr = 1, delay_time = 500;
void setup(){
  irrecv.enableIRIn();
  for(int i = 0; i <n; i++)
    pinMode(led[i], OUTPUT);
    
}
void loop() {
  // put your main code here, to run repeatedly:
  if(irrecv.decode(&results))
  {
    int value = results.value;
    if(value==1)
      incr = 0-incr;
    else
      delay_time = value;
    irrecv.resume();
  }
  current_led= (current_led + n) % n;
  digitalWrite(led[current_led],1);
  delay(delay_time);
  digitalWrite(led[current_led],0);
  current_led += incr;
}
