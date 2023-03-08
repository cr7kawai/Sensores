#include "DHT.h"	//Librer?a del sensor

#define DHTPIN 9     	// Pin donde est? conectado el sensor
#define DHTTYPE DHT11   //Sensor de temperatura y humedad que se usar?

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  Serial.println("Iniciando...");
  dht.begin();
}

void loop() {
  delay(2000);
  float h = dht.readHumidity(); //Leemos la Humedad
  float t = dht.readTemperature(); //Leemos la temperatura en grados Celsius
  float f = dht.readTemperature(true); //Leemos la temperatura en grados Fahrenheit
  //--------Enviamos las lecturas por el puerto serial-------------
  Serial.print("Humedad ");
  Serial.print(h);
  Serial.println(" %");
  Serial.print("Temperatura: ");
  Serial.print(t);
  Serial.print(" *C y ");
  Serial.print(f);
  Serial.println(" *F");
}