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
 * (conector)left    right
 *       0 1 2 3 4   5 6 7 8 9
 *
 *       o o o o o x o o o o o
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
#include <avr/io.h>
#include <avr/interrupt.h>
#include "LED.h"
#include "Image.h"

//Pin Defines
const int dataPin = 4;
const int clockPin = 5;
const int hallSensor = 2;

//Programm const
const double angleOffset = 1.7;
const double LEDOffset = 2.5;
const double LEDDistance = 6.944444;                       // [mm]
const int LEDCount = 58;                                   // 
const uint8_t brightness = 20;                              // Set BRIGHTNESS to about 1/5 (max = 255)
const double X_Y_TO_Left_Bottom = LEDDistance * (LEDCount / 2);


//Variables
unsigned long previousTime = 0;
unsigned long cycleTime_myS = 0;
LEDClass LED[LEDCount];

//Skalierungsfaktor 
const int wingspan = LEDCount * LEDDistance; // [mm]
const double ImgScale = wingspan / sizeof(Smiley[0]); // [mm / arrayLength]


//Functions
void getCycleTime();
double getCurrentAngle();
void setLEDPosition(const int& LEDPos, const double& CurrentAngle);
void setLEDCollors(const int& LEDPos);
void UpdateLEDs();


//Classes
Adafruit_DotStar strip(LEDCount, DOTSTAR_BGR);

void setup() {
    // Start Serial
    Serial.begin(115200);

    // Interrupt for HallSensor
    pinMode(hallSensor, INPUT_PULLUP);
    interrupts();
    attachInterrupt(digitalPinToInterrupt(hallSensor), getCycleTime, RISING);

    // Create LEDs
    for (size_t i = 0; i < LEDCount; i++) {
        LED[i].setDistance(i * LEDDistance + LEDOffset);
    }

    // INITIALIZE Dorstar strip object
    strip.begin();
    strip.setBrightness(brightness);
    strip.clear();
}

void loop() {
    double currentAngle = getCurrentAngle();
    //Serial.println(currentAngle);
    for (size_t i = 0; i < LEDCount; i++) {
        setLEDPosition(i, currentAngle);
        setLEDCollors(i);
    }
    UpdateLEDs();
}

//Interrupt routine for getting the RPM from the device
void getCycleTime() {
    cycleTime_myS = micros() - previousTime;
    previousTime = micros();
}

//Calculate Angle (rad) from revolutions
double getCurrentAngle() {
    return ((double)(micros() - previousTime) / (double)(cycleTime_myS)) * 2 * 3.14 + angleOffset;
}


void setLEDPosition(const int& LEDPos, const double& CurrentAngle) {
    LED[LEDPos].setXYCartesianFromAngle(CurrentAngle, wingspan);
}


void setLEDCollors(const int& LEDPos) {
    const uint8_t xPosImg = LED[LEDPos].getXPos() / ImgScale;
    const uint8_t yPosImg = LED[LEDPos].getYPos() / ImgScale;

    LED[LEDPos].setRed(Smiley[xPosImg][yPosImg]);
    LED[LEDPos].setBlue(Smiley[xPosImg][yPosImg]);
    LED[LEDPos].setGreen(Smiley[xPosImg][yPosImg]);
}

void UpdateLEDs() {
    for (size_t i = 0; i < LEDCount; i++) {
        strip.setPixelColor(i, LED[i].getRed(), LED[i].getGreen(), LED[i].getBlue());
    }
    strip.show();
}
