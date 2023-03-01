# Practica 1. Gerard Cots y Joel J. Morera
## 1. Blink
El resultado de este código consiste en hacer parpadear el led integrado en la placa cada 500 milisegundos y imprimir por pantalla el estado del mismo.

A continuación aparece el **código del programa**:


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

El **diagrama de flujo** del programa es el siguiente:

<div class="mermaid">
graph TD;
    A[LED ON]       --> B;
    B[Print 'ON']   --> C;
    C[Delay 500 ms] --> D;
    D[LED OFF]      --> E;
    E[Print 'OFF']  --> F;
    F[Dealy 500 ms] --> A;
</div>


Por orta parte, el **diagrama de tiempos** del programa es:


```wavedrom

{ signal : [
  { name: "CLK",  wave: "p........" },
  { name: "Estado LED",  wave: "545454545", data: "ON OFF ON OFF ON OFF ON OFF ON" },
]}
```

**Tiempo libre del procesador:**
## 2. Leer valor analógico, mostrarlo y escribirlo
En este punto el objetivo del código consiste en leer un valor analógico por un pin, en concreto el 13, imprimir el valor leído por pantalla y sacarlo por otro pin, en concreto el 15.


El **codigo del programa** es:


```c
#include <Arduino.h>

int lecture = 0;    //Declaración de la variable en la que guardaremos el valor leido

//Codigo que solo se ejecuta una vez:
void setup()
{
    Serial.begin(115200);           //Velocidad de transimision
    pinMode(13, INPUT);             //Definimos el pin 13 como pin de entrada
    pinMode(15, OUTPUT);            //Definimos el pin 15 como pin de salida
}

//Codigo que se ejecuta repetitivamente:
void loop()
{
    lecture = analogRead(13);               //Guardamos el valor que lee el pin 13 en la variable "lecture"

    Serial.print("Voltatge d'entrada: ");   //Escribimos por pantalla el valor guardado en "lecture"
    Serial.print(lecture);
    Serial.print(" mV");
    Serial.println("");

    analogWrite(15, lecture);                          //Sacamos por el pin 15 el valor guardado en "lecture"
    
    delay(500);                             // Delay de 500 milisegundos
}
```


El **diagrama de flujo** del programa es el siguiente:


<div class="mermaid">
graph TD;
    A[Lectura Valor Pin 13]         --> B;
    B[Print del valor]              --> C;
    C[Salida Valor Pin 15]   --> D;
    D[LED OFF]                      --> E;
    E[Dealy 500 ms]                 --> A;
</div>


Por último, el **diagrama de tiempos** del programa es:


```wavedrom

{ signal : [
  { name: "CLK",  wave: "p........" },
  { name: "Lectura pin 13",  wave: "545454545", data: "ON OFF ON OFF ON OFF ON OFF ON" },
  { name: "Escritura pin 15",  wave: "545454545", data: "ON OFF ON OFF ON OFF ON OFF ON" },
]}
```
## 3. Leer valor del sensor de temperatura interno
Por último, este código nos mostrara por pantalla el valor que lee el sensor que tempreatura interno del procesador.

El **codigo del programa** es el siguiente:
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

    delay(500);                             // Delay de 500 milisegundos
}
```

El **diagrama de flujo** del programa es:

<div class="mermaid">
graph TD;
    A[Lectura valor tempreatura]    --> B;
    B[Print del valor]              --> C;
    C[Delay 500 ms]                 --> A;
</div>


Por último, el **diagrama de tiempos** del programa es:


```wavedrom

{ signal : [
  { name: "CLK",  wave: "p........" },
  { name: "LECTURA",  wave: "545454545", data: "ON OFF ON OFF ON OFF ON OFF ON" },
]}
```