#include "HX711.h"                    // Biblioteca HX711 
 
#define DOUT1  A0                      // HX711 DATA OUT = pino A0 do Arduino da balança1
#define CLK1  A1                       // HX711 SCK IN = pino A1 do Arduino da balança1

#define DOUT2  A3                      // HX711 DATA OUT = pino A0 do Arduino da balança2
#define CLK2  A4                       // HX711 SCK IN = pino A1 do Arduino da balança2
 
HX711 balanca1(DOUT1, CLK1);             // instancia Balança1 HX711
HX711 balanca2(DOUT2, CLK2);             // instancia Balança2 HX711

float calibration_factor_balanca_1 = 26450;     // fator de calibração aferido na Calibraçao da balança1
float calibration_factor_balanca_2 = 25980;  // fator de calibração aferido na Calibraçao da balança2

 
void setup()
{
  Serial.begin(9600);
  balanca1.set_scale(calibration_factor_balanca_1);      // ajusta fator de calibração da balança 1
  balanca2.set_scale(calibration_factor_balanca_2);      // ajusta fator de calibração da balança 2
  balanca1.tare();                                       // zera a Balança1
  balanca2.tare();                                       // zera a Balança2
}
 
void loop(){
float b1 = balanca1.get_units();
float b2 = balanca2.get_units();

  if (b1>0.5){
    Serial.print("Entrando: ");                // imprime no monitor serial
    Serial.print(b1, 2);              // imprime peso na balança com 2 casas decimais 
    Serial.println(" kg");                             // imprime no monitor serial 
    delay(1500) ;                                       // atraso de 1 segundo 
  }
 
  if (b2>0.5){
  Serial.print("Saindo: ");               //imprime o monitor serial
  Serial.print(b2, 2);             // imprime peso na balança com 2 casas decimais
  Serial.println(" kg");                             // imprime no monitor serial 
  delay(1500) ;                                       // atraso de 1 segundo 
  }

  if (Serial.available())                            // se a serial estiver disponivel
  {
    char temp = Serial.read();                       // le carcter da serial 
    if (temp == 't' || temp == 'T')                  // se pressionar t ou T
    {
      balanca1.tare();                                // zera a balança1
      balanca2.tare();                                // zera a balança2
      Serial.println(" Balança zerada");             // imprime no monitor serial
    }
  }
}
