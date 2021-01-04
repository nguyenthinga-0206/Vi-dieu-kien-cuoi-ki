String httpHeader = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n";
String html = R"=====(  
<!DOCTYPE html>
<html>
 <head>
 <meta name='viewport' content='width=device-width, initial-scale=1.0'/>
 <meta charset='utf-8'>
 <style>
   h2, h3, p, form {text-align: center; }
   td { text-align: right; padding: 3px; }
   th { text-align: center; padding: 5px; }
 </style>
   <title>Viết ra chân Arduino thông qua NodeMCU</title>
   <script>
      function SendGetRequest() {
        var pin = document.forms['writePinForm'].pinName.value;
        var val = document.forms['writePinForm'].pinValue.value;
        window.location.href = window.location.origin + '/' + pin + '/' + val + '/';
      }
   </script>
 </head>
 <body>
     <form name='writePinForm'>
        <table width="30%" height="40%" cellpadding style="border: 1px solid black; margin: auto; text-align: center;">
          <tr> <th colspan='3'> Viết ra chân Arduino thông qua NodeMCU </th> </tr>
          <tr>
            <td> <label for='pinName'>Chân</label> </td>
            <td colspan='2'> <input type='text' id='pinName' name='pinName' value='D13'> </td>
          <tr>
            <td> <label for='pinValue'>Giá trị</label> </td>
            <td colspan='2'> <input type='text' id='pinValue' name='pinValue' value='1'> </td>
          </tr>
          
          <tr><td colspan='3' style='text-align: center;'>
              <input type='button' onclick='SendGetRequest()' value='Viết ra Arduino'>
          </td></tr>
          <tr><td colspan='3' style='text-align: center;'>
              Nhập ở ô Chân là tên của chân Arduino (D11, D5,... chân A không output được).
              Nhập ở ô value là một giá trị số nguyên, đừng nhập HIGH, LOW. Nếu giá trị là 0, 1 thì hàm digitalWrite
              sẽ được sử dụng, ngược lại hàm analogWrite sẽ được sử dụng.
           </td></tr>
        </table>
     </form>
 </body>
</html>
)=====";

#include <ESP8266WiFi.h>
#define TENWIFI "Van Tho 15"
#define PASSWIFI "vannhucu15"
WiFiServer server(80);
// --
#include <SoftwareSerial.h>
SoftwareSerial ss (D1, D2);

void setup(){
  Serial.begin(115200);
  WiFi.begin(TENWIFI, PASSWIFI);

  Serial.print("\n Đang thử kết nối");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500); Serial.print(".");
  }
  Serial.print("\n Kết nối thành công. IP address: ");
  Serial.println(WiFi.localIP());

  server.begin(); // Khởi động server.
  Serial.print("Server đã khởi động.");
  // --
  ss.begin(9600);
}

void loop() {
    // Kiểm tra nếu có client, 
    WiFiClient client = server.available();
    // client == 0 khi không có người truy cập
    if (!client)  { return; }
  
    String request = "";
    while (client.connected()) {
      if (client.available())
        request += (char) client.read(); // ép kiểu byte sang char
      if (request.endsWith("\r\n\r\n")) // header được quy định là kết thúc 
        break;            // bằng hai dòng trống, ta dùng điều này để break
    }
    Serial.println(request);
    int idx1 = request.indexOf("GET") + 4;
    int idx2 = request.indexOf(' ', idx1);
    if (idx1 + 1 < idx2) {
      String towrite = request.substring(idx1+1, idx2-1);
      String pin = towrite.substring(0, towrite.indexOf('/'));
      String val = towrite.substring(towrite.indexOf('/')+1);
      String sending = pin + " " + val + "\r\n";
      Serial.println("Writing to SSerial..: " + sending);
      ss.write(sending.c_str());
    }
    String htmlPage = html;
    client.print(httpHeader); // viết HTTP Header ra trình duyệt trước
    client.print(htmlPage);   // viết code HTML ra trình duyệt
    delay(5); // chờ một chút để trình duyệt xử lý
}
