char val;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
  // put your setup code here, to run once:
pinMode(13,OUTPUT);
}

void loop() {
  digitalWrite(13,0);
//  // put your main code here, to run repeatedly: 
  if(Serial.available()>0)
{
  val = Serial.read();
  if(val=='s')
   digitalWrite(13,1);
   delay(1000);
}

}
