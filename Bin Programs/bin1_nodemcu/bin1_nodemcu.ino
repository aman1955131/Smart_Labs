//--------Blynk details-----//
#define BLYNK_TEMPLATE_ID "TMPLdh7XFakW"
#define BLYNK_DEVICE_NAME "SmartBin"
#define BLYNK_AUTH_TOKEN "UgLbiwEl86tnMjHUZpVwNZXUA56ccyxr"

#define BLYNK_PRINT Serial

#include "ThingSpeak.h"
#include <ESP8266WiFi.h>
#include<SoftwareSerial.h>
#include <BlynkSimpleEsp8266.h>
SoftwareSerial serialcom(D1,D2);




char auth[] = BLYNK_AUTH_TOKEN;
BlynkTimer timer;


//----------- Enter you Wi-Fi Details---------//
const char* ssid     = "HITAM_EEE";
const char* password = "hitam@2023";
//-------------------------------------------//

//-------------------------------------------//

//----------- Channel Details -------------//
unsigned long Channel_ID = 1717065 ; // Channel ID
const char * WriteAPIKey = "OPNVLQYQLK5KDB7V"; // Your write API Key
// ----------------------------------------//


long Time;
int x;
int i;

String bin_lvl;
   
const int Field_number = 1;
WiFiClient  client;

BLYNK_CONNECTED()
{
  // Change Web Link Button message to "Congratulations!"
  Blynk.setProperty(V3, "offImageUrl", "https://static-image.nyc3.cdn.digitaloceanspaces.com/general/fte/congratulations.png");
  Blynk.setProperty(V3, "onImageUrl",  "https://static-image.nyc3.cdn.digitaloceanspaces.com/general/fte/congratulations_pressed.png");
  Blynk.setProperty(V3, "url", "https://docs.blynk.io/en/getting-started/what-do-i-need-to-blynk/how-quickstart-device-was-made");
}
/*BLYNK_WRITE(V0)
{
  // Set incoming value from pin V0 to a variable
  //int value = param.asInt();
  // Update state
  //for(int value=0; value<=200;value++){
  //Blynk.virtualWrite(V1, value);
  //delay(500);}
}*/
void myTimerEvent()
{
  // You can send any value at any time.
  // Please don't send more that 10 values per second.
 // Blynk.virtualWrite(V2,millis() / 1000);
}
void label(){
  
  Blynk.virtualWrite(V1,bin_lvl); // updates the VirtualPin V1 
}
void check(){
  label();
  alert();
}
void setup()
{

  Serial.begin(115200);    //To begin the serial monitor
  serialcom.begin(9600);  //To establish serial communication
  Blynk.begin(auth, ssid, password); //establish communication with the blynk 
  timer.setInterval(1000L, myTimerEvent);//Sets the timmer
  WiFi.mode(WIFI_STA);//setting to the STATION mode
  ThingSpeak.begin(client);//To establish the communication with thingspeak

  delay(2500);
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
  //internet();
  //measure();
  Blynk.run();//It updates all the blynk commands
  timer.run();//Starts the timmer
  check();
  bin_lvl=serialcom.readStringUntil('\r');//Reads the string from the serial communication

  Serial.print("Garbage Level:");
  Serial.print(bin_lvl);
  Serial.println("%");
    upload();//calling the upload function
  
}
void upload()
{
  x = ThingSpeak.writeField(Channel_ID, Field_number, bin_lvl, WriteAPIKey);//uploads the bin level to the thingspeak
 
}
void alert(){
  if( bin_lvl>"90"){
    Blynk.virtualWrite(V0,1);//trigger the virtul pin V0 if bin level is greater than 90
    
  }
  else{
    Blynk.virtualWrite(V0,0);//if bin level is less than 90 then virtual pin set to 0
    }
}
