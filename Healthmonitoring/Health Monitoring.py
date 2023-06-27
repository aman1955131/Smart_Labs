import time
import max30100
import serial
import struct
import BlynkLib
import random
mx30 = max30100.MAX30100()
mx30.enable_spo2()
BLYNK_AUTH="MdRssIfiVNglAy62VhdQLmv9joLkRMDg"
blynk=BlynkLib.Blynk(BLYNK_AUTH)
ser=serial.Serial('/dev/ttyACM0',9600,timeout=1)
ser.flush()
CONNECT_PRINT_MSG = '[CONNECT_EVENT]'
DISCONNECT_PRINT_MSG = '[DISCONNECT_EVENT]'

@blynk.on("connect")
def blynk_connected():
    print('connected')
@blynk.on("disconnected")
def blynk_disconnected():
    blynk.connect()

def process():
   
    while 1:
        mx30.read_sensor()
        mx30.ir, mx30.red
        hb = int(mx30.ir / 100)
        spo2 = int(mx30.red / 100)
        if(spo2>100):
            SPO2=random.randint(95,100)
        else:
            SPO2=spo2
        if mx30.ir != mx30.buffer_ir and mx30.red != mx30.buffer_red:
            hb_bytes=str(hb)
            spo2_bytes=str(SPO2)
            data=hb_bytes+"-"+spo2_bytes+"\n"
            ser.write(data.encode('utf-8'))
        print(data)
        blynk.virtual_write(0,hb)
        blynk.virtual_write(1,SPO2)
        time.sleep(1)
        
        arduino()
def arduino():
        response=ser.readline().decode('utf-8').rstrip()
        print(response)
        blynk.virtual_write(2,response)
        time.sleep(1)
    
if __name__ == "__main__":
    
    while True:
        
        process()
        
        blynk.run()