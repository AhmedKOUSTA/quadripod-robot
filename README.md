# Quadripod-robot "QuadBot"

Ce robot à quatre pattes , qui se prénomme QuadBOT pour Embedded Robotic , a été construit dans le cadre du club CELEC .C’est un robot quadrupède qui a été d’abord conçu virtuellement en 3D, puis chacune des pièces a été réalisé avec du bois et  du plastique.
Le robot QuadBOT pèse environ 0,4 kg pour une taille 22 cm, est pour le mettre en mouvement, ce n’est pas moins de 8 servo-moteurs qui sont utilisés.
Au niveau de l’intelligence artificielle, QuadBOT utilise un micro-contrôleur ATMEGA 16 .

     1.   Conception mécanique du système 

[Video](http://www.youtube.com/watch?v=EYxNN1IYde8)


      2.   Système électronique

  Schéma électrique d’ensemble réalisé sous ISIS, qui contient :
  
   - Un microcontrôleur ATMEGA16
   - 8 servomoteurs
   - Une interface Virtuelle
   
  
       3.Partie intelligent

1.   Software
            Environnement utilise pour la compilation du programme  c’est AVRstudio et  Notepad Programmer.
WinAVR qui contient des bibliothèques d’ATMEGA16.
 2.   Objectif du programme
Ce programme nous permet  de commander les 8 servomoteurs à travers les signaux de la sortie d’ATmega 16 avec lequel on manipule l’ongle de chaque servomoteur.
Ce programme est valable pour les différents types des servomoteurs.
3.   Structure de système

Pour pouvoir contrôler les 8 servomoteurs avec grande,  des divers composants internes du mC ont était utiliser: communication USART, Interface de programmation ISP6, 3 TIMER, interruption externes INT2.
(30% du mémoire totale du microcontrôleur).
 
