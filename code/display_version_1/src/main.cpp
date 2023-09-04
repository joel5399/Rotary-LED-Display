/* Titel: Turbo Display
*  Beschreibung: Ein LED Band rotiert so schnell, dass ein Bild entsteht!
*  Autor: Joel Flepp
*  Erstellungsdatum:14.10.2022
*  Änderungen:
*  28.11.2022 Erste Tests und Pinabänderungen
*/


//Includes
#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
#include "LED.h"
#include "Image.h"
#include <math.h>

//Pin Defines
#define Strip_Pin 9
#define Hall_Sens 2
#define Motor 6


//Programm Defines
#define Ard_Freq 16000000
#define LED_Distance 6.944444 //[mm]
#define LED_Count 28
#define BRIGHTNESS 50 // Set BRIGHTNESS to about 1/5 (max = 255)
#define X_Y_TO_Left_Bottom LED_Distance*LED_Count


//Variables
float RPS = 0;
double CycleTime_MyS = 0;
LED LEDsHall[LED_Count];
LED LEDs_o_Hall[LED_Count];


//Functions
void Get_RPS();
float get_Angle();
void Set_Collors();
void Set_LEDs();


//Classes
Adafruit_NeoPixel strip(LED_Count + LED_Count, Strip_Pin, NEO_GRB + NEO_KHZ800);

//Skalierungsfaktor 
uint8_t scale = 400 / sizeof(Smiley[0]);


void setup() {
  //Start Serial
  Serial.begin(115200);
  pinMode(Hall_Sens,INPUT_PULLUP);

  //Interrupt for Hallsensor
  pinMode(Hall_Sens,INPUT_PULLUP);
  interrupts();
  attachInterrupt(digitalPinToInterrupt(Hall_Sens), Get_RPS, FALLING);
  pinMode(8,INPUT_PULLUP);
  
  //Activate Timer
  TCCR1A = 0;
  TCCR1B = 0;
  TCCR1B |= (1<<CS12); //Prescaler 256
  

  //Create LEDs Right
  for(size_t i = 0; i<LED_Count; i++){
    LEDsHall[i].set_Distance(i*LED_Distance);
  }

  //Create LEDs Left
  for(size_t i = 0; i<LED_Count; i++){
    LEDs_o_Hall[i].set_Distance(i*LED_Distance);
  }  
  
  strip.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
  strip.show();            // Turn OFF all pixels ASAP
  strip.setBrightness(50); // Set BRIGHTNESS to about 1/5 (max = 255)


}

void loop() {
  //Set x and y positions of the LEDS
  if(digitalRead(8)==0){
  for(size_t i=100; i<255;i++){
    analogWrite(Motor,i);
    delay(20);
    if(digitalRead(8)==1){
      break;
    }
  }
  while(digitalRead(8)==0){

    for(size_t i = 0; i < LED_Count; i++){
      LEDsHall[i].set_x(int(sin(get_Angle())*LEDsHall[i].get_Distance())+X_Y_TO_Left_Bottom);
      LEDsHall[i].set_y(int(cos(get_Angle())*LEDsHall[i].get_Distance())+X_Y_TO_Left_Bottom);
    }

    for(size_t i = 0; i < LED_Count; i++){
      LEDs_o_Hall[i].set_x(int(-sin(get_Angle())*LEDs_o_Hall[i].get_Distance())+X_Y_TO_Left_Bottom);
      LEDs_o_Hall[i].set_y(int(-cos(get_Angle())*LEDs_o_Hall[i].get_Distance())+X_Y_TO_Left_Bottom);
    }

    //Set the Collors
    Set_Collors();
    Set_LEDs();
    //Serial.println(LEDs_o_Hall[14].get_x());

  }
  }
  else{
    analogWrite(Motor,0);
  }


}

//Interrup routine for getting the RPM from the device
void Get_RPS(){
  //With Prescaler 256, 1 Klick is 16 myS
  CycleTime_MyS = TCNT1 * 0.000016;
  RPS = 1.0 / (double)CycleTime_MyS;
  TCNT1 = 0;
}

//Calculate Angle (rad) from revolutions
float get_Angle(){
  
  double Timer_In_myS = TCNT1 * 0.000016;
  float Angle = (Timer_In_myS*2*PI) / CycleTime_MyS;
  return Angle;
}

void Set_Collors(){
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
    strip.setPixelColor(j,strip.Color(LEDs_o_Hall[i].get_Red(), LEDs_o_Hall[i].get_Green(),LEDs_o_Hall[i].get_Blue()));
    strip.show();                          //  Update strip to match
    delayMicroseconds(300);
    j++;
  }

  for(size_t i = 0; i < LED_Count; i++){
    strip.setPixelColor(j,strip.Color(LEDsHall[i].get_Red(), LEDsHall[i].get_Green(),LEDsHall[i].get_Blue()));
    strip.show();                          //  Update strip to match
    delayMicroseconds(300);
    j++;
  }

}