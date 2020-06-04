#ifndef Sensori

#define Sensori

//OUT PIR sensor to PIN 3
#define PIR_PIN 3

//Relay stari si valori
#define Relay_MAX 1
#define Relay_MIN 0
#define Relay_ON 1
#define Relay_OFF 0

//Relay pin to PIN A0
#define Relay_PIN A0

//LDR pin to PIN A1
#define LDR_PIN A1

//minimal value of analog read for LDR
#define LIGHT_MIN 300 //valoare minima pentru sensor iluminare

//setup si functia Relay
void RelaySetup (); //initierea port (pini)
void RelaySetValue (int R_value);

//setup si functia LDR
void LDR_Setup(); //initierea port
float LDRGetValue ();

//setup si functia PIR Sensor
void PIR_Setup(); //initiere port
int PIR_Sensor();

#endif
