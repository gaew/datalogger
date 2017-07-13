 
#include <Wire.h>  // Only needed for Arduino 1.6.5 and earlier
#include "SSD1306.h" // alias for `#include "SSD1306Wire.h"
#include <time.h>

float h,t;
int x=0;
const char* ssid     ="gaew";
const char* password ="asdfghjkl"; 

const char* host = "data.sparkfun.com";
const char* streamId   = "4Jj0rzrLvYH6Wlq2JzXn";
const char* privateKey = "b5xBKDKJlGfnRP2zkdoZ";


#include <DHT.h>
#include <ESP8266WiFi.h> 
#define DHTPIN D2     // what pin we're connected to
#define DHTTYPE DHT22   // DHT 11
SSD1306  display(0x3c, D3, D6);
// SH1106 display(0x3c, D3, D5);

// Initialize DHT sensor for normal 16mhz Arduino
DHT dht(DHTPIN, DHTTYPE);
const int sleepTimeS = 2;
void setup(){

  Serial.begin(115200);
  // Initialising the UI will init the display too.
  display.init();

  display.flipScreenVertically();
  display.setFont(ArialMT_Plain_16);
  display.setTextAlignment(TEXT_ALIGN_LEFT);
  dht.begin(); // initialize dht 

   WiFi.mode(WIFI_STA);                                        //เชื่อมต่อ Wifi
  WiFi.begin(ssid, password);
  Serial.println("\nConnecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
     Serial.print(",");
     delay(1000);
   }
   
} 

void displayTempHumid(){
  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  h = dht.readHumidity();
  // Read temperature as Celsius
  t = dht.readTemperature();
  // Read temperature as Fahrenheit
  float f = dht.readTemperature(true);


  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t) || isnan(f)){
    display.clear(); // clearing the display
    display.drawString(5,0, "Failed DHT");
    return;
  }
  display.clear();
  display.drawString(0, 0, "S/N : 8266"); 
  display.drawString(0, 16, "Humidity: " + String(h) + "%\t"); 
  display.drawString(0, 32, "Temp: " + String(t) + "C");
   if (WiFi.status() != WL_CONNECTED){
     display.drawString(0, 47, "disconnect"); 
  }else{
    display.drawString(0, 47, "connected"); 
  } 
  
}

  void displayClear(){    
     display.clear();     
  }

   void displayConnecting(){    
     display.clear();    
     display.drawString(0, 47, "connecting...");  
  }

  void displayStatus(){    
     display.clear();
     if (WiFi.status() != WL_CONNECTED){
     display.drawString(0, 47, "disconnect"); 
  }else{
    display.drawString(0, 47, "connected"); 
  } 
  }

  void sentWifi(){
    WiFiClient client;
   const int httpPort = 80;
    if (!client.connect(host, httpPort)) {
    Serial.println("connection failed");
    return;
    }
  String url = "/input/";
  url += streamId;
  url += "?private_key=";
  url += privateKey;
  url += "&humidity=";
  url += h;
  url += "&temp=";
  url += t;
  url += "&sn=01";
   
  Serial.print("Requesting URL: ");
  Serial.println(url);
   
  // This will send the request to the server
  client.print(String("GET ") + url + " HTTP/1.1\r\n" +
               "Host: " + host + "\r\n" + 
               "Connection: close\r\n\r\n");
  delay(3000);
  }
  
void loop(){ 
  
       displayTempHumid();  
       display.display();
       delay(3000);
     
   sentWifi();

   delay(40000);
        
  }
   
 



