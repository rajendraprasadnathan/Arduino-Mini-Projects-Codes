const int trigPin = 3;

const int echoPin = 2;
int i=0;
void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600);
   pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  long duration, cm;
  pinMode(trigPin, OUTPUT);

  digitalWrite(trigPin, LOW);

  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);

  delayMicroseconds(10);

  digitalWrite(trigPin, LOW);

  pinMode(echoPin, INPUT);

  duration = pulseIn(echoPin, HIGH);


  cm = microsecondsToCentimeters(duration);
  Serial.print("cm");
  Serial.print(cm);
  Serial.print("\n");
  //delay(1000);
  if(cm<10)
  {
    i++;
    //Serial.print("i");
    Serial.print(i);
    //Serial.print("\n");
    //delay(1000);    
  }
  if(i==2||i==3||i==4||i==5||i==8||i==9)
  {
    forward();
    //delay(2000);
    //halt();
  }
  if(i==1||i==6||i==7||i==10||i==11)
  {
        back();
        //delay(2000);
        //halt();
        
  }
  if(i>10)
  i=1;
  
}
long microsecondsToCentimeters(long microseconds)

{ return microseconds / 29 / 2;

}
void forward()
{
  digitalWrite(8, 1); //forward
  digitalWrite(9, 1);
  digitalWrite(10,0);
  digitalWrite(11,0);
}
void back()
{
  digitalWrite(8, 0); //Reverse
  digitalWrite(9, 0);
  digitalWrite(10,1);
  digitalWrite(11,1);

}
//void halt()
//{
  //digitalWrite(8, 0); //halt
  //digitalWrite(9, 0);
  //digitalWrite(10,0);
  //digitalWrite(11,0);
//}

