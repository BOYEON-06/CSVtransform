#include "Adafruit_CCS811.h"
 
Adafruit_CCS811 ccs;
 
void setup() {
  Serial.begin(9600);
 
  Serial.println("CCS811 test");
 
  if(!ccs.begin()){
    Serial.println("Failed to start sensor! Please check your wiring.");
    while(1);
  }
 
  // Wait for the sensor to be ready
  while(!ccs.available());
  delay(5000);
}
 
void loop() {
  if(ccs.available()){
    if(!ccs.readData()){
      Serial.print(" ");
      Serial.println(ccs.getTVOC());
    }
    else{
      Serial.println("ERROR!");
      while(1);
    }
  }
  delay(500);
}
