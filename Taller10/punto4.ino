#include <Keypad.h>                     
#include <LiquidCrystal.h>               
LiquidCrystal lcd(48,49,45,44,43,42);  
const byte filas = 4;                    
const byte columnas = 3;               
char teclas[filas][columnas] =          
{
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};
byte pinesfilas[filas] = {21,20,19,18};    
byte pinescolumnas[columnas] = {17,16,15};
Keypad teclado = Keypad( makeKeymap(teclas), pinesfilas,  pinescolumnas, filas,columnas );
int led = 22;          	        
int tiempo,uni,dec;                               
char k;                                   

int teclados()                         
{
  int val;  
  k=teclado.getKey(); 	                 

  while((k=='\0')||(k=='#')||(k=='*'))	 
  {
    k=teclado.getKey();                     
  }

  val=k-48;                              
  return val;
}

void temporizando()                       
{
  digitalWrite(led, HIGH); 		
  while(tiempo>0)                          
  {
    lcd.clear();                         
    lcd.setCursor(1,0);                    
    lcd.print("TEMPORIZANDO...");          
    lcd.setCursor(1,1);                   
    lcd.print("FALTAN");                  
    lcd.setCursor(8,1);                     
    lcd.print(tiempo);                      
    lcd.setCursor(11,1);                   
    lcd.print("SEG");                      
    delay(1000);                          
    tiempo--;                             
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
  digitalWrite(led, LOW); 
 
}
void loop()                               
{
  lcd.setCursor(1,0);                    
  lcd.print("INGRESE TIEMPO");            
  dec=teclados();                        
  lcd.setCursor(3,1);                    
  lcd.print(dec);                        
  uni=teclados();                       
  lcd.setCursor(4,1);                    
  lcd.print(uni);                         
  lcd.setCursor(6,1);                     
  lcd.print("SEGUNDOS");                   
  while(k!='#')                           
  {
    k=teclado.getKey();                    
  }
  tiempo=dec*10+uni;
  temporizando();                         
}
