
#include <SPI.h>
#include <MFRC522.h>
#include <TimeLib.h>

#define SS_PIN 10 
#define RST_PIN 9

MFRC522 mfrc522(SS_PIN, RST_PIN); 
String card_ID=""; 

//Add as many cards you want 
String Name1="89 48 C9 2F";
String Name2="12122112947";
String Name3="15353114169";
String Name4="13937143185";
String Name5="79 DD 81 2F";
String Name6="89 48 C9 2F";

int NumbCard[6];
int j=0;  
int statu[6];
int s=0;  

int const RedLed=6;
int const GreenLed=5;
int const Buzzer=8;

String Log;
String Name;
long Number;
int n ;
int ID=1;
void setup() {
  setTime(20,0,0,3,30,2019);
  Serial.begin(9600);
  SPI.begin();  
  mfrc522.PCD_Init(); 
  
  Serial.println("CLEARSHEET");                
  Serial.println("LABEL,ID,Date,Name,Number,Card ID,Time IN,Time OUT");
  pinMode(RedLed,OUTPUT);
  pinMode(GreenLed,OUTPUT);
  pinMode(Buzzer,OUTPUT);
  setTime(20,0,0,3,30,2019);
  

  delay(200);
   }
   
void loop() {
  
   if ( ! mfrc522.PICC_IsNewCardPresent()) {
  return;
 }
 
 if ( ! mfrc522.PICC_ReadCardSerial()) {
  return;
 }

 for (byte i = 0; i < mfrc522.uid.size; i++) {
     card_ID += mfrc522.uid.uidByte[i];
 }
 
 Serial.println(card_ID);
 
       if(card_ID==Name1){
       Name="First employee";
       Number="79 DD 81 2F";
       j=0;
       s=0;
      }
      else if(card_ID==Name2){
       Name="Second employee";
       Number=789101;
       j=1;
       s=1;
      }
      else if(card_ID==Name3){
       Name="Third employee";
       Number=789101;
       j=2;
       s=2;
      }
      else if(card_ID==Name4){
       Name="Fourth employee";
       Number=789101;
       j=3;
       s=3;
      }
      else if(card_ID==Name5){
       Name="Fiveth employee";
       Number=789101;
       j=4;
       s=4;
      }
      else if(card_ID==Name6){
       Name="Sixth employee";
       Number=789101;
       j=5;
       s=5;
      }
      else{
          digitalWrite(GreenLed,LOW);
          digitalWrite(RedLed,HIGH);
          goto cont;
     }

      if(NumbCard[j] == 1 && statu[s] == 0){
      statu[s]=1;
    
      Serial.print("DATA,");
      Serial.print(ID);
      Serial.print(",");
      Serial.print("DATE");
      Serial.print(",");
      Serial.print(Name);
      Serial.print(",");
      Serial.print(Number); 
      Serial.print(",");
      Serial.print(card_ID); 
      Serial.print(",");
      Serial.print("");
      Serial.print(",");
      Serial.println("TIME");
      ID=ID+1;
      digitalWrite(GreenLed,HIGH);
      digitalWrite(RedLed,LOW);
      digitalWrite(Buzzer,HIGH);
      delay(30);
      digitalWrite(Buzzer,LOW);
      }
      else if(NumbCard[j] == 0){
      NumbCard[j] = 1;
      
      n++;
    
      Serial.print("DATA,");
      Serial.print(ID);
      Serial.print(",");
      Serial.print("DATE");
      Serial.print(",");
      Serial.print(Name);
      Serial.print(",");
      Serial.print(Number); 
      Serial.print(",");
      Serial.print(card_ID); 
      Serial.print(",");
      Serial.print("TIME");
      Serial.print(",");
      Serial.println("");
      digitalWrite(GreenLed,HIGH);
      digitalWrite(RedLed,LOW);
      digitalWrite(Buzzer,HIGH);
      delay(30);
      digitalWrite(Buzzer,LOW);
      ID=ID+1;
      }
      else if(statu[s] == 1){
     
      }
      delay(1000);
     
cont:
delay(2000);
digitalWrite(GreenLed,LOW);
digitalWrite(RedLed,LOW);
card_ID="";

}
    void printTime() {
  Serial.print(hour());
  Serial.print(":");
  Serial.print(minute());
  Serial.print(":");
  Serial.print(second());
  Serial.print(",");
}
    
