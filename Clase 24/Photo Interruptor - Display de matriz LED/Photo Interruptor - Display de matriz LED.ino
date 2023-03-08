#include <Adafruit_GFX.h>
#include <Adafruit_NeoMatrix.h>
#include <Adafruit_NeoPixel.h>
#ifndef PSTR
#define PSTR // Make Arduino Due happy
#endif

#define PIN 14
int sensr = 5;
int val;
String res;

// Forma en la que se va a imprimir el valor
Adafruit_NeoMatrix matrix = Adafruit_NeoMatrix(8, 8, 4, 1, PIN,
  NEO_TILE_TOP   + NEO_TILE_LEFT   + NEO_TILE_COLUMNS   + NEO_TILE_PROGRESSIVE +
  NEO_MATRIX_TOP + NEO_MATRIX_LEFT + NEO_MATRIX_COLUMNS + NEO_MATRIX_ZIGZAG,
  NEO_GRB + NEO_KHZ800);

const uint16_t colors[] = {
  matrix.Color(255, 0, 0), matrix.Color(0, 255, 0), matrix.Color(0, 0, 255) };

void setup() {
  matrix.begin();
  matrix.setTextWrap(false);
  matrix.setBrightness(40);
  matrix.setTextColor(colors[0]);
  pinMode (sensr, INPUT);
  Serial.begin(9600);
}

int x    = matrix.width();
int pass = 0;

void loop() {
  // Se lee el sensor y de acuerdo al valor se muestra un mensaje en la matríz
  val = digitalRead (sensr);
  if (val == HIGH) {
    res = "Apagado";
  }else{
    res = "Encendido";
  }
  String imp = "Oscar Rojas "+res;
  Serial.println(imp);
  
  // Mover el mensaje por la matríz
  matrix.fillScreen(0);
  matrix.setCursor(x, 0);
  matrix.print(imp);
  if(--x < -150) {
    x = matrix.width();
    if(++pass >= 3) pass = 0;
    matrix.setTextColor(colors[pass]);
  }
  matrix.show();
  delay(100);
}