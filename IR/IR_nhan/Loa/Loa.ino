/*
- modun IR nhận:
    + Chân âm nối với GND
    + Chân giữa nối 5V
    + Chân đầu S nối với Pin9
 */
#include <IRremote.h>
int remote_pin = 9;
IRrecv irrecv(remote_pin);
decode_results results;
int coi = 8;
void setup(){
  irrecv.enableIRIn();
  pinMode(coi, OUTPUT);
}
void loop() {
  // put your main code here, to run repeatedly:
  if(irrecv.decode(&results))
  {
    char value = results.value;
    if(value== '0'){
      noTone(coi);
    }
    else{
      tone(coi,2000);
    }
    irrecv.resume();
  }
}
