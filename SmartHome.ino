#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <Servo.h>

Servo servo;   
char junk;
String inputString="";
LiquidCrystal_I2C lcd(0x27,16,2);
int LivLed = 2, BedLed = 3, KitLed = 4, BedFan = 5, DoorLed;

void setup()                   
{
 lcd.init();
 lcd.backlight(); 
 Serial.begin(9600);          
 pinMode(LivLed, OUTPUT);
 pinMode(BedLed, OUTPUT);
 pinMode(KitLed, OUTPUT);
 pinMode(BedFan, OUTPUT);
 pinMode(DoorLed, OUTPUT);
 servo.attach(6);        
}

void loop()
{
  if(Serial.available()){
  while(Serial.available())
    {
      char inChar = (char)Serial.read(); //read the input
      inputString += inChar;
      //make a string of the characters coming on serial
    }

    while (Serial.available() > 0)  
    junk = Serial.read() ;    // clear the serial buffer
   
    if(inputString == "a"){         //  turn the Living Room Light on
      digitalWrite(LivLed, HIGH);
      lcd.clear();
      lcd.setCursor(0,0);    
      lcd.print("Living Room Light");
      lcd.setCursor(7,1);
      lcd.print("ON");
      
    } 
    
    if(inputString == "b"){   //  turn the Living Room Light off
      digitalWrite(LivLed, LOW);
      lcd.clear();
      lcd.setCursor(0,0);  
      lcd.print("Living Room Light");
      lcd.setCursor(7,1);
      lcd.print("OFF");
          }
    
    if(inputString == "c"){         //  turn the Kitchen Light on
      digitalWrite(KitLed, HIGH);
      lcd.clear();
      lcd.setCursor(2,0);
      lcd.print("Kitchen Light");
      lcd.setCursor(7,1);
      lcd.print("ON");
      
    } 
    
    if(inputString == "d"){   //  turn the Kitchen Light off
      digitalWrite(KitLed, LOW);
      lcd.clear();
      lcd.setCursor(2,0);
      lcd.print("Kitchen Light");
      lcd.setCursor(7,1);
      lcd.print("OFF");    
      
    }  
    
    if(inputString == "e"){         //  turn the Bed Room Light on
      digitalWrite(BedLed, HIGH);  
      lcd.clear();
      lcd.setCursor(2,0);
      lcd.print("Bed Room Light");
      lcd.setCursor(7,1);
      lcd.print("ON");
      
    } 
    
    if(inputString == "f"){   //  turn the Bed Room Light off
      digitalWrite(BedLed, LOW);
      lcd.clear();
      lcd.setCursor(2,0);
      lcd.print("Bed Room Light");
      lcd.setCursor(7,1);
      lcd.print("OFF");        
      
    }
    
    if(inputString == "g"){         //  turn the FAN on
      digitalWrite(BedFan, HIGH);  
      lcd.clear();
      lcd.setCursor(7,0);
      lcd.print("Fan");
      lcd.setCursor(7,1);
      lcd.print("ON");  
      
    } 
    
    if(inputString == "h"){   //  turn the FAN off
      digitalWrite(BedFan, LOW);
      lcd.clear();
      lcd.setCursor(7,0);
      lcd.print("Fan");
      lcd.setCursor(7,1);
      lcd.print("OFF");  
      
    } 
    
    if (inputString == "i")// khi nhận tính hiệu từ ứng dụng điều khiển
    {
        servo.write(180);
        delay(5);
        lcd.clear();
        lcd.setCursor(6,0);
        lcd.print("Door");
        lcd.setCursor(5,1);
        lcd.print("LOCKED");      
        digitalWrite(DoorLed,LOW);
        }
          
    if (inputString == "j"){
        servo.write(75);
        delay(5);lcd.clear();
        lcd.setCursor(6,0);
        lcd.print("Door");
        lcd.setCursor(4,1);
        lcd.print("UNLOCKED");
        digitalWrite(DoorLed,HIGH);
    }
    
    if (inputString == "x"){
        lcd.setCursor(4,0);
        lcd.print("Good Night!");
        digitalWrite(LivLed, LOW);
        digitalWrite(BedLed, LOW);
        digitalWrite(KitLed, LOW);
        digitalWrite(BedFan, LOW);
        digitalWrite(DoorLed, LOW);
        servo.write(180);
    }
    
    inputString = "";
  }
}
