#ifndef Plant_h
#include "FIFO.h"
#define Plant_h

// Fichier "header", on y déclare le contenu de la classe Plant
// Les fonctions seront implémentée dans le fichier .cpp

#include "Arduino.h"

class Plant{
  
  

    // private : logique interne qu'on veut garder pour nous
    private:
     FIFO _buffer;
     FIFO _tones;
    // public : pourra être appelé de l'extérieur
  public:

    // les propriétés (variables) de la classe

    // les états de la plante
    static const int FREE = 0; // elle n'a (plus) rien à faire
    static const int BUSY = 1; // elle est occupée à jouer un son : ne pas interrompre!

    Plant* voisins[4];
    int pin;
    int nbvoisins;
    int state;
    int deadline;

    // le constructeur
    Plant(int pin);

    // mettre à jour l'état de la plante
    void update();

    // fonction appelée pour mettre un message dans la FIFO de la plante
    void post(int msg);
    
};

#endif
