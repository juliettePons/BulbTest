#include "Plant.h"
// liste de toutes les plantes gérées
Plant[5] plants;

// on ne va traiter qu'une plante à la fois dans chaque loop()
// curPlant contient le numéro de la plante actuelle
int curPlant=0;

void setup() {
  Serial.begin(9600);

  // on instancie chaque plante du tableau
  for(int = 0; i < 5; i++){
    plants[i] = new Plant();
  }

  // on spécifie les données de chaque plante
  plants[0].pin = 2;
  plants[0].voisins= {plants[1], plants[2]};
  plants[0].nbvoisins= 2;

  plants[1].pin = 5;
  plants[1].voisins= {plants[0]};
  plants[1].nbvoisins= 1;

  plants[2].pin = 8;
  plants[2].voisins= {plants[0], plants[4]};
  plants[2].nbvoisins= 2;

  plants[3].pin = 9;
  plants[3].voisins= {plants[4]};
  plants[3].nbvoisins= 1;

  plants[4].pin = 11;
  plants[4].voisins= {plants[2], plants[3]};
  plants[4].nbvoisins= 2;
}

void loop() {
  // on met à jour la plante actuelle
  plants[curPlant].update();

  // si la plante actuelle n'a (plus) rien à faire
  if(plants[curPlant].state == FREE){
    // on passe à la plante suivante
    curPlant= (curPlant+1)%5;
  }
}
