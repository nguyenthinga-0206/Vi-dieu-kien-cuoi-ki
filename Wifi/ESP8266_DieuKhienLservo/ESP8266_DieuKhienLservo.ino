#include <ESP8266WiFi.h>
#include <Servo.h>

const char* ssid = "kid1234";
const char* password = "12341234";
Servo myservo;
int pos = 0;
//int LED = 4; // GPIO4 (D2)
WiFiServer server(80);

void setup(){
  Serial.begin(115200);
  myservo.attach(D1);
  Serial.print("Connecting to the Newtork");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("WiFi connected"); 
  server.begin();
  Serial.println("Server started");
  Serial.print("IP Address of network: "); // will IP address on Serial Monitor
  Serial.println(WiFi.localIP());
  Serial.print("Copy and paste the following URL: https://");
  Serial.print(WiFi.localIP());
  Serial.println("/");
}

void loop(){
  WiFiClient client = server.available();
  if (!client)
  {
    return;
    }
    
  Serial.println("Waiting for new client");
  while(!client.available())
  {
    delay(1);
  }
  String request = client.readStringUntil('\r');
  Serial.println(request);
  client.flush();
  
  int value = HIGH;
  if(request.indexOf("/CungChieu") != -1){
    for(pos = 0; pos < 180; pos += 1){ 

        myservo.write(pos);
        delay(15);
    }
    value = LOW;
  }

  if(request.indexOf("/NguocChieu") != -1){

    for(pos = 180; pos>=1; pos-=1) {                           
        myservo.write(pos);
        delay(15);
    } 
    value = HIGH;
  } 
  
//*------------------HTML Page Code---------------------*//

  client.println("HTTP/1.1 200 OK"); //
  client.println("Content-Type: text/html");
  client.println("");
  client.println("<!DOCTYPE HTML>");
  client.println("<html>");
  client.print(" CONTROL Servo: ");
  if(value == HIGH){
    client.print("OFF");
  }
  else
  {
    client.print("ON");
  }
  client.println("<br><br>");
  client.println("<a href=\"/CungChieu\"\"><button>CHAY</button></a>");
  client.println("<a href=\"/NguocChieu\"\"><button>DOI CHIEU</button></a><br />");
  client.println("</html>");
  
  delay(1);
  Serial.println("Client disonnected");
  Serial.println("");
}
