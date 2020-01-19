#include <SoftwareSerial.h>

SoftwareSerial BTSerial(10, 11); // RX | TX

void setup()
{
  pinMode(9, OUTPUT);  // this pin will pull the HC-05 pin 34 (key pin) HIGH to switch module to AT mode
  digitalWrite(9, HIGH);
  Serial.begin(9600);
  Serial.println("Enter AT commands:");
  BTSerial.begin(38400);  // HC-05 default speed in AT command more
}

int ar[2]={1060, 800};
void loop()
{
  if (Serial.available()){
    //Serial.write("FromSer: ");
    BTSerial.write(Serial.read());
  }

  // Keep reading from HC-05 and send to Arduino Serial Monitor
  static bool lock = false;
  static bool sound = false;
  static char input, count = 0;
  count++;
  
  if(BTSerial.available()){
    input = BTSerial.read();
    Serial.write(input);

    switch(input){
      case 'd':
      lock = true;
      sound = true;//temporary
      break;
      case 'e':
      lock = false;
      sound = false;
      break;
      case 'q':
      return;

      case 'g':
      BTSerial.write(lock);
      BTSerial.write(sound);
      break;
      default: break;
    }
  }

  if(lock){
    //if accelerometer?
    //will replace following if(lock) if statement
  }
  
  if(lock){
    tone(8, ar[count%2], 1000);
    delay(900);
  }
/*  
  else if (BTSerial.available()){
    //Serial.write("FromBT: ");
    char input=BTSerial.read();
    Serial.write(input);
    if(input=='d')
    {
      lock = true;
      //tone(8, ar[count%2], 800);
    }

  }*/

  // Keep reading from Arduino Serial Monitor and send to HC-05
}
