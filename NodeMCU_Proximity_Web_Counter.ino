#include <ESP8266HTTPClient.h>
#include <ESP8266WiFi.h>




//settingan SSID
//const char* ssid = "ZIA HOTSPOT";
//const char* password = "bayar5000";
//const char* host = "192.168.43.57"; //alamat IP Server

const char* ssid = "DMD Guest";
const char* password = "DMD12345";
const char* host = "192.168.88.10"; //alamat IP Server

int ir_pin = D0;
int counter = 0;
int hitObject = false;

void setup() {
  Serial.begin(115200);
  pinMode(ir_pin, INPUT);

  // setting koneksi wifi
  WiFi.hostname("nodeMCU");
  WiFi.begin(ssid, password);

  // cek koneksi wifi
  while (WiFi.status() != WL_CONNECTED)
  {
    //nodeMCU terus mencari koneksi
    Serial.print(".");
    delay(500);
  }
  //tampilkan pesan di serial connected
  Serial.println("WiFi Connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

}

void loop() {
  int sensor = digitalRead(ir_pin);

  if ( (sensor == 1) && (hitObject == false) ) {
    counter++;
    hitObject = true;
    Serial.print("Status saat ini \n");
    Serial.print("Counter = ");
    Serial.println( counter);
  }
  else if ( (sensor == 0) && (hitObject == true) ) {
    hitObject = false;
  }

  WiFiClient client;
  if (!client.connect(host, 80))
  {
    Serial.println("Connection Failed");
    return;

  }
  //proses pengirimin data ke server
  String Link;
  HTTPClient http;
//  Link = "http://192.168.88.10/websensor/kirimdata.php?sensor=" + String(counter);
  Link = "http://192.168.88.10/webcounter/public/sensor/nilaisensor?sensor=" + String(counter);


  //eksekusi Link

  http.begin(client, Link);

  //mode GET
  http.GET();
  http.end();
  delay(1000);
}
