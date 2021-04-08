#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int sensor = 9;  
int state = LOW; 
int val = 0;
int buzzer= 10;  

void setup() 
{
  pinMode(sensor, INPUT);    
  pinMode(buzzer, OUTPUT); 
  lcd.begin(16, 2);
  lcd.print("MOTION DETECTOR");
}

void loop() 
{
  val = digitalRead(sensor);   
  if (val == HIGH)
  {
  delay(1000);                 
    if (state == LOW) 
      {
    lcd.setCursor(0, 1);
    lcd.print("MOTION DETECTED!!!");
    digitalWrite(buzzer, HIGH);   
    state = HIGH;       
       }  
     }
  else
   {
     delay(200);            
      if (state == HIGH)
     {
        lcd.setCursor(0, 1);
        lcd.print("MOTION CAN'T DETECTED!!!");
        digitalWrite(buzzer, LOW);   
        state = LOW;       
     }
   }
}