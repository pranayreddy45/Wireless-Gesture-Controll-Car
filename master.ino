#include <SoftwareSerial.h>
SoftwareSerial BTSerial(10, 11); // RX | TX
 
 int xpin = A3;                  // x-axis of the accelerometer
 int ypin = A2;                  // y-axis
 int zpin = A1;                  // z-axis (only on 3-axis models)


 int xval;
 int yval;
 int zval;

void setup() {
  Serial.begin(9600);
  BTSerial.begin(38400);
}

void loop() {

  
  Serial.print(analogRead(xpin));
  Serial.print("\t");
  Serial.print(analogRead(ypin));
  Serial.print("\t");
  Serial.print(analogRead(zpin));
  Serial.println();
 


  xval=analogRead(xpin);
  yval=analogRead(ypin);
  zval=analogRead(zpin);
 

  if( ((xval>=300 && xval<=350)) && ((yval>=305) && (yval<=335))&&((zval>=385)&&(zval<=415))) //stationary or stop(transmitter parallel to ground)
  {
    Serial.println("stop");
     BTSerial.write("stop");
    digitalWrite(13,LOW);
  } 
 
  
  else if ((xval>=310 && xval<=340) && (yval>=255 && yval<=285)&&(zval>=350&&zval<=385)) //forward(transmitter tilted forward)
    {
      Serial.println("forward");
       BTSerial.write("forward");
      digitalWrite(13,HIGH);
     }
    
    
   else if ((xval>=310 && xval<=340) && (yval>=370 && yval<=400)&&(zval>=355&&zval<=385)) //backward(transmitter tilted backward)
    {
      Serial.println("backward");
       BTSerial.write("backward");
      digitalWrite(13,HIGH);
   }
   
    
    else if ((xval>=375 && xval<=405) && (yval>=315 && yval<=355)&&(zval>=350&&zval<=380)) //left(transmitter tilted to left)
    {
      Serial.println("left");
       BTSerial.write("left");
      digitalWrite(13,HIGH);
     }
     
     
     else if ((xval>=250 && xval<=280) && (yval>=330 && yval<=350)&&(zval>=340&&zval<=390))//right(transmitter tilted to right)
    {
      Serial.println("right");
       BTSerial.write("right");
      digitalWrite(13,HIGH);
       }
  
  delay(100);
  
  
}
