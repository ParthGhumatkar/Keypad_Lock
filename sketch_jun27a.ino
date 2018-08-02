#include <Key.h>
#include <Keypad.h>//https://github.com/Chris--A/Keypad
#include <LiquidCrystal.h> 

char* password ="0000";//Your password you can change it
//defining the keypad
const byte rows = 4; 
const byte cols = 4;

char keyMap [rows] [cols] = { 
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins [rows] = {1, 2, 3, 4};
byte colPins [cols] = {5, 6, 7, 8};

Keypad myKeypad = Keypad( makeKeymap(keyMap), rowPins, colPins, rows, cols);

LiquidCrystal lcd (A0, A1, A2, A3, A4, A5);//Pins for lcd

void setup(){

  lcd.begin(16, 2);
  setLocked (true); 
}

void loop(){
  char whichKey = myKeypad.getKey(); 
  lcd.setCursor(0, 1);
  lcd.print(" Enter Password");

  if(whichKey == '*' || whichKey == '#' || whichKey == 'A' ||  
  whichKey == 'B' || whichKey == 'C' || whichKey == 'D'){

    pozisyon=0;
    setLocked (true);// If you have put your wrong password
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Not Verified");
    delay(1000);
    lcd.clear();
  }
  if(whichKey == password [pozisyon]){

    pozisyon ++;
  }
  if(pozisyon == 4){
    setLocked (false);// If you have put your correct password
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("*** Verified ***");
    delay(10000);
    lcd.clear();
  }
  delay(100);
}




