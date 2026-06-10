#define BLYNK_TEMPLATE_ID "TMPL6ghf_6g7E"
#define BLYNK_TEMPLATE_NAME "Temperature"
#define BLYNK_AUTH_TOKEN "l4Vkmp-U1_YsObj3fR8C_SJ5emGTRvNo"
#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>
#include <BlynkSimpleEsp32.h>
#include <ESP32Servo.h>


const char* ssid = "Wokwi-GUEST";
const char* password = "";


String apiKey = "3d703eb11b65d1085d7d24ade936bdc8"; //
String url = "https://api.openweathermap.org/data/2.5/weather?lat=21.0285&lon=105.8542&appid=" + apiKey + "&units=metric";
//----
BlynkTimer timer;
Servo myServo;
const int servoPin = 18;


BLYNK_WRITE(V2) {
  int gocQuay = param.asInt();
  Serial.print("Blynk gui lenh");
  Serial.println(gocQuay);
  myServo.write(gocQuay);
}
void setup() {
  Serial.begin(115200);
  myServo.attach(servoPin);
  // Tiến hành kết nối Wifi
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, password);
  Serial.println("\n>>> KET NOI BLYNK THANH CONG! <<<");

  fetchWeather();
  timer.setInterval(30000L, fetchWeather);
}

void loop() {
  Blynk.run();
  timer.run();
  //----


}

void fetchWeather() {
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    http.begin(url);
    int httpResponseCode = http.GET();
    //----
    if (httpResponseCode == 200) {
      String dataJson = http.getString();
      Serial.println("Da nhan tin hieu thoi tiet thot tu Server!");
      //------
      JsonDocument doc;
      DeserializationError error = deserializeJson(doc, dataJson);

      if (error) {
        Serial.print("Loi phan tich JSON: ");
        Serial.println(error.f_str());
        return;
      }


      float nhietDoHienTai = doc["main"]["temp"];
      int doAmHienTai = doc["main"]["humidity"];
      const char* moTaThoiTiet = doc["weather"][0]["description"];
      const char* tenThanhPho = doc["name"];


      // --- BƯỚC 5: IN KẾT QUẢ ĐÃ LỌC LÊN SERIAL MONITOR ---
      Serial.print("Thanh pho: ");
      Serial.println(tenThanhPho);

      Serial.print("Nhiet do hien tai: ");
      Serial.print(nhietDoHienTai);
      Serial.println(" °C");

      Serial.print("Do am khong khi: ");
      Serial.print(doAmHienTai);
      Serial.println(" %");

      Serial.print("Trang thai bau troi: ");
      Serial.println(moTaThoiTiet);
      Serial.println("-------------------------------------------");


      //Lên Blynk Cloud
      Blynk.virtualWrite(V0, nhietDoHienTai);
      Blynk.virtualWrite(V1, doAmHienTai);
    } else {
      Serial.print("Loi call API. Ma loi: ");
      Serial.println(httpResponseCode);
    }

    http.end();
  } else {
    Serial.println("Mat ket noi Wifi, dang doi ket noi lai...");
  }
}
