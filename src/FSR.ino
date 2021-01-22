const int sensorPin = A0;    // pin A0 associer au senseur fsr 1
const int sensorPin2 = A1;    // pin A1 associer au senseur fsr 2

// variables:
float sensorValue = 0;         // valeur du senseur fsr 1
float sensorValue2 = 0;         // vameur du senseur fsr 2

int sensorMin = 1023;        // valeur minimal des senseurs
int sensorMax = 0;           // valeur maximal des senseurs 
int sensorMax2 = 0;
  
int voltage; // valeur analogique converti en voltage
float resistance; // voltage converti en resistance
float  conductance; 
float force; // resistance converti en force (Newton)
float poids; // force converti en poids (kg)

int voltage2; // valeur analogique converti en voltage
float resistance2;  // voltage converti en resistance
float  conductance2; 
float force2; // resistance converti en force (Newton)
float poids2; // force converti en poids (kg)

void setup()
{
  Serial.begin(9600);
  pinMode(sensorPin, INPUT);  
  pinMode(sensorPin2, INPUT);


  // calibrate during the first five seconds
  while (millis() < 5000) {
    sensorValue = analogRead(sensorPin);
    sensorValue2 = analogRead(sensorPin2);
   
  }

}

void loop() {


  
  // lecture analogique des senseurs
  sensorValue = analogRead(sensorPin);
  sensorValue2 = analogRead(sensorPin2);

// Callibration du senseur
  sensorValue = map(sensorValue, sensorMin, sensorMax, 0, 1023);
  sensorValue2 = map(sensorValue2, sensorMin, sensorMax, 0, 1023);
  
  // Range de la valeur sensorValue lors de la callibration
  sensorValue = constrain(sensorValue, 0, 1023);
  sensorValue2 = constrain(sensorValue2, 0, 1023);

    //Serial.println("---------------------------------  CAPTEUR1  -----------------------------");


    voltage = map(sensorValue, 0, 1023, 0, 5000);
    //Serial.println("voltage");
    //Serial.println(voltage);
    //Serial.println();
      
    // voltage = Vcc * R / (R + FSR) ou R = 10K et Vcc = 5V
    // FSR = ( (Vcc - V) * R) / V
    // Voltage est en millivolts 5V = 5000mV
    resistance = 5000 - voltage;     
    resistance *= 10000; // 10K resistance
    resistance /= voltage; // FSR resistance en ohms.
    //Serial.println("resistance");
    //Serial.println(resistance);
    //Serial.println();
  
    conductance = 1000000; //mesure en (ohms).
    conductance /= resistance;
    //Serial.println("conductance");
    //Serial.println(conductance);
    //Serial.println();
   
    force = conductance / 80;
    force *= 19.5;
    //Serial.println("newton");
    //Serial.println(force);
    //Serial.println();
    
    poids = force / 9,81;
    //Serial.println("kg");
    Serial.println(poids);
    //Serial.println();

/********************************************/
  //  Serial.println("---------------------------------  CAPTEUR2  -----------------------------");
    //Serial.println("Analog2");
    //Serial.println(sensorValue2);
    //Serial.println();
  // calibration du capteur senseur
  
    voltage2 = map(sensorValue2, 0, 1023, 0, 5000);
    //Serial.println("voltage2");
    //Serial.println(voltage2);
    //Serial.println();
    
    resistance2 = 5000 - voltage2;     
    resistance2 *= 10000; // 10K resistance 
    resistance2 /= voltage2; // FSR resistance en ohms.
    //Serial.println("resistance2");
    //Serial.println(resistance2);
    //Serial.println();
    
    conductance2 = 1000000; //Mesure en (ohms).
    conductance2 /= resistance2;
    //Serial.println("conductance2");
    //Serial.println(conductance2);
   // Serial.println();

    force2 = conductance2 / 80;
    force2 *= 19.5;
    //Serial.println("newton2");
    //Serial.println(force2);
   // Serial.println();

    poids2 = force2 / 9,81;
    //Serial.println("kg");
    Serial.println(poids2);
   // Serial.println();
    
  delay(500);
}
