// https://github.com/shurillu/CTBot

#include "CTBot.h"
CTBot myBot;

String ssid  = "Note 7";   // Nama WiFi atau SSID kalian
String pass  = "bayar5000";  // Password Wifi
String token = "1387200421:AAGBKCy5dz4NNdyAmeHmfpMwqSHTiFXOLOU"; // Token Telegram kalian

const int lampu = D6;

void setup() {
  // initialize the Serial
  Serial.begin(115200);
  Serial.println("Starting TelegramBot...");

  // connect the ESP8266 to the desired access point
  myBot.wifiConnect(ssid, pass);

  // set the telegram bot token
  myBot.setTelegramToken(token);

  // check if all things are ok
  if (myBot.testConnection())
    Serial.println("\ntestConnection OK");
  else
    Serial.println("\ntestConnection NOK");

  // set the pin connected to the LED to act as output pin
  pinMode(lampu, OUTPUT);
  digitalWrite(lampu, LOW); // turn off the led (inverted logic!)

}

void loop() {

  // a variable to store telegram message data
  TBMessage msg;

  // if there is an incoming message...
  if (myBot.getNewMessage(msg)) {

    if (msg.text.equalsIgnoreCase("/start")) {
      myBot.sendMessage(msg.sender.id, "Selamat datang di bot controller lampu \n \n Ketik On untuk menyalakan lampu \n Ketik Off untuk mematikan lampu ");
    }
    if (msg.text.equalsIgnoreCase("On")) {                   //Perintah dari telegram ke perangkat
      digitalWrite(lampu, HIGH);                              //Lampu dihidupkan
      myBot.sendMessage(msg.sender.id, "The Led is now ON"); //Balasan dari perangkat ke Bot Telegram
    }
    else if (msg.text.equalsIgnoreCase("Off")) {              //Perintah dari telegram ke perangkat
      digitalWrite(lampu, LOW);                              //Lampu dimatikan
      myBot.sendMessage(msg.sender.id, "The Led is now OFF"); //Balasan dari perangkat ke Bot Telegram
    }
  }

}

