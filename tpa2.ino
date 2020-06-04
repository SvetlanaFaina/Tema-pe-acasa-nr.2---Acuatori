#include "tpa2.h"

void setup() {
  Serial.begin(9600);
  RelaySetup();
  LDR_Setup();
}

void loop() {
  //======pentru monitorizare nivel iluminare
  Serial.println("Light points:");
  float l_value = LDRGetValue();
  Serial.println (l_value);
  Serial.println ();//pentru lizibilitate in serial

  //======Conectare Relay, daca este detectata miscarea si daca nivelul de iluminare este mai mic decit minimal
  if (PIR_Sensor() == 1) {
    Serial.println("Movment detected");
    if (LDRGetValue() < LIGHT_MIN) { //LIGHT_MIN 300 (analogic) = 100 in simulator proteus
      Serial.println("Light is under minimum livel");
      RelaySetValue(Relay_ON);
      Serial.println("Relay turns on");
      delay(200);
      Serial.println();
    } else {
      RelaySetValue(Relay_OFF);
      Serial.println("Relay turns off");
      delay(200);
    }
  } else {
    Serial.println("No motion detected");
    RelaySetValue(Relay_OFF);
    delay(200);
  }

}
