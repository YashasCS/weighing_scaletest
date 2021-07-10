#include "HX711.h"


// HX711 circuit wiring
const int LOADCELL_DOUT_PIN = 5;
const int LOADCELL_SCK_PIN = 4;


HX711 scale;

void setup() {
  Serial.begin(9600);
  Serial.println("Initializing the scale");


  scale.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);

  Serial.println("Before setting up the scale:");
  Serial.print("read: \t\t");
  Serial.println(scale.read());      

  Serial.println("\nPut 4000 gram in the scale, press a key to continue");
  while(!Serial.available());
  while(Serial.available()) Serial.read();

  scale.callibrate_scale(4000, 5);
  Serial.print("UNITS: ");
  Serial.println(scale.get_units(10),3);

  Serial.println("\nScale is calibrated");
}

void loop() {
  Serial.print("\t| average:\t");
  Serial.println(scale.get_units(10));
  delay(250);

 
}
