#ifndef Plant_h
#define Plant_h

// Fichier "header", on y déclare le contenu de la classe Plant
// Les fonctions seront implémentée dans le fichier .cpp

#include "FIFO.h"
#include "Arduino.h"

class Plant{

    // private : logique interne qu'on veut garder pour nous
    private:
      /* buffer des messages reçus d'autres plantes
         message == int entre 00 et 99
         0  0
         ^  ^
         |  |_ nombre de sauts depuis l'émetteur du message
         |____ ID du message
      */
      FIFO _buffer;

      // buffer de tones à jouer dans l'ordre
      // puisque la FIFO (dans sa forme actuelle) stocke des uint8_t
      // on fait 2 pushes par tone() :
      // - la fréquence (divisée par 3 pour aller de 0 à 765Hz)
      // - la durée (divisée par 8 pour aller de 0 à 2040ms)
      FIFO _tones;

      /* ~ beaucoup de chipo parce qu'on est partis de cette FIFO qui ne stocke
        que des uint8_t .. faut voir si c'est viable...
      */

    // public : pourra être appelé de l'extérieur
    public:

      // LES PROPRIÉTÉS (variables) de la classe

      // les états de la plante
      static const int FREE = 0; // elle n'a (plus) rien à faire
      static const int BUSY = 1; // elle est occupée à jouer un son : ne pas interrompre!

      int state; // stocke l'état

      // tableau de pointeurs vers les plantes voisines dans notre réseau
      Plant* voisins[4];
      int nbvoisins; // nombre de voisins dans le tableau (de 0 à 4)

      int pin; // pin correspondant à la plante

      // prochain moment (cf millis()) où il faudra évaluer un truc dans l'état BUSY
      // - soit jouer la note suivante
      // - soit repasser en free
      int deadline;

      // LES MÉTHODES (fonctions) de la classe
      // le constructeur
      Plant(int pin);

      // mettre à jour l'état de la plante
      void update();

      // fonction appelée pour mettre un message dans la FIFO de la plante
      void post(int msg);
};

#endif
