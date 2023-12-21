#include <OneWire.h>
#include <DallasTemperature.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_BMP085.h>
#include <ezButton.h>
#define seaLevelPressure_hPa 1013.25

Adafruit_BMP085 bmp;


#define SCREEN_WIDTH 128  
#define SCREEN_HEIGHT 32 
#define OLED_RESET -1   
#define SCREEN_ADDRESS 0x3C
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
OneWire oneWire(2);
DallasTemperature sensors(&oneWire);
ezButton button(7);


int currentTemp(0);
String strTemp(0);


void setup(void)
{
  sensors.begin();
  Serial.begin(9600);
  button.setDebounceTime(30);

  Wire.begin();  // Initialize I2C communication
  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;);
  }
  if (!bmp.begin(0x77)) {
	Serial.println("Could not find a valid BMP085 sensor, check wiring!");
	while (1) {}
  }
  display.clearDisplay();
  display.setTextSize(4);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);

  display.print("JULIE");
  display.display();
  delay(2000);


}
int alti(0);
String strAlti;
String strPressure;
int screen = 0.0;
int pressure = 0;
int switchCheck;
double volts;

void loop(){
  button.loop();
  if(button.isPressed()){
    if(screen < 3) {
      screen++;
    }else {
      screen = 0;
    }
    Serial.print("The button is pressed");
  }
  if(button.isReleased()){
    Serial.print("The button has been released");
  }


  switch(screen) {
    case 0:
      sensors.requestTemperatures(); 
      currentTemp = ((sensors.getTempCByIndex(0) * 9.0) / 5.0 + 32.0) + 0.5;
      strTemp = String(currentTemp);
      strTemp = String(currentTemp) + " " + "F";
      display.clearDisplay();
      display.setTextSize(3);
      display.setCursor(0, 0);
      display.print(strTemp);
      display.setCursor(0,25);
      display.setTextSize(1);
      display.print("Temperature");
      display.display();
      break;
    case 1:
      alti = bmp.readAltitude(seaLevelPressure_hPa * 100) * 3.28;
      strAlti = String(alti) + " Ft";
      display.clearDisplay();
      display.setTextSize(3);
      display.setCursor(0, 0);
      display.print(strAlti);
      display.setCursor(0,25);
      display.setTextSize(1);
      display.print("Altitude");
      display.display();
      break;
    case 2:
      pressure = bmp.readPressure() / 100;
      strPressure = String(pressure) + " kPa";
      display.clearDisplay();
      display.setTextSize(3);
      display.setCursor(0, 0);
      display.print(strPressure);
      display.setCursor(0,25);
      display.setTextSize(1);
      display.print("Pressure");
      display.display();
      break;


  }


  //delay(100);
}




