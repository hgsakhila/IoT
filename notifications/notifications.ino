/*******

  This is a simple demo of sending and receiving some data.
  Be sure to check out other examples!
 *******/

/* Fill-in information from Blynk Device Info here */
#define BLYNK_TEMPLATE_ID           "TMPL3PEqYfzzX"
#define BLYNK_TEMPLATE_NAME         "Quickstart Device"
#define BLYNK_AUTH_TOKEN            "U0G54Rvw61-p_XkY9NEQXG-EwD5WSr3y"

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>


#include "DHT.h"

#define DHTPIN 27   
#define DHTTYPE DHT11   // DHT 11
// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "Akhila";
char pass[] = "iowp4337";

BlynkTimer timer;

DHT dht(DHTPIN, DHTTYPE);
// This function is called every time the Virtual Pin 0 state changes
BLYNK_WRITE(V0)
{
  // Set incoming value from pin V0 to a variable
  int value = param.asInt();

  // Update state
  //Blynk.virtualWrite(V1, value);

  if( value==1 )
  {
    digitalWrite(26,LOW);
  }
  else
  {
    digitalWrite(26,HIGH);
  }
}

// This function is called every time the device is connected to the Blynk.Cloud
BLYNK_CONNECTED()
{
  // Change Web Link Button message to "Congratulations!"
  Blynk.setProperty(V3, "offImageUrl", "https://static-image.nyc3.cdn.digitaloceanspaces.com/general/fte/congratulations.png");
  Blynk.setProperty(V3, "onImageUrl",  "https://static-image.nyc3.cdn.digitaloceanspaces.com/general/fte/congratulations_pressed.png");
  Blynk.setProperty(V3, "url", "https://docs.blynk.io/en/getting-started/what-do-i-need-to-blynk/how-quickstart-device-was-made");
}

// This function sends Arduino's uptime every second to Virtual Pin 2.
void myTimerEvent()
{
  // You can send any value at any time.
  // Please don't send more that 10 values per second.
  //Blynk.virtualWrite(V2, millis() / 1000);

  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();


if (isnan(h) || isnan(t) ) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

   

    Blynk.virtualWrite(V2, h);
    Blynk.virtualWrite(V1, t);
    
//    int soil=analogRead(SOIL );
//
//   if( soil>3500 && soil <4095 )
//    {
//      Blynk.logEvent("alert","Soil is dry,irrigate");  
//    }
}

void setup()
{
  // Debug console
  Serial.begin(115200);
  pinMode(26,OUTPUT);  //realy
  pinMode(33,INPUT);   // soil moisture
  dht.begin();
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  // You can also specify server:
  //Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass, "blynk.cloud", 80);
  //Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass, IPAddress(192,168,1,100), 8080);

  // Setup a function to be called every second
  timer.setInterval(1000L, myTimerEvent);

  Blynk.logEvent("alert_demo","Soil is dry,irrigate");  
}

void loop()
{
  Blynk.run();
  timer.run();
  // You can inject your own code or combine it with other sketches.
  // Check other examples on how to communicate with Blynk. Remember
  // to avoid delay() function!
}
