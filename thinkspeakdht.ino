#include <dht.h>
#include <ESP8266WiFi.h>
dht DHT;
String apiKey = "0HNRBVLZNOEB05Q5";
const char* ssid = "prasad";
const char* password = "12345678";
const char* server = "api.thingspeak.com";
#define DHT11_PIN D2 // what pin we're connected to
 
//DHT dht(DHTPIN, DHT11,15);
WiFiClient client;

void setup()
{
  //Serial.begin(9600);
  Serial.begin(115200);
  
  delay(10);
  //DHT.begin();
  
  WiFi.begin(ssid, password);
 
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
   
  WiFi.begin(ssid, password);
   
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  //pinMode(13, OUTPUT);
 
}

//void LedState(int state)
//{
//  digitalWrite(13,state);
//}

void loop()
{
   int chk = DHT.read11(DHT11_PIN);
  //Serial.print("Temperature = ");
  //Serial.println(DHT.temperature);
  //Serial.print("Humidity = ");
  //Serial.println(DHT.humidity);
  float h = DHT.temperature;
  float t = DHT.humidity;
  if (isnan(h) || isnan(t)) {
   //Serial.println("Failed to read from DHT sensor!");
    return;
  }

  
  
  
  if (client.connect(server,80)) {  //   "184.106.153.149" or api.thingspeak.com
    String postStr = apiKey;
           postStr +="&field1=";
           postStr += String(t);
           postStr +="&field2=";
           postStr += String(h);
         
           postStr += "\r\n\r\n";
 
     client.print("POST /update HTTP/1.1\n"); 
     client.print("Host: api.thingspeak.com\n"); 
     client.print("Connection: close\n"); 
     client.print("X-THINGSPEAKAPIKEY: "+apiKey+"\n"); 
     client.print("Content-Type: application/x-www-form-urlencoded\n"); 
     client.print("Content-Length: "); 
     client.print(postStr.length()); 
     client.print("\n\n"); 
     client.print(postStr);
           
 
     Serial.print("Temperature: ");
     Serial.print(t);
     Serial.print(" degrees Celcius Humidity: "); 
     Serial.print(h);
      Serial.print("Temperature: ");
     Serial.print(t);
     Serial.println("% send to Thingspeak");    
  }
  client.stop();
   
  Serial.println("Waiting...");    
  // thingspeak needs minimum 15 sec delay between updates
  delay(1000);
}

