#include "DHT.h"
#include <ESP8266WiFi.h>
// Pin    
#define DHTPIN 1

// Su dung cam bien DHT11 
#define DHTTYPE DHT11
// Thiet lap DHT
DHT dht(DHTPIN, DHTTYPE);
// Thong so WiFi nha ban
const char* TENWIFI = "kidkid";
const char* PASSWIFI = "htxoan123";
// Tao server
WiFiServer server(80);
void setup() {
    Serial.begin(115200);
  WiFi.begin(TENWIFI, PASSWIFI);
      // Kết nối WIFI với TÊN và MẬT KHẨU như trên
  Serial.print("\n Đang thử kết nối");
  while (WiFi.status() != WL_CONNECTED) {
    // làm cho đến khi thành công
    delay(500); Serial.print(".");
  }
  Serial.print("\n Kết nối thành công. IP address: ");
  Serial.println(WiFi.localIP());

  server.begin(); // Khởi động server.
  Serial.print("Server đã khởi động.");


}
void loop() {
  
  // Kiem tra khi co client ket noi
  WiFiClient client = server.available();
  if (!client) {
    return;
  }
  
  // Doi client gui ket noi
  Serial.println("Co mot client moi ket noi xem du lieu");
  while(!client.available()){
    delay(1);
  } 
  // Doc do am
  float h = dht.readHumidity();
  // Doc nhiet do o do C
  float t = dht.readTemperature();
  Serial.println(h);
  Serial.println(t);
  // Doc dong dau tien cua yeu cau gui len.
  String req = client.readStringUntil('\r');
  Serial.println(req);
  client.flush();
  // Chuan bi tao web de phan hoi
  String s = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n";
  s += "<head>";
  s += "<meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">";
  s += "<meta http-equiv=\"refresh\" content=\"60\" />";
  s += "<script src=\"https://code.jquery.com/jquery-2.1.3.min.js\"></script>"; 
  s += "<link rel=\"stylesheet\" href=\"https://maxcdn.bootstrapcdn.com/bootstrap/3.3.4/css/bootstrap.min.css\">";
  s += "<style>body{font-size: 24px;} .voffset {margin-top: 30px;}</style>";
  s += "</head>";
  
  s += "<div class=\"container\">";
  s += "<h1>Theo doi nhiet do va do am</h1>";
  s += "<div class=\"row voffset\">";
  s += "<div class=\"col-md-3\">Nhiet do: </div><div class=\"col-md-3\">" + String(t) + "</div>";
  s += "<div class=\"col-md-3\">Do am: </div><div class=\"col-md-3\">" + String(h) + "</div>";
  s += "</div>"; 
  // Gui phan hoi toi client (o day la giao dien web)
  client.print(s);
  delay(1);
  Serial.println("Client da thoat");

  // Sau khi nhan duoc thong tin thi se tu dong ngat ket noi 
}
