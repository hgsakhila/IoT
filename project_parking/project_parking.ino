#include <LiquidCrystal.h>
#include <LiquidCrystal_I2C.h>// You may also need to include the Wire library
#include <Adafruit_I2CDevice.h>

Adafruit_I2CDevice i2c_dev = Adafruit_I2CDevice(0x10);


#define IR_SENSOR_A 18
#define IR_SENSOR_B 19


LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display
#define BUZZER 9

int flag=0;
void setup()
{
  Serial.begin(115200);
  flag=0;
  lcd.begin();                      // initialize the lcd 
  pinMode(BUZZER,OUTPUT);
  lcd.backlight();
  pinMode(18,INPUT);
  pinMode(19,INPUT); 
  
  lcd.clear();

 lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Welcm 2 Parking mall"); 
}

void loop()
{
  int p1=digitalRead(18);
  int p2=digitalRead(19);

  String msg="";
  
  lcd.setCursor(0,1);
  
  if( p1==0 && p2==0 )
  {
  msg="Av:No slots        ";
  }
  else if( p1==1 && p2==0)
  {
    msg=" Av:Slot B         ";
    
    if( flag==0){
    digitalWrite(BUZZER,HIGH);
    delay(50);
    digitalWrite(BUZZER,LOW);
    flag=1;}
  }
    
  else if( p1==0 && p2==1){
  msg="Av:Slot A         ";

  if(flag==0){
  digitalWrite(BUZZER,HIGH);
  delay(50);
  digitalWrite(BUZZER,LOW);
  flag=1;
  }
  }
  else if( p1==1 && p2==1 ){
  msg="Av:Slot A and B   ";
  flag=0;
  }

  Serial.println(msg);
 lcd.print(msg);
  Serial.println(p1,p2);
  delay(500);
}
