/*
 - Out(chân giữa) nối Pin10
 */
#include<IRremote.h>

#include "DHT.h"
#define  DHT11Pin 10
#define DHTType DHT11
IRsend irsend;
DHT HT(DHT11Pin,DHTType);
float humi;//độ ẩm
float tempC;
void setup(){
  Serial.begin(9600);
  HT.begin();
  delay(1000);
}
void loop(){
  delay(1000);
  humi= HT.readHumidity();
  tempC = HT.readTemperature();
  if(tempC<30)
  {
    irsend.sendRC5(0,8);
    
  }
  else {
    irsend.sendRC5(1,8);
  }
  Serial.print("Độ ẩm:");
  Serial.println(humi,1);
  Serial.print("Nhiệt độ :");
  Serial.println(tempC,1);
  
  
  
}
