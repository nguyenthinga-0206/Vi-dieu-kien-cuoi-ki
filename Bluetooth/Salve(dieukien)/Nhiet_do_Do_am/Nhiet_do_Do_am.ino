#include <SoftwareSerial.h>
#include "DHT.h"
SoftwareSerial BTSerial(10, 11);//TX/RX

int DHTType = DHT11;
int dht= 6;
DHT HT(dht, DHTType);

float humi;
float tempC;
void setup()
{
  BTSerial.begin(9600);
  Serial.begin(9600);
  HT.begin();
}
void loop()
{
  humi= HT.readHumidity();
  tempC = HT.readTemperature();
  Serial.print("Độ ẩm:");
  Serial.println(humi,1);
  Serial.print("Nhiệt độ :");
  Serial.println(tempC,1);
  if(tempC < 30)
  {
    //digitalWrite(13,HIGH);
    BTSerial.write('1'); 
  }
  else{
    //digitalWrite(13,LOW);
    BTSerial.write('0'); 
  }
 delay(1200);
}
