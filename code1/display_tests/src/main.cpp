#include <Arduino.h>
#include <math.h>

#define Ard_Freq 16000000

float RPS = 0;
double CycleTime_MyS = 0;
void Get_RPS();

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  pinMode(2,INPUT_PULLUP);
  interrupts();
  attachInterrupt(digitalPinToInterrupt(2), Get_RPS, FALLING);
  pinMode(8,INPUT_PULLUP);


 //Activate Timer
  TCCR1A = 0;
  TCCR1B = 0;
  TCCR1B |= (1<<CS12); //Prescaler 256
  
}

void loop() {
  // put your main code here, to run repeatedly:
    
}
void Get_RPS(){
  //With Prescaler 256, 1 Klick is 16 myS
  CycleTime_MyS = TCNT1 * 0.000016;
  RPS = 1.0 / (double)CycleTime_MyS;
  Serial.println(RPS);
  TCNT1 = 0;
}