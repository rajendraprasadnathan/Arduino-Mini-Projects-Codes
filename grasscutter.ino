char junk;
String inputString="";
int lm=6;//pin 9 of arduino to pin 7 of l293d
int lmr=7;//pin 8 of arduino to pin 2 of l293d 
int rm=5;//pin 10 of arduino to pin 10 of l293d
int rmr=4;//pin 11 of arduino to pin 15 of l293d
int gr=8;
int g=9;

void setup()                    
{
  pinMode(lm,OUTPUT);
  pinMode(lmr,OUTPUT);
  pinMode(rm,OUTPUT);
  pinMode(rmr,OUTPUT);
 Serial.begin(9600);            
 pinMode(13, OUTPUT);
}

void loop()
{
  if(Serial.available()){
  while(Serial.available())
    {
      char inChar = (char)Serial.read();
      inputString += inChar;        
    }
    Serial.println(inputString);
    while (Serial.available() > 0)  
    { junk = Serial.read() ; }      
    if(inputString == "a"){         
      digitalWrite(lm,LOW);
      digitalWrite(lmr,HIGH);
      digitalWrite(rm,HIGH);
      digitalWrite(rmr,LOW);

    }if(inputString == "b"){   
      digitalWrite(lm,HIGH);
      digitalWrite(lmr,LOW);
      digitalWrite(rm,LOW);
      digitalWrite(rmr,HIGH);
    }
if(inputString == "c"){   
      digitalWrite(lm,HIGH);
      digitalWrite(lmr,HIGH);
      digitalWrite(rm,HIGH);
      digitalWrite(rmr,LOW);
    }
if(inputString == "d"){   
      digitalWrite(lm,LOW);
      digitalWrite(lmr,HIGH);
      digitalWrite(rm,HIGH);
      digitalWrite(rmr,HIGH);
    }
if(inputString == "e"){   
       digitalWrite(lm,HIGH);
      digitalWrite(lmr,HIGH);
      digitalWrite(rm,HIGH);
      digitalWrite(rmr,HIGH);
    }
if(inputString == "f"){   
       digitalWrite(gr,HIGH);
      digitalWrite(g,LOW);
    }
    if(inputString == "g"){   
       digitalWrite(gr,HIGH);
      digitalWrite(g,HIGH);
    }
    inputString = "";
  }
}
