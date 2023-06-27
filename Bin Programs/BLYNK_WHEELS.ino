#define BLYNK_PRINT Serial



/* Fill-in your Template ID (only if using Blynk.Cloud) */

#define BLYNK_TEMPLATE_ID "TMPL3uibYZNoe"
#define BLYNK_TEMPLATE_NAME "LabAutomation"
#define BLYNK_AUTH_TOKEN "s2291g1WHa7xVg5Sz8MD1Kx2nJ_BfwpL"
#include <ESP8266WiFi.h>

#include <BlynkSimpleEsp8266_SSL.h>



// You should get Auth Token in the Blynk App.

// Go to the Project Settings (nut icon).
 
//char auth[] = "s2291g1WHa7xVg5Sz8MD1Kx2nJ_BfwpL";
char auth[] = "AiI0iw1zg8kV6IN9lErjEOwyw6yDIySo";



// Your WiFi credentials.

// Set password to "" for open networks.

char ssid[] = "OP";

char pass[] = "98764321";



int enA = D1; //GPIO1
int enB = D6; //GPIO12

int in1 = D2;  //GPIO5

int in2 = D3;  //GPIO4

int in3 = D4;  //GPIO0

int in4 = D5;  //GPIO2



int pinValue1;

int pinValue2;
const int trig =D7;
const int echo =D8;
int distance;
int duration;


BLYNK_WRITE(V2)
{
int buttonState = param.asInt();
  if(buttonState == HIGH ){
    Blynk.virtualWrite(V3,0);
  Blynk.virtualWrite(V4,0);
  Blynk.virtualWrite(V5,0);
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);
  

}
else{
  digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,LOW);
  
  }
}



BLYNK_WRITE(V3)
{

//back
int buttonState = param.asInt();
  if(buttonState==HIGH){
  Blynk.virtualWrite(V2,0);
  Blynk.virtualWrite(V4,0);
  Blynk.virtualWrite(V5,0);
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
 

}
else{
  digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,LOW);
  
  }
}

BLYNK_WRITE(V4)
{
//  left
int buttonState = param.asInt();
  if(buttonState==HIGH){
    Blynk.virtualWrite(V2,0);
  Blynk.virtualWrite(V3,0);
  Blynk.virtualWrite(V5,0);
//  digitalWrite(in1,HIGH);
//  digitalWrite(in2,LOW);
//  digitalWrite(in3,LOW);
//  digitalWrite(in4,LOW);
digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);


}
else{
  digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,LOW);
  
  }


}
BLYNK_WRITE(V5)
{
//  right
int buttonState = param.asInt();
  if(buttonState==HIGH){
  Blynk.virtualWrite(V2,0);
  Blynk.virtualWrite(V3,0);
  Blynk.virtualWrite(V4,0);
//  digitalWrite(in1,LOW);
//  digitalWrite(in2,LOW);
//  digitalWrite(in3,LOW);
//  digitalWrite(in4,HIGH);
digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);


}
else{
  digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,LOW);
  }
}
BLYNK_WRITE(V6){
  int buttonState =param.asInt();
  if(buttonState == HIGH){
    Blynk.virtualWrite(V2,0);
    Blynk.virtualWrite(V3,0);
    Blynk.virtualWrite(V4,0);
    Blynk.virtualWrite(V5,0);
     digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,LOW);
   Blynk.virtualWrite(V6,0);

    
    }
  
}
void setup()

{
  // Debug console
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,LOW);
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  analogWrite(enA, 255);
  analogWrite(enB,255);
   pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);

}



void loop()

{ 
 detect();
 if(distance<15){
  Blynk.virtualWrite(V2,0);
  int i=0;
  while (i<150){
    
    digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);
  Serial.println(i);
   i++;
  }
 
   digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,LOW);
  
  }
  
Blynk.run();

}
void detect(){
  digitalWrite(trig,LOW);
  delayMicroseconds(5);
  digitalWrite(trig,HIGH);
  delayMicroseconds(15);
  digitalWrite(trig,LOW);
  duration=pulseIn(echo,HIGH);
  distance=(duration/2)/29.1;
//  Serial.println(distance);
  }
