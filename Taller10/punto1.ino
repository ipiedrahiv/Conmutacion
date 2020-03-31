int cont;
const int sw = 37; 
byte const horario[4] = {0b1100, 0b0110, 0b0011, 0b1001};
byte const antih[4] = {0b1001, 0b0011, 0b0110, 0b1100};
void setup()
{
 pinMode(22, OUTPUT); 
 pinMode(23, OUTPUT); 
 pinMode(24, OUTPUT); 
 pinMode(25, OUTPUT); 
 pinMode(sw, INPUT); 
}
void loop() {
 if (digitalRead(sw) == HIGH) 
 {
 cont = 0; 
 while (cont < 4 && digitalRead(sw) == HIGH)
 {
 PORTA = (horario[cont]); 
 delay(100);
 cont++; 
 }
 }
 else
 {
 cont = 0; 
 while (cont < 4 && digitalRead(sw) == LOW) 
 {
 PORTA = (antih[cont]); 
 delay(100); 
 cont++;
 }
 }
}
