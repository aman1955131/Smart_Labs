void detect_ir()
{
val=digitalRead(sensor);//reading the IR sensor value

if ((val==LOW)&&(dist2<=3)){
  servo.write(0);//bring the servo to intial position
  servo.detach();
  lcd_display(); //calling the lcd function
  //bin1.println(10);
  tone(buzzer, 1800); //rings the buzzer at 1800 frequency
  delay(1000); 
  noTone(buzzer);//tops ringing buzzer
  delay(1000);
         // ...for 1 sec
  
}
else if (( val==LOW )&&(dist2>3)) {
//Change distance as per your need
 servo.attach(servoPin);
  delay(1);      
 servo.write(75);//sets the servo to 150 degree
 lcd_display(); 
 //bin1.println(20); 
 delay(3000); 
      
}
else if (val!=LOW){
  for(pos=75; pos>=0;pos--){
  servo.write(pos);
  delay(15);
  }
  delay(1000);
  servo.detach();
}

}
