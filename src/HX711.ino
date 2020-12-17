    #include "HX711.h"
     
    HX711 capteur;
    int DAT = 3;
    int CLK = 2;
    long valeur;
     
    void setup() { 
      capteur.begin(DAT,CLK);
      Serial.begin(9600);
      Serial.println("HX711");
    }
     
    void loop() {
      valeur = capteur.read_average(10);
      Serial.print("Valeur mesurée : ");
      Serial.println(valeur);
      delay(1000);
    }
