#include "Arduino.h"
#include "FIFO.h"
#include "Plant.h"
// Plant.cpp : on implémente les fonctions déclarées dans Plant.h

// le constructeur de la classe Plant
Plant::Plant(int pin){
  this->pin = pin;
  nbvoisins=0;
  state = FREE;

}

void Plant :: update(){
  if(state == FREE){
    // si on a reçu un ou plusieurs messages
    if(_buffer.size() > 0){
      int msg = _buffer.pop(); //lire le message si je ne fais rien
      int hops = msg%10;
      if(msg < 10){ //message 0 avec x nombre de sauts
            if(hops < 3){
              state = BUSY;
              for (int i =0; i< nbvoisins;i++){            
                voisins[i]->post(msg+1);
                //Serial.write(pin);
                //Serial.write(msg+1);
                Serial.write('he');
                tone(pin, 500, 1500);
                //se mettre en busy, jouer une melodie d'une certaien durée 
                //(savoir combien de temps s'est ecoulé pendant la diffusion du message)
              }
              deadline = millis() + 1500;
          }
      }
      else if(msg < 20){// message 1 avec x nombre de sauts (passages d'une plante "relais" à une autre)

      }
    }
  }

    // BUSY
    else{ //busy if la melodie joue encore on fait rien, si la durée de la melodie est passée, on repasse en free
      if(millis() >= deadline){
        noTone(pin);
        state = FREE;
      }
    }
}

void Plant :: post(int msg){
  _buffer.push(msg);
}
