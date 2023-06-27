 #include <Adafruit_LiquidCrystal.h>
#include <Servo.h>   //servo library
#include <LiquidCrystal.h>
Servo servo;     
int sensor=8;// pir sensor connected to the arduino pin
int state=LOW;
int val=0;
int per=0;
int trigPin2 = 10;
int echoPin2 = 9;
int servoPin = 7;
const int buzzer=13;
int pos;
long duration2, dist2, average2;

long aver2[3];
#include "Wire.h"
#include "Adafruit_LiquidCrystal.h"
Adafruit_LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {       
    Serial.begin(9600);//begin serial monitor
    servo.attach(servoPin);  //attaching the servo
     
    pinMode(sensor, INPUT);
    pinMode(trigPin2, OUTPUT);  
    pinMode(echoPin2, INPUT);  
    servo.write(0);         //close cap on power on
    pinMode(buzzer, OUTPUT); 
    delay(100);
    servo.detach(); 
     lcd.begin(16, 2);//begins LCD 16*2
} 

void loop() { 
  
//Serial.print("dist2 :");

  

for (int i=0;i<=2;i++) {   //average distance
    measure();               
   aver2[i]=dist2;            
    delay(10);              //delay between measurements
  }
  dist2=(aver2[0]+aver2[1]+aver2[2])/3;
  Serial.println(per);
  
   

 
  
/*IR SENSOR*/
  detect_ir();

}
