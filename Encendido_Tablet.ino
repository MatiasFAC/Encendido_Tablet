//Author    Matias Araya
//Workgroup N2
#include <Wire.h> 
#include "RTClib.h"
#define button 7
RTC_DS1307 RTC;

const int button_puch_time=3000;    //3 sec to push
const int det_h=8;                  //start Hour, range 0 - 23
const int det_m=0;                 //start Minute, range 0 - 59
const int det_s=0;                 //start Second, range 0 - 59

int act_hou;
int act_min;
int act_sec;

void setup () {
  Wire.begin();
  RTC.begin();
  //RTC.adjust(DateTime(__DATE__, __TIME__));//Set Time, comment after using
  Serial.begin(9600);
  pinMode(button, OUTPUT);
}

void loop(){
  DateTime now = RTC.now();
  Serial.print(now.year(), DEC); Serial.print('/'); Serial.print(now.month(), DEC); Serial.print('/'); Serial.print(now.day(), DEC); Serial.print(' ');
  Serial.print(now.hour(), DEC); Serial.print(':'); Serial.print(now.minute(), DEC); Serial.print(':'); Serial.print(now.second(), DEC);
  Serial.println();
  act_hou=now.hour();
  act_min=now.minute();
  act_sec=now.second();
  if ((act_hou==det_h) && (act_min==det_m) && (act_sec==det_s)) button_puch(0);  
  //button_puch(1); //blinking button only test
  //button_puch(2); //one blink button only test
}

void button_puch(int p){
  if (p = 0){
    digitalWrite(button, HIGH); 
    Serial.println("Boton Pulsado!!!");
    delay(button_puch_time); 
    digitalWrite(button, LOW);
    delay(500);
  }
  if (p = 1){
    digitalWrite(button, HIGH); 
    Serial.println("Test Button ON!!!");
    delay(button_puch_time); 
    Serial.println("Test Button OFF!!!");
    digitalWrite(button, LOW);
    delay(button_puch_time); 
  }
  if (p = 2){
    digitalWrite(button, HIGH); 
    Serial.println("Test Button ON!!!");
    delay(button_puch_time); 
    Serial.println("Test Button OFF!!!");
    digitalWrite(button, LOW);
    delay(500); 
  }
}
