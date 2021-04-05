//Author    Matias Araya
//Workgroup N2
#include <Wire.h> 
#include "RTClib.h"
#define button 7
RTC_DS1307 RTC;

const int button_puch_time=5000;    //3 sec to push
const int det_h=11;                  //start Hour, range 0 - 23
const int det_m=8;                 //start Minute, range 0 - 59
const int det_s=0;                 //start Second, range 0 - 59

int act_hou;
int act_min;
int act_sec;

void setup () {
  Wire.begin();
  RTC.begin();
  //RTC.adjust(DateTime(__DATE__, __TIME__)); Serial.println('Date setting enabled'); //Set Time, comment after using
  Serial.begin(9600);
  delay(30);
  pinMode(button, OUTPUT);
  //button_puch(); //one press on start, only test
}

void loop(){
  DateTime now = RTC.now();
  Serial.println(GetTime());
  act_hou=now.hour();
  act_min=now.minute();
  act_sec=now.second();
  if ((act_hou==det_h) && (act_min==det_m) && (act_sec==det_s)) button_puch();  
  //if ((act_sec==det_s)) button_puch();  
}

void button_puch(){
  Serial.println("INI puch **********************************");
  digitalWrite(button, HIGH); 
  Serial.print(GetTime() + " Button ON!!!");
  Serial.println();
  delay(button_puch_time); 
  Serial.println(GetTime() + " Button OFF!!!");
  digitalWrite(button, LOW);
  delay(500);
  Serial.println("END puch **********************************");
}


String GetTime(){
  DateTime now = RTC.now();
  String TM = String(now.year(), DEC) + '/' + String(now.month(), DEC) + '/' + String(now.day(), DEC) + ' ' + 
              String(now.hour(), DEC) + ':' + String(now.minute(), DEC) + ':' + String(now.second(), DEC);
  return TM;
}
