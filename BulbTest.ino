#include "Plant.h"
// liste de toutes les plantes gérées
Plant plants[] = {Plant(2), Plant(5), Plant(8), Plant(9), Plant(11)};

// on ne va traiter qu'une plante à la fois dans chaque loop()
// curPlant contient le numéro de la plante actuelle
int curPlant=0;

void setup() {
  Serial.begin(9600);

  // on spécifie les données de chaque plante
  plants[0].voisins[0] = &plants[1];
  plants[0].nbvoisins= 1;

  plants[1].voisins[0] = &plants[2];
  //plants[1].voisins[1] = &plants[4];
  plants[1].nbvoisins= 1;


  plants[2].voisins[0] = &plants[3];
  plants[2].nbvoisins= 1;

  plants[3].voisins[0] = &plants[3];
  plants[3].voisins[1] = &plants[4];
  plants[3].nbvoisins= 2;


  plants[4].voisins[0] = &plants[0];
  plants[4].nbvoisins= 1;

  // impulsion de départ! c'est le big bang
  plants[0].post(0);
}

void loop() {
  // on met à jour la plante actuelle
  plants[curPlant].update();

  // si la plante actuelle n'a (plus) rien à faire
  if(plants[curPlant].state == 0){
    // on passe à la plante suivante
    curPlant= (curPlant+1)%5;
  }

}
