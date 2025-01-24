void setup() {
  // put your setup code here, to run once:
pinMode(5,OUTPUT); //since we've connected the pin to D5

}

void loop() {
  // put your main code here, to run repeatedly:
  //to turn on led:
  digitalWrite(5,HIGH); //high is used to turn on the led
  delay(1000);//1000millisecond=1sec
  digitalWrite(5,LOW);//after blinking return to normal
  delay(1000);
}
