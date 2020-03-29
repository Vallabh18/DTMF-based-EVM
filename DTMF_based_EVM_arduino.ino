
 #include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
const int Q1 = 10;  // Defining Digital Input Pins from DTMF Module
const int Q2 = 9;
const int Q3 = 8;
const int Q4 = 7;
const int stQ= 13;

int SoQ1 = 0;     // Defining variable to store the status(HIGH/LOW) of above inputs.
int SoQ2 = 0;
int SoQ3 = 0;
int SoQ4 = 0;
int oldCon = 0;  //  Variable to know what was the last button pressed.  

void setup(){ 
  pinMode(Q1, INPUT);  // Defining pins as input.
  pinMode(Q2, INPUT);
  pinMode(Q3, INPUT);
  pinMode(Q4, INPUT);
    lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.setCursor(0,0);
  lcd.print("Welcome Voters");
  delay(4000);
  lcd.setCursor(0,1);
  lcd.print("DTMF based EVM");
  delay(4000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("enter your vote");
  delay(2000);
  lcd.setCursor(0,1);
  lcd.print("1:BJP");
  delay(2000);
  lcd.setCursor(0,1);
   lcd.print("2:Cong");
   delay(2000);
   lcd.setCursor(0,1);
   lcd.print("3:shivsena");
   delay(2000);
   lcd.clear();
   Serial.begin(9600);   // Setup Serial Communication.               
  Serial.print("DTMF based EVM");  
  Serial.print("Let's Vote for the Change");
}

void loop(){
  SoQ1 = digitalRead(Q1);  // Reading status of Input Pins. It can be LOW or HIGH
  SoQ2 = digitalRead(Q2);
  SoQ3 = digitalRead(Q3);
  SoQ4 = digitalRead(Q4);
  
  if(SoQ4==LOW && SoQ3==LOW && SoQ2==LOW && SoQ1==HIGH )   // Condition for Button 1. It is equal to Binary - 0001 
  {
    if (oldCon!=1)
    {                                       // Here we are testing that what was the last pressed button, 
//We want actions to be done when current is not as the lastone.
       Serial.println("1");
       lcd.clear();
       lcd.setCursor(0,0);
       lcd.print("BJP");
       delay(2000);
       // Your Action goes here.                         // You can add your set of action here.  
    }
    oldCon=1;
  }  
  else if(SoQ4==LOW && SoQ3==LOW && SoQ2==HIGH && SoQ1==LOW )  // Condition for Button 2. It is equal to Binary - 0010 
    {
      if (oldCon!=2){
         Serial.println("2");
         // Your Action goes here.
          lcd.clear();
       lcd.setCursor(0,0);
       lcd.print("Congress");
       delay(2000);  
       }
      oldCon=2;  
    }
  else if(SoQ4==LOW && SoQ3==LOW && SoQ2==HIGH && SoQ1==HIGH )  // Condition for Button 3. It is equal to Binary - 0011 
    {
      if (oldCon!=3){
         Serial.println("3");
         // Your Action goes here.
          lcd.clear();
       lcd.setCursor(0,0);
       lcd.print("Shivsena");
       delay(2000);  
       }
      oldCon=3;  
    }

    
delay(50);   // Debounce Delay.
  
}


 
