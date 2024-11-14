int LedAmarelo=8;
int LedVermelho=5;
int LedVerde=4;
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

//Inicializa o display no endereco 0x27
LiquidCrystal_I2C lcd(0x27,16,2);
 
void setup()
{
  lcd.init();
 lcd.setBacklight(HIGH);
 pinMode(LedAmarelo,OUTPUT);
 pinMode(LedVermelho,OUTPUT);
 pinMode(LedVerde,OUTPUT);}
void loop()
{
  int ValorPot=analogRead(A0);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Potec"+String(ValorPot));
  lcd.setCursor(0,1);
  if(ValorPot>0 && ValorPot<=400){ 
    digitalWrite(LedVerde,LOW);
    digitalWrite(LedVermelho,LOW);
    digitalWrite(LedAmarelo,HIGH);
    lcd.print("Led Amarelo ON");
  }
  if(ValorPot>400 && ValorPot<=800){
    lcd.print("Led Vermelho ON");
    digitalWrite(LedVermelho,HIGH);
  }
  if(ValorPot>800 && ValorPot<=1200){
    lcd.print("Led Verde ON");
    digitalWrite(LedVerde,HIGH);
  }
  delay(500);

}
