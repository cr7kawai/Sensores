#include <TM1637Display.h>

// Pines de conexi�n de la pantalla
const int CLK = 26;
const int DIO = 27;
// Pines de conexi�n del sensor
const int Trigger = 21;
const int Echo = 1;

// Creamos una instancia de la clase TM1637Display y la llamamos "display"
TM1637Display display(CLK, DIO);

// Codificaci�n de una l�nea horizontal
const uint8_t linea[] = {
  SEG_G, SEG_G, SEG_G, SEG_G
};

void setup() {
  display.setBrightness(5);// Indicamos el brillo de los segmentos (0 = m�nimo; 7 = m�ximo)
  Serial.begin(9600);//iniciailzamos la comunicaci�n
  pinMode(Trigger, OUTPUT); //pin como salida
  pinMode(Echo, INPUT);  //pin como entrada
  digitalWrite(Trigger, LOW);//Inicializamos el pin con 0  
}

void loop() {
  long t; //timepo que demora en llegar el eco
  long d; //distancia en centimetros

  digitalWrite(Trigger, HIGH);
  delayMicroseconds(10);          //Enviamos un pulso de 10us
  digitalWrite(Trigger, LOW);
  
  t = pulseIn(Echo, HIGH); //obtenemos el ancho del pulso
  d = t/59;             //escalamos el tiempo a una distancia en cm
  
  display.showNumberDec(d); // Se imprime la distancia en cent�metros en el display
  delay(1000); // Espera un segundo

  display.setSegments(linea); // Imprime una �nea horizontal
  delay(1000); // Espera un segundo
}