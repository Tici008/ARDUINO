#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>


const char* ssid = "Wokwi-GUEST";
const char* password = "";


String apiKey = "3d703eb11b65d1085d7d24ade936bdc8"; //
String url = "https://api.openweathermap.org/data/2.5/weather?lat=21.0285&lon=105.8542&appid=" + apiKey + "&units=metric";
void setup() {
  Serial.begin(115200);

  // Wifi
  WiFi.begin(ssid, password);
  Serial.print("ESP32 dang ket noi vao Wifi Wokwi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\n>>> KET NOI WIFI THANH CONG! <<<");
}

void loop() {

  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    http.begin(url);
    int httpResponseCode = http.GET();
    //----
    if (httpResponseCode == 200) {
      String dataJson = http.getString();
      Serial.println("\n-------------------------------------------");
      Serial.println("Da nhan tin hieu thoi tiet thot tu Server!");
      //------
      JsonDocument doc;
      error = deserializeJson(doc, dataJson);

      if (error) {
        Serial.print("Loi phan tich JSON: ");
        Serial.println(error.f_str());
        return;
      }

      float nhieDoHienTai = doc["main"]["temp"];
      int doAmHienTai = doc["main"]["humidity"];
      const char* moTaThoiTiet = doc["weather"][0]["description"];
      const char* tenThanhPho = doc["name"];
      //----
      Serial.print("Thanh pho: ");
      Serial.println(tenThanhPho);

      Serial.print("Nhiet do hien tai: ");
      Serial.print(nhieDoHienTai);
      Serial.println(" °C");

      Serial.print("Do am khong khi: ");
      Serial.print(doAmHienTai);
      Serial.println(" %");

      Serial.print("Trang thai bau troi: ");
      Serial.println(moTaThoiTiet);
      Serial.println("-------------------------------------------");

    } else {
      Serial.print("Loi call API. Ma loi: ");
      Serial.println(httpResponseCode);
    }

    http.end();
  } else {
    Serial.println("Mat ket noi Wifi, dang doi ket noi lai...");
  }

  delay(30000);
}
