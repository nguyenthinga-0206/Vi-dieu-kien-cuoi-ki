/*
 - Biến trở:
    + Giữa nối A0;
    + Ôm nối 5V
    + Còn lại nối GND
 */
#include <SoftwareSerial.h>
SoftwareSerial BTSerial(10, 11);//TX/RX
int tro = A0;
void setup()
{
  BTSerial.begin(9600);
  Serial.begin(9600);
}
void loop()
{
  int tro_val = analogRead(tro);
  int value = map(tro_val, 0, 1023, 0, 180);
  Serial.println(value);
  BTSerial.write(value); 
  delay(10);
  
}
