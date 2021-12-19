#include <LiquidCrystal.h>
int trigPin = 7;
int echoPin = 6;
int matlab = A0;
int sure;
int uzaklik;
int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
int uzaklik2; 
int p;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  lcd.begin(16, 2);
  //Serial.begin(9600);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  sure = pulseIn(echoPin, HIGH, 11600);
  uzaklik= (sure*0.0345)/2;
  delay(250);
  //Serial.print(uzaklik);
  //Serial.print(" ");
  if (uzaklik>0 && uzaklik<=200){
    lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Uzaklik:");
  lcd.setCursor(0,1);
  lcd.print(uzaklik);
  lcd.print("cm");
  }
  else
  {lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Hatali Uzaklik"); 
  }
  //Serial.print(uzaklik);
 

  //lcd.clear();
  //lcd.setCursor(0,0);
  //lcd.print("Uzaklik:");
  //lcd.setCursor(0,1);
  //lcd.print(uzaklik);
  //lcd.print("cm");
  
}
