
#include <Adafruit_MLX90614.h>
#include<Wire.h>
#include <TFT.h>  
#include <SPI.h>
#include<stdlib.h>
Adafruit_MLX90614 mlx = Adafruit_MLX90614();
#define cs   10
#define dc   9
#define rst  8
#define relay 2

const int textWidth = 100; 
const int scrollSpeed = 1; 
const int trigPin = 5;
const int echoPin = 6;
long duration;
int distance;

float hb_bytes;
float spo2_bytes;
String message;
String part1;
String part2;
String tempValue;
int val1;
int val2;
TFT TFTscreen = TFT(cs, dc, rst);
void TCA9548A(uint8_t bus){
 Wire.beginTransmission(0x70);
 Wire.write(1<<bus);
 Wire.endTransmission();
}

void setup() {
  Serial.begin(9600);
  Wire.begin();
  pinMode(relay,OUTPUT);
   TFTscreen.begin();
// clear the screen with a black background
  TFTscreen.background(0, 0, 0);
  //set the text size
  TFTscreen.setTextSize(2);
  while (!Serial);
  TCA9548A(0);
  if (!mlx.begin()) {
    Serial.println("Error connecting to MLX sensor. Check wiring.");
    while (1);
  };
   pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT); 
      digitalWrite(relay,HIGH);

}

void loop() {
  
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
//  Serial.println(distance);
 


//max30100();
  if(distance>8){
     if(Serial.available()>=0){
  message=Serial.readStringUntil('\n');
  }
    
 
   
int screen_width = TFTscreen.width();
int screen_height = TFTscreen.height();
TFTscreen.fillRect(0, 0, screen_width, screen_height, TFTscreen.Color565(0, 0, 0));
   int redRandom = (255, 255,255);
// set a random font color
  TFTscreen.stroke(redRandom);
  splitString(message.c_str(),"-");
  TFTscreen.text("hb",6,10);
  TFTscreen.text(part1.c_str(), 71, 20);
  TFTscreen.text("spo2",6,40);
  TFTscreen.text(part2.c_str(), 71, 60);
//  TFTscreen.text("objectC", 6, 80); // Display the converted string on the TFT screen
//  TFTscreen.text(tempValue.c_str(), 71, 100);
  
  delay(500);
  }
//  else if(val1>0 and val2>0){
//    max30100();
//    }
  else{
    digitalWrite(relay,LOW);
    delay(3000);
    digitalWrite(relay,HIGH);
    
    TCA9548A(0);
    tempValue=mlx.readObjectTempF();
float tempValues=atof(tempValue.c_str())+3.00;
String  tempValuesF=String(tempValues);
    Serial.println(tempValues);
   
    
     int screen_width = TFTscreen.width();
     int screen_height = TFTscreen.height();
     TFTscreen.fillRect(0, 0, screen_width, screen_height, TFTscreen.Color565(0, 0, 0));
     int redRandom = (255, 255,255);
     TFTscreen.stroke(redRandom);
//      TFTscreen.text("HITAM  ", 70,10 );
//      TFTscreen.text("SSDC  ", 70,50 );
//      TFTscreen.text("EEE ", 70,90 );
 TFTscreen.text("objectF ", 6, 80); // Display the converted string on the TFT screen
  TFTscreen.text(tempValuesF.c_str(), 71, 100);
  delay(3000);
      }
  delay(1000);
}

void max30100(){
  if(Serial.available()>=0){
  message=Serial.readStringUntil('\n');
  splitString(message.c_str(),"-");
  val1=atoi(part1.c_str());
  val2=atoi(part2.c_str());

  }
  maxDisplay();
}
void maxDisplay(){
int screen_width = TFTscreen.width();
int screen_height = TFTscreen.height();
TFTscreen.fillRect(0, 0, screen_width, screen_height, TFTscreen.Color565(0, 0, 0));
   int redRandom = (255, 255,255);  
// set a random font color
  TFTscreen.stroke(redRandom);
  splitString(message.c_str(),"-");
  TFTscreen.text("hb",6,10);
  TFTscreen.text(part1.c_str(), 71, 20);
  TFTscreen.text("spo2",6,40);
  TFTscreen.text(part2.c_str(), 71, 60);
  
  
  }

void splitString(String input, String delimiter) {
  int delimiterIndex = input.indexOf(delimiter);
  part1 = input.substring(0, delimiterIndex);
  part2 = input.substring(delimiterIndex + 1);
}
