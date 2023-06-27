void I2C(){
  for(int j=0;j<3;j++){
    avrg[j]=level();
  }
  status_lvl=(avrg[0]+avrg[1]+avrg[2])/3;
  //Serial.println(status_lvl);
  if(status_lvl>=34){
    lvl=0;
    lcd.setCursor(2,0);
    lcd.println("0% filled");
    
    }
   else if(status_lvl==33){
    lvl=1;
    lcd.setCursor(2,0);
    lcd.println("1%Filled");
    
   }
    else if(status_lvl==32){
    lvl=2;
    lcd.setCursor(2,0);
    lcd.println("2%Filled");
    
   }
    else if(status_lvl==31){
    lvl=3;
    lcd.setCursor(2,0);
    lcd.println("3%Filled");
    
   }
    else if(status_lvl==30){
    lvl=5;
    lcd.setCursor(2,0);
    lcd.println("5%Filled");
    
   }
    else if(status_lvl>=28 and status_lvl<=29){
    lvl=10;
    lcd.setCursor(2,0);
    lcd.println("10%Filled");
    
   }
   
    else if(status_lvl==27){
    lvl=15;
    lcd.setCursor(2,0);
    lcd.println("15%Filled");
    
   }
    else if(status_lvl==26){
    lvl=20;
    lcd.setCursor(2,0);
    lcd.println("20%Filled");
    
   }
    else if(status_lvl==25){
    lvl=25;
    lcd.setCursor(2,0);
    lcd.println("25%Filled");
    
   }
    else if(status_lvl==24){
    lvl=30;
    lcd.setCursor(2,0);
    lcd.println("30%Filled");
    
   }
    else if(status_lvl>=22 and status_lvl<24){
    lvl=35;
    lcd.setCursor(2,0);
    lcd.println("35%Filled");
    
   }
    else if(status_lvl>=20 and status_lvl<22){
    lvl=40;
    lcd.setCursor(2,0);
    lcd.println("40%Filled");
    
   }
    else if(status_lvl>=18 and status_lvl<20){
    lvl=45;
    lcd.setCursor(2,0);
    lcd.println("45%Filled");
    
   }
    else if(status_lvl>=16 and status_lvl<18){
    lvl=50;
    lcd.setCursor(2,0);
    lcd.println("50%Filled");
    
   }
    else if(status_lvl>=14 and status_lvl<16){
    lvl=55;
    lcd.setCursor(2,0);
    lcd.println("55%Filled");
    
   }
    else if(status_lvl>12 and status_lvl<14){
    lvl=60;
    lcd.setCursor(2,0);
    lcd.println("60%Filled");
    
   }
    else if(status_lvl==12){
    lvl=65;
    lcd.setCursor(2,0);
    lcd.println("65%Filled");
    
   }
    else if(status_lvl>10 and status_lvl<12){
    lvl=70;
    lcd.setCursor(2,0);
    lcd.println("70%Filled");
    
   }
    else if(status_lvl==10){
    lvl=75;
    lcd.setCursor(2,0);
    lcd.println("75%Filled");
    
   }
    else if(status_lvl==9){
    lvl=80;
    lcd.setCursor(2,0);
    lcd.println("80%Filled");
    
   }
    else if(status_lvl==8){
    lvl=85;
    lcd.setCursor(2,0);
    lcd.println("85%Filled");
    
   }
    else if(status_lvl>=6 and status_lvl<8){
    lvl=90;
    lcd.setCursor(2,0);
    lcd.println("90%Filled");
    
   } else if(status_lvl>=4 and status_lvl<6){
    lvl=95;
    lcd.setCursor(2,0);
    lcd.println("95%Filled");
   
    
   }
    else if(status_lvl>0 and status_lvl<4){
    lvl=100;
    lcd.setCursor(2,0);
    lcd.println("100%Filled");
    
    
   }
   
   
   
   //Serial.println(lvl);
   
   
}
