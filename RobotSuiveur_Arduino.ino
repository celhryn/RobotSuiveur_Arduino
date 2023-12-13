// Créé par Celhryn
// Modification le 06/12/2023
// Version 0.1.1
// Documentation à

// Pins du moteur
const int motorPin1 = 9;
const int motorPin2 = 8;
const int motorPin3 = 7;
const int motorPin4 = 6;

// Pins des capteurs ultrasons Gravity SEN0307
const int sensityPin1 = A0; //gauche
const int sensityPin2 = A1; //droite

// Vitesse du moteur
int speed = 180;

#define MAX_RANG (520)       // La valeur de mesure maximale du module est 520 cm (un peu plus longue que la plage maximale effective)
#define ADC_SOLUTION (1023.0) // La précision ADC de l'Arduino UNO est de 10 bits

void setup() {
  // Paramétrage des pins en mode SORTIE (OUTPUT)
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(motorPin3, OUTPUT);
  pinMode(motorPin4, OUTPUT);

  // Communication en série pour le débogage
  Serial.begin(9600);
}

// Fonction pour mesurer la distance en utilisant le capteur ultrasons Gravity SEN0307
float getDistance(int sensityPin) {
  // Lecture de la valeur analogique depuis le capteur
  float sensity_t = analogRead(sensityPin);
  // Calcul de la distance en cm
  float dist_t = sensity_t * MAX_RANG / ADC_SOLUTION;

  return dist_t;
}

// Fonction pour ajuster la vitesse et la direction par rapport à la distance
void adjustMotors(float distance1, float distance2) {
  // Distance cible (à calibrer en fonction de votre application)
  float targetDistance = 30.0;
  // Tolérance pour la direction
  float tolerance = 5.0;

  // Si le capteur de gauche ne capte rien, tourner à droite
  if (distance1 == 0) {
    analogWrite(motorPin1, speed);
    analogWrite(motorPin2, 0);
    analogWrite(motorPin3, 0);
    analogWrite(motorPin4, speed);
  }
  // Si le capteur de droite ne capte rien, tourner à gauche
  else if (distance2 == 0) {
    analogWrite(motorPin1, 0);
    analogWrite(motorPin2, speed);
    analogWrite(motorPin3, speed);
    analogWrite(motorPin4, 0);
  } else {
    // Calcul de la distance moyenne
    float averageDistance = (distance1 + distance2) / 2.0;

    // Ajustements en fonction de la distance moyenne
    if (averageDistance > targetDistance + tolerance) {
      // Si la distance est supérieure à la distance cible + tolérance, tourne à gauche
      analogWrite(motorPin1, 0);
      analogWrite(motorPin2, speed);
      analogWrite(motorPin3, speed);
      analogWrite(motorPin4, 0);
    } else if (averageDistance < targetDistance - tolerance) {
      // Si la distance est inférieure à la distance cible - tolérance, tourne à droite
      analogWrite(motorPin1, speed);
      analogWrite(motorPin2, 0);
      analogWrite(motorPin3, 0);
      analogWrite(motorPin4, speed);
    } else {
      // Si la distance est dans la plage de +/- tolérance autour de la distance cible, avance tout droit
      analogWrite(motorPin1, speed);
      analogWrite(motorPin2, 0);
      analogWrite(motorPin3, speed);
      analogWrite(motorPin4, 0);
    }
  }
}

void loop() {
  // Lire les distances depuis les capteurs ultrasons Gravity SEN0307
  float distance1 = getDistance(sensityPin1);
  float distance2 = getDistance(sensityPin2);

  // Afficher les distances pour le débogage
  Serial.print("Distance gauche: ");
  Serial.print(distance1);
  Serial.print(" cm, Distance droite: ");
  Serial.print(distance2);
  Serial.println(" cm");

  // Ajuster la vitesse du moteur par rapport à la distance
  adjustMotors(distance1, distance2);

  // Ajout d'un délai pour la stabilité
  delay(900);
}
