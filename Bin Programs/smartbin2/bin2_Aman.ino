//#include<SoftwareSerial.h>
//SoftwareSerial nodeserial(12,13);
#include<LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,20,4);
#include<Wire.h>
#include<Servo.h>



String data;
int trigpin = 9;
int pos;
int trig2=6;
int echo2=7;
int servopin=3;
int buzzer=13;
int duration=0;
int distance=0;
int duration1=0;
int status_lvl=0;
long avrg[3];
int lvl=0;
int status_level=0;
int count=0;

Servo myservo;

void setup(){
  Serial.begin(9600);
  //nodeserial.begin(115200);
  lcd.init();
  lcd.backlight();
  
  
  pinMode(trigpin,INPUT);
  
  pinMode(trig2,OUTPUT);
  pinMode(echo2,INPUT);
  pinMode(buzzer,OUTPUT);
  myservo.attach(servopin);

  
}
void loop()
{ 
  detect();
  op();
//lvl=98;
  if(lvl<90){
  Serial.println(lvl);//lvl
  delay(500);
  lcd.setCursor(0,0);
    lcd.println(String(lvl)+"% Filled");
  }
else{
Serial.println(String(lvl)+"-");//lvl
transfer();
}

}
void transfer(){
  if(Serial.available()){
    data=Serial.readStringUntil('\n');
    Serial.println(data+"kk");}
    
    lcd.setCursor(0,0);
    lcd.println(String(lvl)+"% Filled");
    lcd.setCursor(0,1);
    lcd.println("BIN1-"+ data+"%Filled");
}
