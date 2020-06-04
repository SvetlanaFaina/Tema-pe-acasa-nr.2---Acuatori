#include "tpa2.h"
#include "Arduino.h"

//=== sectiune Relay setare si functii =====
int relayCurrentState;
void RelaySetup() {
  pinMode(Relay_PIN, OUTPUT);//setare pin ca iesire
}

//pentru a aplica semnal doar pina cind releul sa ajunga in starea de care avem nevoie? Cine o sa-i dea o alta valoare?
//pentru a converti valoarea mai mare decit maxima, in cea maximala permisa
//iar pentru o valoare mai mica decit cea minimala - voloarea va fi setata ca cea minimala
void RelaySetValue (int R_value) {
  if (R_value > Relay_MAX) {
    //limita la val. maxima
    R_value = Relay_MAX;
  }
  else if (R_value < Relay_MIN) {
    //limitare la val. minim
    R_value = Relay_MIN;
  }

  //daca valoarea R_value nu este 0, deci este 1 - reley conectat
  if (R_value != Relay_OFF) {
    digitalWrite (Relay_PIN, HIGH);
  } else {
    digitalWrite (Relay_PIN, LOW);
  }
  relayCurrentState = R_value;
}

//=====sectiune LDR setare si functii=======
void LDR_Setup() {
  pinMode(LDR_PIN, INPUT); //setare pin ca intrare
}

//primire valoare sensor lumina //am renuntat la float si map, pentru ca conversia in Proteus, imi dadea doar 4 valori: 10, 28, 46 si 64
//probabil ca sa mearga trebuia de aplicat o formula
float LDRGetValue() {
  int rawData = analogRead(LDR_PIN);
  return rawData;//light;
}

//=====sectiune PIR setare si functii=======
void PIR_Setup() {
  pinMode(PIR_PIN, INPUT);//setare pin ca intrare
}

int PIR_Sensor() {
  int PIR_Status = digitalRead (PIR_PIN);//poate avea doar doua valori, 1 sau 0
  return PIR_Status;
}
