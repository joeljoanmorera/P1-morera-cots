#include <Arduino.h>

int Lectura = 0;
float Temperatura =0;

void setup() {
  Serial.begin(115200);
  Serial.println("Hola Mundo!");
  pinMode(23,OUTPUT);
  pinMode(15, OUTPUT);

  // put your setup code here, to run once:
}

void loop() {

digitalWrite(23,HIGH);
Serial.print("SORTIDA: ");
Serial.print("ON");
Serial.println("");

Lectura = analogRead(15);
Temperatura = temperatureRead();

Serial.print("Temperatura: ");
Serial.print(Temperatura);
Serial.print(" Cº");
Serial.println("");

Serial.print("Voltatge d'entrada: ");
Serial.print(Lectura);
Serial.print(" mV");
Serial.println("");
analogWrite(15,Lectura);
delay(500);


digitalWrite(23,LOW);
Serial.print("SORTIDA: "); 
Serial.print("OFF");
Serial.println("");

delay(500);
  // put your main code here, to run repeatedly:
}