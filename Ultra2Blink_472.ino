// Sensor 1
const int trigPin1 = 5;
const int echoPin1 = 4;
// Sensor 2
const int trigPin2 = 3;
const int echoPin2 = 2;

// 6 LEDs on pins 6, 7, 8, 9, 10, 11
int ledPins[] = {8, 9, 10, 11, 12, 13};
int numLeds = 6;

float duration, distance1, distance2;

void setup() {
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  
  // Initialize all LED pins as outputs
  for (int i = 0; i < numLeds; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
  
  Serial.begin(9600);
  // Helps make the "random" actually random
  randomSeed(analogRead(0)); 
}

void loop() {
  // --- READ SENSOR 1 ---
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);
  duration = pulseIn(echoPin1, HIGH);
  distance1 = (duration * .0343) / 2;

  delay(50); // Gap to prevent acoustic interference

  // --- READ SENSOR 2 ---
  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);
  duration = pulseIn(echoPin2, HIGH);
  distance2 = (duration * .0343) / 2;

  // --- SERIAL OUTPUT ---
  Serial.print("S1: "); Serial.print(distance1);
  Serial.print(" cm | S2: "); Serial.print(distance2);
  Serial.println(" cm");

  // --- LED LOGIC ---
  // If either sensor detects something closer than 50cm
  if ((distance1 > 0 && distance1 < 50) || (distance2 > 0 && distance2 < 50)) {
    int randomLed = random(0, numLeds); // Pick a random LED index
    
    digitalWrite(ledPins[randomLed], HIGH); // Turn it on
    delay(500);                              // Short blink
    digitalWrite(ledPins[randomLed], LOW);  // Turn it off
  } else {
    // Ensure all LEDs stay off if no one is close
    for (int i = 0; i < numLeds; i++) {
      digitalWrite(ledPins[i], LOW);
    }
  }

  delay(50); 
}
