#include <HX711.h>
HX711 scale;

void setup() {
  Serial.begin(9600);
  
  Serial.println("Initializing the scale");
  // HX711.DOUT  - pin #A1
  // HX711.PD_SCK - pin #A0
  scale.begin(A1, A0);

  scale.set_scale(202.75f);
  scale.tare();
}

void loop() {
  long  value = static_cast<long >(scale.get_units() * 10000.0 );    
  long current_time = millis();
  Serial.print(current_time);
  Serial.print(",");
  Serial.print(value);
  Serial.println(",done.");
}

