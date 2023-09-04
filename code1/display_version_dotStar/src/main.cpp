/* Titel: Turbo Display
*  Beschreibung: Ein LED Band rotiert so schnell, dass ein Bild entsteht!
*  Autor: Joel Flepp
*  Erstellungsdatum:14.10.2022
*  Änderungen:
*  28.11.2022 Erste Tests und Pinabänderungen
*  01.09.2023 Weiterentwcklung
*/

/*******************************************
 * Positionierung x und y
 * 
 *  LEDs
 *  0 1 2 3 4   5 6 7 8 9
 *    
 *  o o o o o x o o o o o
 * 
 *  /\
 *  |
 *  |_____>
 *  (0;0)
 * *****************************************/



//Includes
#include <Arduino.h>
#include <Adafruit_DotStar.h>
#include <Wire.h>
#include <SPI.h>
#include <math.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include "LED.h"
#include "Image.h"

//Pin Defines
const int DATAPIN = 4;
const int CLOCKPIN = 5;
const int Hall_Sens = 2;

//Programm const
const double Ard_Freq = 16000000;
const double LED_Distance = 6.944444;                       // [mm]
const int LED_Count = 58;                                   // 
const uint8_t BRIGHTNESS = 50;                              // Set BRIGHTNESS to about 1/5 (max = 255)
const double X_Y_TO_Left_Bottom = LED_Distance * LED_Count;


//Variables
unsigned long previousTime = 0;
double CycleTime_S = 0;
LEDClass LED[LED_Count];

//Skalierungsfaktor 
const int spannweite = 400; 
uint8_t scale = spannweite / sizeof(Smiley[0]);


//Functions
void Get_RPS();
float get_Angle();
void Set_Collors();
void Set_LEDs();
void setLEDPosition(const int LEDPos, const int );

//Classes
Adafruit_DotStar strip(LED_Count + LED_Count, DATAPIN, CLOCKPIN, DOTSTAR_BGR);



void setup() {
  //Start Serial
  Serial.begin(115200);

  //Interrupt for Hallsensor
  pinMode(Hall_Sens,INPUT_PULLUP);
  interrupts();
  attachInterrupt(digitalPinToInterrupt(Hall_Sens), Get_RPS, FALLING);
  
  //Create LEDs Right
  for(size_t i = 0; i<LED_Count; i++){
    LEDsHall[i].set_Distance(i*LED_Distance);
  }

  //Create LEDs Left
  for(size_t i = 0; i<LED_Count; i++){
    LEDs_o_Hall[i].set_Distance(i*LED_Distance);
  }  
  
  strip.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
  strip.setBrightness(BRIGHTNESS); // Set BRIGHTNESS to about 1/5 (max = 255)
  strip.clear();            // Turn OFF all pixels ASAP

  
}

void loop() {

  double currentAngle = get_Angle();

  for(size_t i = 0; i < LED_Count; i++){
    setLEDPosition(LEDsHall[i])
    LEDsHall[i].set_x(int(sin(currentAngle)*LEDsHall[i].get_Distance()) + X_Y_TO_Left_Bottom);
    LEDsHall[i].set_y(int(cos(currentAngle)*LEDsHall[i].get_Distance()) + X_Y_TO_Left_Bottom);
  }
*/
  for(size_t i = 0; i < LED_Count; i++){
    LEDs_o_Hall[i].set_x(int(-sin(currentAngle)*LEDs_o_Hall[i].get_Distance()) + X_Y_TO_Left_Bottom);
    LEDs_o_Hall[i].set_y(int(-cos(currentAngle)*LEDs_o_Hall[i].get_Distance()) + X_Y_TO_Left_Bottom);
  }

  //Set the Collors
  Set_Collors();
  Set_LEDs();

  
}

//Interrup routine for getting the RPM from the device
void getCycleTime() {
  unsigned long elapsedTime = micros() - previousTime;
  previousTime = micros();
  CycleTime_S = (double)elapsedTime * 1e-6;
}


//Calculate Angle (rad) from revolutions
float getCurrentAngle() {
  double Time_In_S = (double)(micros() - previousTime) * 1e-6;
  float Angle = (Time_In_S*2*PI) / CycleTime_S;
  return Angle;
}

void setLEDCollors(){
  for(size_t i = 0; i < LED_Count; i++){
    LEDsHall[i].set_Red(Smiley[(uint8_t)LEDsHall[i].get_x()/scale][(uint8_t)LEDsHall[i].get_y()/scale]);
    LEDsHall[i].set_Blue(Smiley[(uint8_t)LEDsHall[i].get_x()/scale][(uint8_t)LEDsHall[i].get_y()/scale]);
    LEDsHall[i].set_Green(Smiley[(uint8_t)LEDsHall[i].get_x()/scale][(uint8_t)LEDsHall[i].get_y()/scale]);
    LEDs_o_Hall[i].set_Red(Smiley[(uint8_t)LEDs_o_Hall[i].get_x()/scale][(uint8_t)LEDs_o_Hall[i].get_y()/scale]);
    LEDs_o_Hall[i].set_Blue(Smiley[(uint8_t)LEDs_o_Hall[i].get_x()/scale][(uint8_t)LEDs_o_Hall[i].get_y()/scale]);
    LEDs_o_Hall[i].set_Green(Smiley[(uint8_t)LEDs_o_Hall[i].get_x()/scale][(uint8_t)LEDs_o_Hall[i].get_y()/scale]);
  }

}

void Set_LEDs(){
  uint8_t j = 0;
  for(size_t i = LED_Count; i > 0; i--){
    strip.setPixelColor(j,LEDs_o_Hall[i].get_Red(), LEDs_o_Hall[i].get_Green(),LEDs_o_Hall[i].get_Blue());
    j++;
  }
/*
  for(size_t i = 0; i < LED_Count; i++){
    strip.setPixelColor(j,LEDsHall[i].get_Red(), LEDsHall[i].get_Green(),LEDsHall[i].get_Blue());
    j++;
  }
  */
  strip.show();

}
