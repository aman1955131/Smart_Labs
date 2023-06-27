int level(){
  digitalWrite(trig2,LOW);
  delayMicroseconds(5);
  digitalWrite(trig2,HIGH);
  delayMicroseconds(15);
  digitalWrite(trig2,LOW);
  duration1=pulseIn(echo2,HIGH);
  status_level=(duration1/2)/29.1;
  //Serial.println("2nd sensor");
  //Serial.println(status_lvl);
  return status_level;
}
void op(){
  
  if(distance==LOW and status_lvl>=8){
    //Serial.println("open");
    myservo.attach(servopin);
    //for(pos=0;pos<=90;pos++){
      myservo.write(90);
      //
    delay(6000);
    for(pos=90;pos>=0;pos--){
      myservo.write(pos);
      delay(15);
    }
//    myservo.write(90);
//    delay(5000);
//    myservo.write(0);
    lcd.clear();
    I2C();
    
    //cap();
  }
  
  else if(distance==LOW and status_lvl<8){
//    myservo.write(0);
//    myservo.detach();
    lcd.clear();
    I2C();
    tone(buzzer,1500);
    delay(1000);
    noTone(buzzer);
    delay(1000);
    //Serial.println("close");
    
    
  }
  else if(distance==HIGH){
    myservo.write(0);
    delay(1000);
    myservo.detach();
  }
}
