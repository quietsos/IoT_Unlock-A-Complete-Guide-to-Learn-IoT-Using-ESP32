/*
 Md Shohanuzzaman
 IoT Engineer @ IoT Lab
 DHT Sensor Library: https://github.com/adafruit/DHT-sensor-library
 Adafruit Unified Sensor Lib: https://github.com/adafruit/Adafruit_Sensor
*/


#include "DHT.h"

#define DHTPIN 18     // Digital pin connected to the DHT sensor


// Uncomment Which Sensor  you're using!

//#define DHTTYPE DHT11   // DHT 11
#define DHTTYPE DHT22   // DHT 22  




// Initialize DHT sensor.
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  Serial.println(F("DHT22 test!"));

  dht.begin();
}

void loop() {
  
  delay(2000);

  
  float h = dht.readHumidity();                   // reading humidity
  float t = dht.readTemperature();                // Read temperature as Celsius (the default)
  float f = dht.readTemperature(true);            // Read temperature as Fahrenheit (isFahrenheit = true)


  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  
  float hif = dht.computeHeatIndex(f, h);         // Compute heat index in Fahrenheit (the default)
  float hic = dht.computeHeatIndex(t, h, false);  // Compute heat index in Celsius (isFahreheit = false)

  Serial.print(F("Humidity: "));
  Serial.print(h);
  Serial.print(F("%  Temperature: "));
  Serial.print(t);
  Serial.print(F("°C "));
  Serial.print(f);
  Serial.print(F("°F  Heat index: "));
  Serial.print(hic);
  Serial.print(F("°C "));
  Serial.print(hif);
  Serial.println(F("°F"));
}
