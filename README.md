# Practica 1. Gerard Cots y Joel J. Morera
## 1. Blink
Codigo de la primera parte:
```c
#include <Arduino.h>

int LED_BUILTIN = 23;

void setup()
{
    Serial.begin(115200);
    pinMode( LED_BUILTIN, OUTPUT);
}

void loop()
{
    digitalWrite(LED_BUILTIN, HIGH);
    Serial.println("ON");
    delay(500);
    digitalWrite(LED_BUILTIN, LOW);
    Serial.println("OFF");
    delay(500);
}
```
**Tiempo libre del procesador:**
## 2. Leer valor analogico y mostrarlo
Codigo de la segunda parte:
```c
#include <Arduino.h>

int lecture = 0;

void setup()
{
    Serial.begin(115200);
}

void loop()
{
    lecture = analogRead(13);

    Serial.print("Voltatge d'entrada: ");
    Serial.print(lecture);
    Serial.print(" mV");
    Serial.println("");

    analogWrite();
}
```

## 3. Leer valor del sensor de temperatura interno
Codigo de la tercera parte:
```c
#include <Arduino.h>

float temperature =0;

void setup() 
{
  Serial.begin(115200);
}

void loop() 
{
    temperature = temperatureRead();

    Serial.print("Temperatura: ");
    Serial.print(Temperatura);
    Serial.print(" Cº");
    Serial.println("");
}
```