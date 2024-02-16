#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

#define MQ2pin A0
 
#define FIREBASE_HOST "led1-5d8b2-default-rtdb.firebaseio.com" // Firebase host
#define FIREBASE_AUTH "rGQdsE6SKdfrTH1y20WGf2bzXTQJsNHiT2nUYOlU" //Firebase Auth code
#define WIFI_SSID "HUAWEI nova 7i" //Enter your wifi Name
#define WIFI_PASSWORD "A78hgf4B" // Enter your password


void setup() {
  pinMode(MQ2pin, INPUT);
  Serial.begin(9600);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.println("Connected.");
  Serial.println(WiFi.localIP());
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
}

void loop() {
  float value = analogRead(MQ2pin);
  Serial.println(value);
  Firebase.setFloat("MQ2_value", value);
  delay(1000);
}
