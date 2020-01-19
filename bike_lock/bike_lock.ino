#include<SoftwareSerial.h>

int speedL, speedR;
char fg;
SoftwareSerial mySerial(10,11);//RX, TX


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.flush();
  mySerial.begin(38400);
  mySerial.flush();

  speedL = 420;          // for testing
  speedR = 69;
  fg='d';
}

void loop()
{
  if(Serial.available()){
    //mySerial.print(Serial.read());
    auto a = Serial.read();
    if(a != 13 && a!= 10){
      mySerial.print((char)a);
      Serial.println((char)a);
    }
  }

  if(mySerial.available()){
    char lock = mySerial.read();
    char sound = mySerial.read();
    if(lock == '1'){
      Serial.println("Locked!");
    } else{
      Serial.println("Unlocked!");
    }
    Serial.println((int)lock);
    if(sound == '1'){
      Serial.println("Sounding!");
      
    }
    Serial.println((int)sound);     
  }
  //delay(100);
 /*mySerial.print(fg);            //send the two speeds
 mySerial.print(",");
 mySerial.print(speedR);
 mySerial.print('\n');
 
 Serial.print(fg);            //just for debugging
 Serial.print(",");
 Serial.print(speedR);
 Serial.print('\n');
 
 delay(100);*/
 
}
