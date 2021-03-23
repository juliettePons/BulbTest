#include "Arduino.h"
#include "FIFO.h"
#include "Plant.h"
// le constructeur de la classe plant
Plant::Plant(){
  nbVoisins=0;
  state = FREE;
  
}

void Plant :: update(){
  if(state == FREE){
    int msg = _buffer.pop(); //lire le message si je ne fais rien
    int hops = msg%10; // +prévoir le cas ou y a rien dans la boite
    if(msg < 10){ //message 0 avec x nombre de sauts
          if(hops < 3){
          for (int i =0; i< nbVoisins;i++){
            voisins[i].post(msg+1);
            //se mettre en busy, jouer une melodie d'une certaien durée (savoir combien de temps s'est ecoulé pendant la diffusion du message)
            }
         }
    }
      }else if(msg < 20){// message 1 avec x nombre de sauts (passages d'une plante "relais" à une autre)
        
        }
    }

    else{ //busy if la melodie joue encore on fait rien, si la durée de la melodie est passée, on repasse en free
    }
}

void Plant ::post(int msg){
  _buffer.push(msg);
}
