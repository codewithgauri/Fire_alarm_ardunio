
#include <LiquidCrystal.h>
float temp;
int led_red=7;
int led_green=8;
int buzzer=6;
int sensorval;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  lcd.begin(16, 2);
  pinMode(led_red,OUTPUT);
  pinMode(led_green,OUTPUT);
  pinMode(buzzer,OUTPUT);

  Serial.begin(9600);
}

void loop() {
  temp=analogRead(A0);
  temp=temp*0.4882;
  lcd.setCursor(0, 1);
  lcd.print(temp);
  lcd.setCursor(6, 1);
  lcd.print("c");
  
  Serial.println(temp,DEC);
 
  if (temp>=45){
  	digitalWrite(led_red,HIGH);
   
    digitalWrite(led_green,LOW);
    lcd.setCursor(0,0);
    lcd.print("TEMP HIGH ALERT");
    tone(buzzer,800,200);
    delay(200);         
    tone(buzzer,600,200);
    delay(200);
  }else{
  	digitalWrite(led_green,HIGH);
    digitalWrite(led_red,LOW);
    lcd.setCursor(0,0);
    lcd.print("TEMP LOW ");
  }
}