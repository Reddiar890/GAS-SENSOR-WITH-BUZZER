#include <LiquidCrystal.h>
LiquidCrystal lcd(5,6,8,9,10,11);
 
int redled = 2;
int greenled = 3;
int sensor = A0;
int sensorTresh = 400;
int buzz =12;



void setup()
{
  pinMode(redled,OUTPUT);
  pinMode(greenled,OUTPUT);
  pinMode(sensor,INPUT);
  pinMode(12,OUTPUT);
  Serial.begin(9600);
  lcd.begin(16,2);
}

void loop()
{
 	int analogValue = analogRead(sensor);
  	Serial.print(analogValue);
    if(analogValue>sensorTresh){
      digitalWrite(redled,HIGH);
      digitalWrite(greenled,LOW);
      lcd.clear();
      lcd.setCursor(0,1);
      digitalWrite(12,HIGH);
      lcd.print("ALERT");
      delay(1000);
      lcd.clear();
      lcd.print("EVACUATE");
      delay(1000);
      digitalWrite(12,LOW);
    }
  else
  {
    digitalWrite(greenled,HIGH);
    digitalWrite(redled,LOW);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("SAFE");
    delay(1000);
    lcd.clear();
    lcd.setCursor(0,1);
    lcd.print("ALL CLEAR");
    delay(1000);
  }   

}