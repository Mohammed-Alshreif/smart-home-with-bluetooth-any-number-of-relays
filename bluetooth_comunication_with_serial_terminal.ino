#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2); 


#include <SoftwareSerial.h>
SoftwareSerial myserial (3,2) ;// bluetooth : Tx = 3 , Rx = 2  


char rx_byte;
String rx_str = "";
bool set_switchs[16]={HIGH,HIGH,HIGH,HIGH,HIGH,HIGH,HIGH,HIGH,HIGH,HIGH,HIGH,HIGH,HIGH,HIGH,HIGH,HIGH};


#define ser 4
#define latch 5
#define clk 6
void setup() {
 Serial.begin(9600);
 myserial.begin(9600); 
 
 lcd.init();                      // initialize the lcd 
  lcd.init();
 lcd.backlight();

 pinMode (ser, OUTPUT);
 pinMode (latch, OUTPUT);
 pinMode (clk, OUTPUT);
 

}

void loop() {
 if(myserial.available() )
  {
     rx_byte = myserial.read();   
    Serial.write(rx_byte ); 
       
    if (rx_byte != '\n') {
      rx_str += rx_byte;
    }
      else {
      
      rx_str.replace(rx_str.substring(rx_str.length()-1), ""); //remove last caracter in string "/0"
       lcd.setCursor(0,0);
      lcd.print(rx_str );lcd.print("            ");// print the data on lcd 
       
      //lcd.setCursor(rx_str.length()-1,0); lcd.print("            "); if yo donot remove last char.
      
      // ===============================================  control ========================

    
      
  if(rx_str.equals("switch1 on")){set_switchs[0]=LOW;}else if(rx_str.equals("switch1 off")){set_switchs[0]=HIGH;} 
  if(rx_str.equals("switch2 on")){set_switchs[1]=LOW;}else if(rx_str.equals("switch2 off")){set_switchs[1]=HIGH;} 
  if(rx_str.equals("switch3 on")){set_switchs[2]=LOW;}else if(rx_str.equals("switch3 off")){set_switchs[2]=HIGH;} 
  if(rx_str.equals("switch4 on")){set_switchs[3]=LOW;}else if(rx_str.equals("switch4 off")){set_switchs[3]=HIGH;} 
  if(rx_str.equals("switch5 on")){set_switchs[4]=LOW;}else if(rx_str.equals("switch5 off")){set_switchs[4]=HIGH;} 
  if(rx_str.equals("switch6 on")){set_switchs[5]=LOW;}else if(rx_str.equals("switch6 off")){set_switchs[5]=HIGH;} 
  if(rx_str.equals("switch7 on")){set_switchs[6]=LOW;}else if(rx_str.equals("switch7 off")){set_switchs[6]=HIGH;} 
  if(rx_str.equals("switch8 on")){set_switchs[7]=LOW;}else if(rx_str.equals("switch8 off")){set_switchs[7]=HIGH;} 
  if(rx_str.equals("switch9 on")){set_switchs[8]=LOW;}else if(rx_str.equals("switch9 off")){set_switchs[8]=HIGH;} 
if(rx_str.equals("switch10 on")){set_switchs[9]=LOW;}else if(rx_str.equals("switch10 off")){set_switchs[9]=HIGH;} 
if(rx_str.equals("switch11 on")){set_switchs[10]=LOW;}else if(rx_str.equals("switch11 off")){set_switchs[10]=HIGH;} 
if(rx_str.equals("switch12 on")){set_switchs[11]=LOW;}else if(rx_str.equals("switch12 off")){set_switchs[11]=HIGH;} 
if(rx_str.equals("switch13 on")){set_switchs[12]=LOW;}else if(rx_str.equals("switch13 off")){set_switchs[12]=HIGH;} 
if(rx_str.equals("switch14 on")){set_switchs[13]=LOW;}else if(rx_str.equals("switch14 off")){set_switchs[13]=HIGH;}
if(rx_str.equals("switch15 on")){set_switchs[14]=LOW;}else if(rx_str.equals("switch15 off")){set_switchs[14]=HIGH;} 
if(rx_str.equals("switch16 on")){set_switchs[15]=LOW;}else if(rx_str.equals("switch16 off")){set_switchs[15]=HIGH;} 
if(rx_str.equals("all on")){for(int i=0;i<16;i++){set_switchs[i]=LOW;}}
else if(rx_str.equals("all off")){for(int i=0;i<16;i++){set_switchs[i]=HIGH;}} 
digitalWrite(latch,LOW);
digitalWrite(clk,LOW);
digitalWrite(clk,HIGH);

digitalWrite(ser, set_switchs[0]);//////////1
digitalWrite(clk,LOW);
digitalWrite(clk,HIGH);
digitalWrite(ser,set_switchs[1]);//////////2
digitalWrite(clk,LOW);
digitalWrite(clk,HIGH);
digitalWrite(ser,set_switchs[2]);//////////3
digitalWrite(clk,LOW);
digitalWrite(clk,HIGH);
digitalWrite(ser,set_switchs[3]);//////////4
digitalWrite(clk,LOW);
digitalWrite(clk,HIGH);
digitalWrite(ser,set_switchs[4]);//////////5
digitalWrite(clk,LOW);
digitalWrite(clk,HIGH);
digitalWrite(ser,set_switchs[5]);//////////6
digitalWrite(clk,LOW);
digitalWrite(clk,HIGH);
digitalWrite(ser,set_switchs[6]);//////////7
digitalWrite(clk,LOW);
digitalWrite(clk,HIGH);
digitalWrite(ser,set_switchs[7]);//////////8
digitalWrite(clk,LOW);
digitalWrite(clk,HIGH);
digitalWrite(ser,set_switchs[8]);//////////9
digitalWrite(clk,LOW);
digitalWrite(clk,HIGH);
digitalWrite(ser,set_switchs[9]);//////////10
digitalWrite(clk,LOW);
digitalWrite(clk,HIGH);
digitalWrite(ser,set_switchs[10]);//////////11
digitalWrite(clk,LOW);
digitalWrite(clk,HIGH);
digitalWrite(ser,set_switchs[11]);//////////12
digitalWrite(clk,LOW);
digitalWrite(clk,HIGH);
digitalWrite(ser,set_switchs[12]);//////////13
digitalWrite(clk,LOW);
digitalWrite(clk,HIGH);
digitalWrite(ser,set_switchs[13]);//////////14
digitalWrite(clk,LOW);
digitalWrite(clk,HIGH);
digitalWrite(ser,set_switchs[14]);//////////15
digitalWrite(clk,LOW);
digitalWrite(clk,HIGH);
digitalWrite(ser,set_switchs[15]);//////////16
digitalWrite(clk,LOW);
digitalWrite(clk,HIGH);

digitalWrite(ser,LOW);//
digitalWrite(latch,HIGH);
      //================================================end control ===================== 
      
      rx_str = "";  lcd.print("            ");   // select    rx_str =""        
     
    }
    
}
    
    if (Serial.available () )
    {
      myserial.write(Serial.read() );
    }
             
}
