#define BLYNK_PRINT Serial


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "76efa95e55b546c48d2be33ffd8cc0cf";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "prasad";
char pass[] = "12345678";

void setup()
{
  // Debug console
  Serial.begin(115200);

  Blynk.begin(auth, ssid, pass);
  pinMode(D3,OUTPUT);
  pinMode(D6,OUTPUT);
  pinMode(D7,OUTPUT);
  pinMode(D8,OUTPUT);
  pinMode(D1,OUTPUT);
  // You can also specify server:
  //Blynk.begin(auth, ssid, pass, "blynk-cloud.com", 80);
  //Blynk.begin(auth, ssid, pass, IPAddress(192,168,1,100), 8080);
}

void loop()
{
  Blynk.run();
  int y=digitalRead(D1);
  if(y==1){
    Serial.println("Metal Detected");
  }
  else {
    Serial.println("Meta Not detected");
  }
}
BLYNK_WRITE(V1){ 
int x = param[0].asInt(); 
int y = param[1].asInt();  
if(x==1){
digitalWrite(D3,HIGH);
digitalWrite(D6,LOW);
digitalWrite(D7,HIGH);
digitalWrite(D8,LOW);
Serial.println("forward");
}
else if(x==-1){
digitalWrite(D3,LOW);
digitalWrite(D6,HIGH);
digitalWrite(D7,LOW);
digitalWrite(D8,HIGH);
Serial.println("reverse");
  }
  else if(x==2)
  {
digitalWrite(D3,LOW);
digitalWrite(D6,LOW);
digitalWrite(D7,HIGH);
digitalWrite(D8,LOW);
Serial.println("right");
delay(5000);
digitalWrite(D3,HIGH);
digitalWrite(D6,LOW);
digitalWrite(D7,HIGH);
digitalWrite(D8,LOW);
  }
  else if(x==-2)
  {
digitalWrite(D3,HIGH);
digitalWrite(D6,LOW);
digitalWrite(D7,LOW);
digitalWrite(D8,LOW);
Serial.println("left");
delay(5000);
digitalWrite(D3,HIGH);
digitalWrite(D6,LOW);
digitalWrite(D7,HIGH);
digitalWrite(D8,LOW);
}
else if(x==0){
  digitalWrite(D3,LOW);
digitalWrite(D6,LOW);
digitalWrite(D7,LOW);
digitalWrite(D8,LOW);

Serial.println("stop");
}
}
