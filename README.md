# RobotSuiveur_Arduino

## Rapport de programmation d’un Robot suiveur de personnes
Utilisation d’un capteur à ultrasons pour détecter la distance entre le robot et la personne à suivre. En fonction de cette distance, le robot ajuste sa vitesse et sa direction pour maintenir une distance optimale.

Voici le code pour le robot suiveur de personnes avec Arduino, en utilisant le capteur à ultrasons et la commande moteur L298N.
Références des composants utilisés:

https://www.gotronic.fr/art-commande-de-2-moteurs-sbc-motodriver2-27418.htm

https://www.gotronic.fr/art-paire-de-motoreducteurs-dg02s-18761.htm

https://www.gotronic.fr/art-module-a-ultrasons-gravity-sen0307-30126.htm


# Usage et mise en place
Pour faire fonctionner le robot après avoir téléchargé le code sur la carte Arduino, suivez ces étapes :

## Assemblage du matériel :
Assurez-vous que toutes les connexions matérielles sont correctes.
Connectez les moteurs aux sorties de la commande moteur L298N.
Connectez le capteur à ultrasons aux broches spécifiées dans le code (trigPin et echoPin).

## Alimentation :
Alimentez votre robot avec la tension spécifiée (3 à 9 Vcc).

##Téléchargement du code :
Assurez-vous que votre carte Arduino est correctement connectée à votre ordinateur via le câble USB.
Ouvrez l'IDE Arduino sur votre ordinateur.
Copiez le code dans l'IDE Arduino.
Sélectionnez le type de carte et le port série dans l'IDE Arduino.
Cliquez sur le bouton de téléchargement (flèche vers la droite) pour télécharger le code sur la carte Arduino.

## Observation :
Ouvrez le moniteur série de l'IDE Arduino (Outils > Moniteur Série) pour voir les messages de débogage (distance mesurée).
Placez votre robot et assurez-vous qu'il peut détecter des obstacles avec le capteur à ultrasons.

## Test :
Déplacez-vous devant le robot pour voir s'il ajuste sa vitesse et sa direction en fonction de la distance mesurée.
Assurez-vous que les moteurs réagissent correctement aux changements de distance.
Assurez-vous de respecter les règles de sécurité lors du test du robot, en particulier si les moteurs peuvent provoquer des mouvements brusques. Vous pouvez ajuster les seuils de distance et les vitesses dans le code en fonction de vos besoins.
