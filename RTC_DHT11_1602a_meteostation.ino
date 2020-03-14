#include <DHT.h>
#include <LiquidCrystal.h>
#include <iarduino_RTC.h>
#define DHTPIN 11
iarduino_RTC time(RTC_DS1302,10,8,9);
LiquidCrystal lcd(7,6,5,4,3,2);
DHT dht(DHTPIN, DHT11);


void setup() {
  time.begin();
  lcd.begin(16,2);
  dht.begin();
  byte m[8] = {6,9,9,6,0,0,0,0};
  lcd.createChar(0,m);
}   
void loop(){
  int t = dht.readTemperature();
  float h = dht.readHumidity();
  lcd.setCursor(0,0);
  lcd.print(time.gettime("d.m/"));
  lcd.setCursor(6,0);
  lcd.print(time.gettime("h:i:s"));
  lcd.setCursor(0,1);
  lcd.print(t);
  lcd.write(byte(0));
  lcd.print("C");
  lcd.setCursor(5,1);
  lcd.print(h);
  lcd.print("%");
  delay(1000);
  lcd.clear();
}
