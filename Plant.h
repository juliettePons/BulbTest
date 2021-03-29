#ifndef Plant_h
#include "FIFO.h"
#define Plant_h

// Fichier "header", on y déclare le contenu de la classe Plant
// Les fonctions seront implémentée dans le fichier .cpp

#include "Arduino.h"

class Plant{
  // les états de la plante
  const int FREE; // elle n'a (plus) rien à faire
  const int BUSY; // elle est occupée à jouer un son : ne pas interrompre!

  // public : pourra être appelé de l'extérieur
  public:

    // les propriétés (variables) de la classe
    Plant[] voisins;
    int pin;
    int nbVoisins;
    int state;
    int deadline;

    // le constructeur
    Plant();

    // mettre à jour l'état de la plante
    void update();

    // fonction appelée pour mettre un message dans la FIFO de la plante
    void post();

    // private : logique interne qu'on veut garder pour nous
    private:
     FIFO_buffer;

};

#endif
