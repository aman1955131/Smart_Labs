void measure()
{
digitalWrite(trigPin2, LOW); //sets the triger to low
delayMicroseconds(5);//delay of 5microseconds
digitalWrite(trigPin2, HIGH);//sets the trigger to high
delayMicroseconds(15);
digitalWrite(trigPin2, LOW);
pinMode(echoPin2, INPUT);
duration2 = pulseIn(echoPin2, HIGH);//reads the echo and stores in duration2
dist2 = (duration2/2) / 29.1;    //obtain distance

}
