// Define the analog pin connected to the moisture sensor
#define SOILPIN A0   // Soil moisture sensor connected to A0

// Define 3 vibration motors
const int VIB1 = 3;
const int VIB2 = 5;
const int VIB3 = 6;

void setup() {
  // Initialize motor pins as outputs
  pinMode(VIB1, OUTPUT);
  pinMode(VIB2, OUTPUT);
  pinMode(VIB3, OUTPUT);
  
  // Initialize serial communication for monitoring values
  Serial.begin(9600);
}

void loop() {

  int moisture = analogRead(SOILPIN);  // Read soil moisture

  Serial.println(moisture);  // For calibration

  if (moisture < 900) // wet
  {
    digitalWrite(VIB1, HIGH);  // turn the MOTOR on (HIGH is the voltage level)
    digitalWrite(VIB2, HIGH);  // turn the MOTOR on (HIGH is the voltage level)
    digitalWrite(VIB3, HIGH);  // turn the MOTOR on (HIGH is the voltage level)
  }
 
  // If else (800 or above), they are off
  else {
    digitalWrite(VIB1, LOW);  // turn the MOTOR off by making the voltage LOW
    digitalWrite(VIB2, LOW);  // turn the MOTOR off by making the voltage LOW
    digitalWrite(VIB3, LOW);  // turn the MOTOR off by making the voltage LOW
  }

  delay(1000);
}

