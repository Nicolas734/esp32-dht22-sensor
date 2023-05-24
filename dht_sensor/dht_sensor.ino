#include "DHT.h"

#define DHTPIN 2
#define DHTTYPE DHT22

SemaphoreHandle_t mutex;
TaskHandle_t tTask1;

DHT dht(DHTPIN, DHTTYPE);
float umi;
float temp;

void setup() {
  Serial.begin(115200);
  Serial.println(F("\nIniciando coleta de dados"));
  dht.begin();
}


void loop() {
  delay(2000);
  umi = dht.readHumidity();
  temp = dht.readTemperature();
  if (isnan(umi) || isnan(temp)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }
  
  Serial.print("Umidade: ");
  Serial.println(umi);
  Serial.print("Temperatura: ");
  Serial.println(temp);
}
