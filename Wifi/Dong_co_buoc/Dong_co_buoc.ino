#include <ESP8266WiFi.h>
#include <Stepper.h>
const int stepsPerRevolution = 2048;

Stepper myStepper = Stepper(stepsPerRevolution, D0, D1, D2, D3); 

const char* ssid = "abc";
const char* password = "02062000";

WiFiServer server(80);

void setup(){
  Serial.begin(115200);
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
  if (!client){
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
    myStepper.setSpeed(10);
    myStepper.step(stepsPerRevolution);
    delay(1000);
    value = LOW;
  }

  if(request.indexOf("/NguocChieu") != -1){   
    myStepper.setSpeed(10);                       
    myStepper.step(-stepsPerRevolution);
    delay(1000);
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
  client.println("<a href=\"/CungChieu\"\"><button>nguoc</button></a>");
  client.println("<a href=\"/NguocChieu\"\"><button>cung</button></a><br />");
  client.println("</html>");
  delay(1);
  Serial.println("Client disonnected");
  Serial.println("");
}
