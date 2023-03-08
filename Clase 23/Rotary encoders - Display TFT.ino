#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_ST7735.h> // Hardware-specific library for ST7735
#include <Adafruit_ST7789.h> // Hardware-specific library for ST7789
#include <SPI.h>

const int clkPin 	= 15;
const int dtPin 	= 8;
const int swPin 	= 7;

int rotVal 	= 0;
bool clkState 	= LOW;
bool clkLast 	= HIGH;
bool swState 	= HIGH;
bool swLast 	= HIGH;

#if defined(ARDUINO_FEATHER_ESP32) // Feather Huzzah32
  #define TFT_CS         14
  #define TFT_RST        15
  #define TFT_DC         32

#elif defined(ESP8266)
  #define TFT_CS         4
  #define TFT_RST        16                                            
  #define TFT_DC         5

#else
  // For the breakout board, you can use any 2 or 3 pins.
  // These pins will also work for the 1.8" TFT shield.
  #define TFT_CS        10
  #define TFT_RST        8 // Or set to -1 and connect to Arduino RESET pin
  #define TFT_DC         14
#endif

// For 1.44" and 1.8" TFT with ST7735 use:
Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);

void setup(void) {
  Serial.begin(9600);

  tft.initR(INITR_BLACKTAB);      // Init ST7735S chip, black tab
  tft.initR(INITR_MINI160x80);  // Init ST7735S mini display
  pinMode(clkPin,INPUT);
 	pinMode(dtPin,INPUT);
 	pinMode(swPin,INPUT_PULLUP); 
  
  // large block of text
  tft.fillScreen(ST77XX_BLACK);  
}

void loop() {
   tft.setCursor(0, 0);
   tft.print("Oscar Adahir Rojas Sánchez");
  clkState = digitalRead(clkPin);
 	if ((clkLast == LOW) && (clkState == HIGH)) {//rotary moving
 			Serial.print("Rotary position ");
 			if (digitalRead(dtPin) == HIGH) {
 					rotVal = rotVal - 1;
 					if ( rotVal < 0 ) {
 							rotVal = 0;
 					}
 			}
 			else {
 					rotVal++;
 					if ( rotVal > 10 ) {
 							rotVal = 10;
 					}
 			} 
      Serial.println(rotVal);
      char val[10];
      dtostrf(rotVal,5,0,val);
      tft.setCursor(0, 20);
      tft.print("El valor es ");
      tft.print(val);
      delay(1000);
      tft.fillScreen(ST77XX_BLACK);
 	}
 	clkLast = clkState;

}