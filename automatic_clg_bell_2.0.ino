#include <Wire.h>
#include "RTClib.h"
#include<LiquidCrystal.h>
#define relay 13               //relay switch pin
#define sw 5                 //mode switch pin

RTC_DS1307 rtc;
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

void shbell();                  //relay on function for 5 secs bell
void longbell();                //relay on function for 7 secs bell
void medbell();                 //relay on function for 10 secs bell
void off();                     //relay on function for NO bell


int mode = 1;   // counter for the number of button presses
int buttonState = 0;         // current state of the button
int lastButtonState = 0; 


void setup () {


  Serial.begin(9600);
  Wire.begin();
  rtc.begin();
  pinMode(relay, OUTPUT);
  pinMode(sw, INPUT);
  digitalWrite(sw,HIGH);

  lcd.begin(16, 2); // 16x2 LCD
  lcd.clear(); // blank the display

}//setup ends here


void loop (){

  DateTime now = rtc.now();
 // rtc.adjust(DateTime(2018, 3, 16, 10, 59, 0));
  //Calculate date/time
  int hh = now.hour();
  int mm = now.minute();
  int ss = now.second();
  int yr = (now.year(), DEC);
  int mt = (now.month(), DEC);
  int dd = (now.day(), DEC);




  //Print Current Date/TIme and mode
  lcd.setCursor(0, 0);
  lcd.print(hh);
  Serial.print(hh);
  lcd.setCursor(2, 0);
  lcd.print(":");
  Serial.print(":");
  lcd.setCursor(3, 0);
  lcd.print(mm);
  Serial.print(mm);
  lcd.setCursor(5, 0);
  lcd.print(":");
  Serial.print(";");
  lcd.setCursor(6, 0);
  lcd.print(ss);
  Serial.print(ss);
 // lcd.setCursor(8, 0);
 // lcd.print(dd);
 // Serial.print(dd);
 // lcd.setCursor(10, 0);
 // lcd.print("/");
 // Serial.print("/");
 // lcd.setCursor(11, 0);
 // lcd.print(mt);
 // Serial.print(mt);
 // lcd.setCursor(13, 0);
 // lcd.print("/");
 // Serial.print("/");
 // lcd.setCursor(14, 0);
 // lcd.print(yr);
 /// Serial.print(yr);
 

  //Mode Change Code for push button press
  
  buttonState = digitalRead(sw);
  if (buttonState != lastButtonState) {
    if (buttonState == HIGH)
    {
     if(mode!=9)
        {mode++;}
     else
     {mode=1;}; 
    }
    }
    
    delay(50);
    lastButtonState = buttonState;



//Mode Definition with preset times
  switch (mode) {
    case 1:
    //lcd.setCursor(0, 0); 
    //lcd.print("                ");   //Clears LCD Second Line since I found some residual text remaining 
 //  lcd.autoscroll();
 lcd.clear();
    lcd.setCursor(0, 1);
            lcd.print("Midsem Morning"); 
            Serial.println("Midsem Morning");
      {
        if (hh == 10 && mm == 00 && ss==0)
          longbell();
        else if (hh == 10 && mm == 30 && ss==0)
          longbell();
        else if (hh == 10 && mm == 45 && ss==0)
          shbell();
        else if (hh == 11 && mm == 00 && ss==0)
          longbell();
               else
        off();
      }
        
      break;

    case 2:
   // lcd.setCursor(0, 0); 
   // lcd.print("                ");
   lcd.clear();
   lcd.setCursor(0, 1); 
   // lcd.autoscroll();
      lcd.print("Midsem Morning Maths/EG");
      
    //  lcd.print("Maths/EG");
      Serial.println("Midsem Morning Maths/EG");
      {if (hh == 10 && mm == 00 && ss==0)
          longbell();
        else if (hh == 10 && mm == 30 && ss==0)
          longbell();
        else if (hh == 10 && mm == 45 && ss==0)
          shbell();
        else if (hh == 11 && mm == 00 && ss==0)
          shbell();
          else if (hh == 11 && mm == 15 && ss==0)
          longbell();
               else
        off();}
      break;

    case 3: //lcd.setCursor(0, 0); 
    //lcd.print("                ");
   // lcd.autoscroll();
   lcd.clear();
    lcd.setCursor(0, 1);
     lcd.print("Midsem Evening");
     Serial.println("Midsem Evening");
      {
         if (hh == 14 && mm == 00 && ss==0)
          longbell();
        else if (hh == 14 && mm == 30 && ss==0)
          longbell();
        else if (hh == 15 && mm == 15 && ss==0)
          shbell();
        else if (hh == 15 && mm == 45 && ss==0)
          longbell();
               else
        off();
      }
       
      break;

    case 4: 
    lcd.clear();
    lcd.setCursor(0, 0); 
   // lcd.print("                ");
  // lcd.autoscroll();
   lcd.setCursor(0, 1);
    lcd.print("Midsem Evening Maths/EG");
    
    //lcd.print("Maths/EG");
    Serial.println("Midsem Evening Maths/EG");
      {
         if (hh == 14 && mm == 00 && ss==0)
          longbell();
        else if (hh == 14 && mm == 30 && ss==0)
          longbell();
        else if (hh == 15 && mm == 15 && ss==0)
          shbell();
        else if (hh == 15 && mm == 45 && ss==0)
          shbell();
           else if (hh == 16 && mm == 00 && ss==0)
          longbell();
               else
        off();
      }
       
      break;
      case 5:
   // lcd.setCursor(0, 1); 
   // lcd.print("                ");          //Clears LCD Second Line since I found some residual text remaining 
  lcd.clear();
  lcd.setCursor(0, 1);
  //  lcd.autoscroll();
            lcd.print("GTU Morning"); 
            Serial.println("GTU Morning");
      {
         if (hh == 10 && mm == 00 && ss==0)
          longbell();
        else if (hh == 10 && mm == 30 && ss==0)
          longbell();
        else if (hh == 11 && mm == 30 && ss==0)
          shbell();
        else if (hh == 12 && mm == 45 && ss==0)
          shbell();
           else if (hh == 13 && mm == 00 && ss==0)
          longbell();
               else
        off();
      }
        
      break;
      case 6:
   // lcd.setCursor(0, 1); 
   // lcd.print("                ");          //Clears LCD Second Line since I found some residual text remaining 
   // lcd.setCursor(0, 0);
    //lcd.autoscroll();
    lcd.clear();
    lcd.setCursor(0, 1);
            lcd.print("GTU Morning Maths/EG"); 
             
           // lcd.print("Maths/EG");
            Serial.println("GTU Morning Maths/EG");
      {
         if (hh == 10 && mm == 00 && ss==0)
          longbell();
        else if (hh == 10 && mm == 30 && ss==0)
          longbell();
        else if (hh == 11 && mm == 30 && ss==0)
          shbell();
        else if (hh == 12 && mm == 45 && ss==0)
          shbell();
           else if (hh == 13 && mm == 00 && ss==0)
          shbell();
          else if (hh == 13 && mm == 30 && ss==0)
          longbell();
               else
        off();
      }
        
      break;
      case 7:
   // lcd.setCursor(0, 1); 
   // lcd.print("                ");          //Clears LCD Second Line since I found some residual text remaining 
    //lcd.setCursor(0, 0);
   // lcd.autoscroll();
   lcd.clear();
      lcd.setCursor(0, 1);
lcd.print("GTU Evening"); 
                       //lcd.print("Maths/EG");
            Serial.println("GTU Evening");
      {
         if (hh == 14 && mm == 00 && ss==0)
          longbell();
        else if (hh == 14 && mm == 30 && ss==0)
          longbell();
        else if (hh == 15 && mm == 30 && ss==0)
          shbell();
        else if (hh == 16 && mm == 45 && ss==0)
          shbell();
          
          else if (hh == 17 && mm == 00 && ss==0)
          longbell();
               else
        off();
      }
        
      break;
      case 8:
   // lcd.setCursor(0, 1); 
   // lcd.print("                ");          //Clears LCD Second Line since I found some residual text remaining 
    //lcd.setCursor(0, 0);
    //lcd.autoscroll();
    lcd.clear();
    lcd.setCursor(0, 1);
            lcd.print("GTU Evening Maths/EG"); 
             
      //      lcd.print("Maths/EG");
            Serial.println("GTU Evening Maths/EG");
      {
         if (hh == 14 && mm == 00 && ss==0)
          longbell();
        else if (hh == 14 && mm == 30 && ss==0)
          longbell();
        else if (hh == 15 && mm == 30 && ss==0)
          shbell();
        else if (hh == 16 && mm == 45 && ss==0)
          shbell();
          else if (hh == 17 && mm == 00 && ss==0)
          shbell();
          else if (hh == 17 && mm == 30 && ss==0)
          longbell();
               else
        off();
      }
        
      break;
       case 9:
       lcd.clear();
    lcd.setCursor(0, 1); 
   // lcd.print("                ");          //Clears LCD Second Line since I found some residual text remaining 
   // lcd.setCursor(0, 0);
   // lcd.autoscroll();
            lcd.print("Regular Classes First Shift"); 
       //      lcd.setCursor(0, 1);
         //   lcd.print("First Shift");
            Serial.println("Regular Classes First Shift");
      {
         if (hh == 8 && mm == 00 && ss==0)
          medbell();
        if (hh == 8 && mm == 50 && ss==0)
          medbell();
          if (hh == 9 && mm == 40 && ss==0)
          medbell();
          if (hh == 9 && mm == 50 && ss==0)
          longbell();
          if (hh == 10 && mm == 40 && ss==0)
          medbell();
          if (hh == 11 && mm == 30 && ss==0)
          medbell();
          if (hh == 12 && mm == 00 && ss==0)
          longbell();
          if (hh == 12 && mm == 50 && ss==0)
          medbell();
          if (hh == 1 && mm == 40 && ss==0)
          longbell();
          
               else
        off();
      }
        
      break;
  }//switch statement ends here



}//loop ends here
void shbell()
{ digitalWrite(relay, 1);           //Switches relay on
   delay(5000);                     //waits for 5 seconds 
  digitalWrite(relay, 0);           //switches relay off
  
}

void medbell()
{
  digitalWrite(relay, 1);           //Switches relay on
   delay(7000);                     //waits for 7 seconds 
  digitalWrite(relay, 0);           //switches relay off
  
 }

void longbell()
{
  digitalWrite(relay, 1);           //Switches relay on
   delay(10000);                     //waits for 10 seconds 
  digitalWrite(relay, 0);           //switches relay off
  
  
}
void off()
{ digitalWrite(relay, LOW);
}
