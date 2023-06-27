void lcd_display()
{
 lcd.clear();//clears the lcd screen
if ( dist2>45 ) {
  lcd.setCursor(0, 0);//seting the cursor to 0*0
  per=0;
  lcd.println("0% FILLED");//display the value on lcd
  
  
}
else if ( (dist2>42)&& (dist2<=45)) {
   lcd.setCursor(0, 0);
  per=5;
  lcd.println("0% FILLED");
}
else if ( (dist2>41)&& (dist2<=42) ) {
  lcd.setCursor(0, 0);
 per=10;
  
  lcd.println("0% FILLED");
}
else if ((dist2>39)&& (dist2<=41)) {
   lcd.setCursor(0, 0);
  per=15;

  lcd.println("15% FILLED");
}
else if ( (dist2>37)&& (dist2<39) ) {
   lcd.setCursor(0, 0);
  per=20;

  lcd.println("20% FILLED");
}
else if ( (dist2>35)&& (dist2<=37) ) {
   lcd.setCursor(0, 0);
  per=25;
  lcd.println("25% FILLED");
}
else if ( (dist2>33)&& (dist2<=35) ) {
  per=30;
  
  lcd.println("30% FILLED");
  
}
else if ( (dist2>31)&& (dist2<=33) ) {
   lcd.setCursor(0, 0);
  per=35;
   
  lcd.println("35% FILLED");
  
}
else if ( (dist2>29)&& (dist2<=31)) {
   lcd.setCursor(0, 0);
  per=40;
  lcd.println("40% FILLED");
}
else if ( (dist2>27)&& (dist2<=29) ) {
   lcd.setCursor(0, 0);
   per=45;
   
  lcd.println("45% FILLED");
}
else if ( (dist2>25)&& (dist2<=27)) {
   lcd.setCursor(0, 0);
  per=50;
  
  lcd.println("50% FILLED");
}
else if ( (dist2>23)&& (dist2<=25) ) {
  per=55;
   
  lcd.println("55% FILLED");
}
else if( (dist2>20)&& (dist2<=23) ) {
   lcd.setCursor(0, 0);
 per=60;
  lcd.println("60% FILLED");
}
else if( (dist2>18)&& (dist2<=20) ) {
   lcd.setCursor(0, 0);
  per=65;
  lcd.println("65% FILLED");
}
else if( (dist2>15)&& (dist2<=18) ) {
   lcd.setCursor(0, 0);
  per=70;
  lcd.println("70% FILLED");
}
else if( (dist2>13)&& (dist2<=15) ) {
   lcd.setCursor(0, 0);
  per=75;
  lcd.println("75% FILLED");
}
else if( (dist2>11)&& (dist2<=13) ) {
   lcd.setCursor(0, 0);
  per=80;
  lcd.println("80% FILLED");
}
else if( (dist2>9)&& (dist2<=11) ) {
   lcd.setCursor(0, 0);
  per=85;

  lcd.println("85% FILLED");
}
else if( (dist2>6)&& (dist2<=9) ) {
   lcd.setCursor(0, 0);
  per=90;
  lcd.println("90% FILLED");
}
else if( (dist2>3)&& (dist2<=6) ) {
   lcd.setCursor(0, 0);
  per=95;
   
  lcd.println("95% FILLED");
}
else if( (dist2>0)&& (dist2<=3) ) {
   lcd.setCursor(0, 0);
  per=100;
  lcd.println("100% FILLED");
}


}
