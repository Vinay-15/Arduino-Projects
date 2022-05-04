#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);

#define flamePin 10
#define buzzerPin 11
#define led 13


void setup() {
  
 pinMode(buzzerPin,OUTPUT); 
 pinMode(flamePin,INPUT);
 pinMode(led,OUTPUT);

  lcd.init();
  lcd.init(); 
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Calibrating");
    for(int i = 0; i <15; i++){
      if (i==4)
      {
         lcd.setCursor(0, 1);
         lcd.print(".");
        }
       else  lcd.print(".");
      delay(500);
      }
    lcd.setCursor(11, 1);
    lcd.print("Done");
    delay(1000);
    lcd.clear(); 
    lcd.setCursor(1, 0);
    lcd.print("Sensor Active");
    delay(1500);
    lcd.clear(); 

}

void loop() {
  
int Flame = digitalRead(flamePin);

  if (Flame == LOW)
  {
     digitalWrite(buzzerPin,HIGH);
     lcd.setCursor(0, 0);
     lcd.print(" Flame : ");
     lcd.print("Flame");
     lcd.setCursor(0, 1);
     lcd.print("  is Detected");
     Serial.print(Flame);
     Serial.print("\t");
     Serial.print("Flame is Detected");   
     digitalWrite(led,HIGH);
  }
  else if (Flame == HIGH)
  {
     digitalWrite(buzzerPin,LOW);
     lcd.setCursor(0, 0);
     lcd.print("Flame : ");
     lcd.print("No Flame");
     Serial.print(Flame);
     Serial.print("\t");
     Serial.println("No Flame");   
     digitalWrite(led,LOW);
  }
  
  delay(300);
  lcd.clear();
}
