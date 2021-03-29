#include "Arduino.h"
#include "FIFO.h"
#include "Plant.h"
// Plant.cpp : on implémente les fonctions déclarées dans Plant.h

// le constructeur de la classe Plant
Plant :: Plant(int pin){
  this->pin = pin;
  this->nbvoisins=0;
  this->state = FREE;
}

void Plant :: update(){
  if(state == FREE){ // on est prêts à traiter un nouveau message
    if(_buffer.size() > 0){ // si on a reçu un ou plusieurs messages
      state = BUSY;
      _tones.push(int(100/3));// fréquence divisée par 3, pushée dans _tones
      _tones.push(int(50/8));// durée divisée par 8, pushée dans _tones

      int msg = _buffer.pop(); // lire le message
      int hops = msg%10; // le nombre de sauts
      if(msg < 10){ //message 0 avec x nombre de sauts
            if(hops < 4){
              for (int i =0; i< nbvoisins;i++){
                voisins[i]->post(msg+1); // logique ici : on transmet le message aux voisins
                Serial.print(pin);
                Serial.print ('_');
                Serial.print (voisins[i]->pin);
                Serial.print ('_');
                Serial.println(msg+1);
              }
              // et on joue un son qui "sonifie" ce qu'on a dit à nos voisins
              _tones.push(int(500/3));
              _tones.push(int(1500/8));
              //deadline = millis() + 1500;
          }
      }
      else if(msg < 20){ // message 1 avec x nombre de sauts (passages d'une plante "relais" à une autre)
        // autre message, autre logique, à mettre en place ;)
      }
    }
  }

    // BUSY
    else{
      // on ne va pas interrompre un truc en cours
      // il faut donc que la deadline soit passée
      if(millis() >= deadline){
        if(_tones.size() > 1){ // y'a de la tone à jouer
          int f = _tones.pop()*3; // *3 car on "décompresse" les valeurs stockées
          int d = _tones.pop()*8; // idem

          Serial.print(pin);
          Serial.print ('/');
          Serial.print (f);
          Serial.print ('/');
          Serial.println (d);

          tone(pin, f, d);
          // noTone(pin);
          deadline = millis() + d + 100; // +100 pour séparer les tones
        }
        else{ // y'a plus rien à jouer, on libère
          noTone(pin);
          state = FREE;
        }
      }
    }
  }


void Plant :: post(int msg){
  _buffer.push(msg);
}
