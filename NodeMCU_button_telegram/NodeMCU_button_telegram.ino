// https://www.warriornux.com/kontrol-relay-nodemcu-esp8266-dengan-telegram/
// https://github.com/shurillu/CTBot
#include "CTBot.h"
CTBot myBot;


String ssid  = "ZIA HOTSPOT";   // Nama WiFi atau SSID kalian
String pass  = "bayar5000";  // Password Wifi
String token = "1387200421:AAGBKCy5dz4NNdyAmeHmfpMwqSHTiFXOLOU"; // Token Telegram kalian
const int id = 124315068;
const int tombol = D2;
const int led = D6;
int button = 0;

void setup() {
  // initialize the Serial
  Serial.begin(9600);
  pinMode(tombol, INPUT);
  pinMode(led, OUTPUT);
  Serial.println("Starting TelegramBot...");

  // connect the ESP8266 to the desired access point
  myBot.wifiConnect(ssid, pass);

  // set the telegram bot token
  myBot.setTelegramToken(token);

  // check if all things are ok
  if (myBot.testConnection()) {
    Serial.println("\ntestConnection OK");
  }
  else {
    Serial.println("\ntestConnection NOK");
  }

}

void loop() {
  // a variable to store telegram message data
  // TBMessage msg;
  button = digitalRead(tombol);
  if (button == HIGH) {
    Serial.println("Tombol ditekan");
    digitalWrite(led, HIGH);
    myBot.sendMessage(id, "Ada tamu nih Boss");
    delay(100);
  }
  else {
      digitalWrite(led, LOW);
  }
}

