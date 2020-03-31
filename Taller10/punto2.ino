#include <LiquidCrystal.h>
LiquidCrystal lcd (48, 49, 45, 44, 43, 42);
//primera fila UNIVERSIDAD
//segunda fila EAFIT-MEDELLIN
void setup() {
  // put your setup code here, to run once:
  pinMode(47,OUTPUT);
  digitalWrite(47,0); //pone un 0 en el pin 47 y habilita el lcd
  lcd.begin(16,2);
}

void loop() {
  // put your main code here, to run repeatedly:
  lcd.setCursor(5,0);
  lcd.print("Isabel");
  lcd.setCursor(3,1);
  lcd.print("Piedrahita");
}
