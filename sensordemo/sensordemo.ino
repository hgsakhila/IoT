#define SOIL 33

void setup() {
  // put your setup code here, to run once:
  pinMode(SOIL,INPUT);
  Serial.begin(115200);//speed at which the board communicates with laptop

}

void loop() {
  // put your main code here, to run repeatedly:
  int soil=analogRead(SOIL); //read data from sensor... type digital read if the board will be connected to [see google once]
  Serial.println(soil);
 

  if(soil==4095)
  {
    Serial.println("Sensor is not inserted");
  }
  else if(soil<=1200)
   {
    Serial.println("Soil is wet");
  }
  
  else if(soil>=1200 && soil<3500)
   {
    Serial.println("Soil is moderately wet");
  }
  else if(soil>3500 && soil<4095)
   {
    Serial.println("Soil is dry");
  }

   delay(500);

}
