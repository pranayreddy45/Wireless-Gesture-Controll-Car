#include <SoftwareSerial.h>

SoftwareSerial BTSerial(10, 11); // RX | TX
String readdata;

void setup() 
{
  pinMode(13, OUTPUT);
  Serial.begin(9600);
  BTSerial.begin(38400);  // HC-05 default speed in AT command more


 pinMode(2,OUTPUT);//1-+
 pinMode(3,OUTPUT);//1-
 pinMode(4,OUTPUT);//2+
 pinMode(5,OUTPUT);//2-
 pinMode(5,OUTPUT);//3+
 pinMode(6,OUTPUT);//3-
 pinMode(7,OUTPUT);//4+
 pinMode(8,OUTPUT);//4-

}

void loop()
{
    while (BTSerial.available()) {
    delay(10);
    char c = BTSerial.read();
    readdata += c;
  }
  if (readdata.length() > 0) {

    if (readdata == "stop")
    {
      digitalWrite(13, LOW);
      Serial.println(readdata);

      
      digitalWrite(2,LOW);
      digitalWrite(3,LOW);
      digitalWrite(4,LOW);   
      digitalWrite(5,LOW);
      digitalWrite(6,LOW);
      digitalWrite(7,LOW);
      digitalWrite(8,LOW);
      digitalWrite(9,LOW);

      //delay(100);
      
    }
        else if (readdata == "forward")
    {
      digitalWrite (13, HIGH);
      Serial.println(readdata);

       digitalWrite(2,LOW);
       digitalWrite(3,HIGH);     //FORWARD
       digitalWrite(4,LOW);
       digitalWrite(5,HIGH);
       digitalWrite(6,LOW);
       digitalWrite(7,HIGH);
       digitalWrite(8,LOW);
       digitalWrite(9,HIGH);

      
      //delay (100);
    }

     else if (readdata == "backward")
    {
      digitalWrite (13, HIGH);
      Serial.println(readdata);

     digitalWrite(2,HIGH);
     digitalWrite(3,LOW);
     digitalWrite(4,HIGH);
     digitalWrite(5,LOW);        //BACKWARD
     digitalWrite(6,HIGH);
     digitalWrite(7,LOW);
     digitalWrite(8,HIGH);
     digitalWrite(9,LOW);
      
      //delay (100);
    }

     else if (readdata == "right")
    {
      digitalWrite (13, HIGH);
      Serial.println(readdata);

     
       digitalWrite(2,LOW);
       digitalWrite(3,HIGH);
       digitalWrite(4,LOW);    //RIGHT
       digitalWrite(5,LOW);
       digitalWrite(6,LOW);
       digitalWrite(7,HIGH);
       digitalWrite(8,LOW);
       digitalWrite(9,LOW); 
      
      //delay (100);
    }

    else if (readdata == "left")
    {
      digitalWrite (13, HIGH);
      Serial.println(readdata);


       digitalWrite(2,LOW);
       digitalWrite(3,LOW);
       digitalWrite(4,LOW);
       digitalWrite(5,HIGH);     //LEFT
       digitalWrite(6,LOW);
       digitalWrite(7,LOW);
       digitalWrite(8,LOW);
       digitalWrite(9,HIGH);
      
      //delay (100);
    }

    

    readdata = "";
  }
}
