#include <LiquidCrystal.h>      
int led = 22;          	       
int start  = 37;          	
LiquidCrystal lcd(48,49,45,44,43,42); 
int cont;                             

void temporizador()                  
{
  digitalWrite(led, HIGH); 		
  while(cont>0)                        
    {
      lcd.clear();                         
      lcd.setCursor(0,0);                   
      lcd.print("TEMPORIZADOR...");         
      lcd.setCursor(1,1);                   
      lcd.print("FALTAN");                 
      lcd.setCursor(8,1);                   
      lcd.print(cont);                     
      lcd.setCursor(11,1);                  
      lcd.print("SEG");                     
      delay(1000);                        
      cont--;                              
   }
  digitalWrite(led, LOW); 		
  lcd.clear();                            
}

void setup()                 
{ 
  pinMode(47,OUTPUT);
  digitalWrite(47,0);
  lcd.begin(16,2);              
  pinMode(led, OUTPUT);     	
  pinMode(start, INPUT); 	
}
void loop()                             
{
  lcd.setCursor(1,0);                   
  lcd.print("PRESIONE START");        
  lcd.setCursor(2,1);                  
  lcd.print("PARA INICIAR");        
  cont=12;                             
  if(digitalRead(start)==HIGH)        
  {
    temporizador();                     
  }
}
