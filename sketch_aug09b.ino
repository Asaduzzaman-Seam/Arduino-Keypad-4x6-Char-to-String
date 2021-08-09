#include <Keypad.h>
const byte ROWS = 4; /* four rows */
const byte COLS = 6; /* four columns */
/* define the symbols on the buttons of the keypads */
char Keys[ROWS][COLS] = {
  {'C','7','8','9','*','/'},
  {'D','4','5','6','-','M'},
  {'P','1','2','3','+','n'},
  {'R','0','.','=','+','q'}
};
byte rowPins[ROWS] = {2,3,4,5}; /* connect to the row pinouts of the keypad */
byte colPins[COLS] = {6,7,8,9,10,11}; /* connect to the column pinouts of the keypad */

/* initialize an instance of class NewKeypad */
Keypad customKeypad = Keypad( makeKeymap(Keys), rowPins, colPins, ROWS, COLS); 

void setup(){
Serial.begin(9600);
}

void loop(){
  Serial.print("Key : ");
  char customKey = customKeypad.waitForKey();
  String customKeyS = keyPadButton(customKey);
  if (customKeyS){
    Serial.println(customKeyS);
  }
  
}

String keyPadButton(char x)
{
  String y;
  if('0' == x){y = "0"; return y;}
  if('1' == x){y = "1"; return y;}
  if('2' == x){y = "2"; return y;}
  if('3' == x){y = "3"; return y;}
  if('4' == x){y = "4"; return y;}
  if('5' == x){y = "5"; return y;}
  if('6' == x){y = "6"; return y;}
  if('7' == x){y = "7"; return y;}
  if('8' == x){y = "8"; return y;}
  if('9' == x){y = "9"; return y;}
  if('*' == x){y = "*"; return y;}
  if('/' == x){y = "/"; return y;}
  if('+' == x){y = "+"; return y;}
  if('-' == x){y = "-"; return y;}
  if('C' == x){y = "ON/C"; return y;}
  if('=' == x){y = "="; return y;}
  if('.' == x){y = "."; return y;}
  if('R' == x){y = "Root"; return y;}
  if('n' == x){y = "M-"; return y;}
  if('q' == x){y = "M+"; return y;}
  if('M' == x){y = "MRC"; return y;}
  if('D' == x){y = "+/-"; return y;}
  if('P' == x){y = "%"; return y;}
}
