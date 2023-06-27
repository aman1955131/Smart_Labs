#include "ThingSpeak.h"
#include <ESP8266WiFi.h>
#include<SoftwareSerial.h>



SoftwareSerial nodemcu(D1,D2);///node to arduino//tx,rx
int statuscode;

//----------- Enter you Wi-Fi Details---------//
const char* ssid     = "HITAM_T14";
const char* password = "SsdcEEE@T14";
//-------------------------------------------//

//-------------------------------------------//

//----------- Channel Details -------------//
unsigned long Channel_ID =  2032292 ; // Channel ID
const char * WriteAPIKey = "85XDANANOYXX99Z0"; // Your write API Key
char * readapikey="RMRHICLQDJC8BF2K";//read api key
// ----------------------------------------//


long Time;
int x;
int i;

String bin_lvl;


const int Field_number = 3;
WiFiClient  client;

void setup()
{

  Serial.begin(9600);    //To begin the serial monitor
  nodemcu.begin(9600);
  
  WiFi.mode(WIFI_STA);//setting to the STATION mode
  ThingSpeak.begin(client);//To establish the communication with thingspeak
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);//establish connection with wifi
  while (WiFi.status() != WL_CONNECTED) {// check wheather the wifi is connected or not
    delay(500);
    Serial.print(".");
  }
 
}
void loop()
{

bin_lvl=nodemcu.readStringUntil('\r');
transfers();
upload();//calling the upload function
   
  
}
void upload()
{ 
  //delay(1500);
  x = ThingSpeak.writeField(Channel_ID, Field_number, bin_lvl, WriteAPIKey);//uploads the bin level to the thingspeak
 
}

void transfers(){
  statuscode=ThingSpeak.readMultipleFields(Channel_ID);
  if(statuscode==200){
    
    int bin1=ThingSpeak.readLongField(Channel_ID,1,readapikey);
//    int bin2=ThingSpeak.readLongField(Channel_ID,2,readapikey);
//    int bin3=ThingSpeak.readLongField(Channel_ID,5,readapikey);
//  String binc=String(bin1)+String(" ")+String(bin2)+String(" ")+String(bin3)+String(" ");
  String binc=String(bin1);

  Serial.println(binc);
  nodemcu.println(binc);
  
  //nodemcu.println(String(binc));
//  if(bin2>90 and bin1<90){
//    nodemcu.println("bin1 is "+String(bin1)+"%");
//    }
//    if(bin2>90 and bin3<90){
//    nodemcu.println("bin3 is "+String(bin3)+"%");
//    }


}
else{
 Serial.println("sss");
 Serial.println(statuscode);
 }
 
}
