#include <dht.h>
#include <ESP8266WiFi.h>
dht DHT;
String apiKey = "MLJV0LFELG4WPGB7";
const char* ssid = "Kd kows";
const char* password = "kdkow143";
const char* server = "api.thingspeak.com";
#define DHT11_PIN D3 // what pin we're connected to
int t1;

//DHT dht(DHTPIN, DHT11,15);
WiFiClient client;
const int  VAL_PROBE= 0;//Analog pin 0

const int MOISTURE_LEVEL = 400; // the value after the LED goes on

void setup()
{
  //Serial.begin(9600);
  Serial.begin(115200);
  
  pinMode(D8, INPUT);
  pinMode(D2, INPUT);
  pinMode(D6, OUTPUT);
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
   int chk1= DHT.read11(DHT11_PIN);
  //Serial.print("Temperature = ");
  //Serial.println(DHT.temperature);
  //Serial.print("Humidity = ");
  //Serial.println(DHT.humidity);
  float t = DHT.temperature;
  float h = DHT.humidity;
  if (isnan(t) || isnan(h) || isnan(t1)) {
    Serial.println("Failed to read from DHT sensor 1!");
    return;
  }
  

  
  int moisture1 = analogRead(VAL_PROBE);
  Serial.print("Moisture1 = ");
  float M1 = moisture1;
  Serial.println(M1);
  int moisture2 = digitalRead(D8);
  Serial.print("Moisture2 = ");
  //float M2 = moisture2;
  Serial.println(moisture2);
  int moisture3 = digitalRead(D2);
  Serial.print("Moisture3 = ");
  //float M3 = moisture3;
  Serial.println(moisture3);

  if(moisture1 > MOISTURE_LEVEL)
  if(moisture2==HIGH)
   if(moisture3==HIGH)
  {
    //LedState(HIGH);
    digitalWrite(D6,HIGH);
    t1=1;
    }
  else 
  {
   // LedState(LOW);
    digitalWrite(D6,LOW);
    t1=0; 
  }
  else 
  {
   // LedState(LOW);
    digitalWrite(D6,LOW);
  }
  else 
  {
   // LedState(LOW);
    digitalWrite(D6,LOW);
  }
  
  delay(500);
  if (client.connect(server,80)) {  //   "184.106.153.149" or api.thingspeak.com
    String postStr = apiKey;
           postStr +="&field1=";
           postStr += String(t);
           postStr +="&field2=";
           postStr += String(h);
           postStr +="&field3=";
           postStr += String(t1);
           
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
      Serial.print("pump status"); 
     Serial.print(t1);
     Serial.print("Temperature: ");
    
     Serial.println("% send to Thingspeak");    
  }
  client.stop();
   
  Serial.println("Waiting...");    
  // thingspeak needs minimum 15 sec delay between updates
  delay(1000);
}

