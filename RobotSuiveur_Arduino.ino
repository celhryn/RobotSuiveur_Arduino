// Créé par Celhryn
// Modification le 06/12/2023
// Version 0.1.0
// Documentation à 

// Pins du moteur
const int motorPin1 = 9;
const int motorPin2 = 8;
const int motorPin3 = 7;
const int motorPin4 = 6;

// Pins du capteur ultrasons
const int trigPin = 2;
const int echoPin = 3;

// Vitesse du moteur
int speed = 180;

void setup() {
  // Paramétrage des pins en mode SORTIE (OUTPUT)
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(motorPin3, OUTPUT);
  pinMode(motorPin4, OUTPUT);

  // Paramétrage des pins du capteur ultrasons
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  // Communication en série pour le débogage
  Serial.begin(9600);
}

float getDistance() {
  // Fonction pour mesurer la distance en utilisant le capteur ultrasons
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  return pulseIn(echoPin, HIGH) * 0.034 / 2;
}

void adjustMotors(float distance) {
  // Fonction pour ajuster la vitesse et la direction par rapport à la distance
  if (distance > 30) {
    analogWrite(motorPin1, speed);
    analogWrite(motorPin2, 0);
    analogWrite(motorPin3, speed);
    analogWrite(motorPin4, 0);
  } else if (distance < 20) {
    analogWrite(motorPin1, 0);
    analogWrite(motorPin2, speed);
    analogWrite(motorPin3, 0);
    analogWrite(motorPin4, speed);
  } else {
    analogWrite(motorPin1, speed);
    analogWrite(motorPin2, speed);
    analogWrite(motorPin3, speed);
    analogWrite(motorPin4, speed);
  }
}

void loop() {
  // Lire la distance depuis le capteur ultrasons
  float distance = getDistance();

  // Afficher la distance pour le débogage
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Ajuster la vitesse du moteur par rapport à la distance
  adjustMotors(distance);

  // Ajout d'un délai pour la stabilité
  delay(100);
}
