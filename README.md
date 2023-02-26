# Practica 1. Gerard Cots y Joel J. Morera
## 1. Blink
El resultado de este código consiste en hacer parpadear el led integrado en la placa cada 500 milisegundos y imprimir por pantalla el estado del mismo.
```c
#include <Arduino.h>

int LED_BUILTIN = 23;   //El pin 23 esta conectado al led de la placa  

//Codigo que solo se ejecuta una vez:
void setup()
{
    Serial.begin(115200);           //Velocidad de transimision
    pinMode( LED_BUILTIN, OUTPUT);  //Definimos el led en el pin 23 como salida
}

//Codigo que se ejecuta repetitivamente:
void loop()
{
    digitalWrite(LED_BUILTIN, HIGH);    //Encendemos el LED, siendo HIGH(alto) el nivel de voltaje
    Serial.println("ON");               //Imprimimos por pantalla que el LED esta encendido
    delay(500);                         //Espera de 500 ms
    digitalWrite(LED_BUILTIN, LOW);     //Apagamos el LED, haciendo el nivel de volatje LOW(bajo)
    Serial.println("OFF");              //Imprimimos por pantall aque el LED esta apagado  
    delay(500);                         //Espera de 500 ms
}
```
**Tiempo libre del procesador:**
## 2. Leer valor analógico y mostrarlo
En este punto el objetivo del código consiste en leer un valor analógico por un pin, en concreto el 13, imprimir el valor leído por pantalla y sacarlo por otro pin, en concreto el X.
```c
#include <Arduino.h>

int lecture = 0;    //Declaración de la variable en la que guardaremos el valor leido

//Codigo que solo se ejecuta una vez:
void setup()
{
    Serial.begin(115200);           //Velocidad de transimision
    //pinMode(13, INPUT)            //Definimos el pin 13 como pin de entrada
}

//Codigo que se ejecuta repetitivamente:
void loop()
{
    lecture = analogRead(13);               //Guardamos el valor que lee el pin 13 en la variable "lecture"

    Serial.print("Voltatge d'entrada: ");   //Escribimos por pantalla el valor guardado en "lecture"
    Serial.print(lecture);
    Serial.print(" mV");
    Serial.println("");

    analogWrite();                          //Sacamos por el pin X el valor guardado en "lecture"
}
```

## 3. Leer valor del sensor de temperatura interno
Por último, este código nos mostrara por pantalla el valor que lee el sensor que tempreatura interno del procesador.
```c
#include <Arduino.h>

float temperature = 0;   //Declaración de la variable en la que guardaremos el valor leido

//Codigo que solo se ejecuta una vez:
void setup()
{
    Serial.begin(115200);           //Velocidad de transimision
}

//Codigo que se ejecuta repetitivamente:
void loop() 
{
    temperature = temperatureRead();    //Guardamos el valor de temperatura que lee el procesador 

    Serial.print("Temperatura: ");      //Sacamos por pantalla el valor guardado en "temperature"
    Serial.print(Temperatura);
    Serial.print(" Cº");
    Serial.println("");
}
```