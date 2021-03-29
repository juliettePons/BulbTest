#include "Plant.h"
Plant[5] plants;
int curPlant=0;
void setup() {
  // put your setup code here, to run once:
  for(int = 0; i < 5; i++){
    plants[i] = new Plant();
    plants[0].voisins= {plants[1], plants[2]};
    plants[0].nbvoisins= 2;
    
    plants[1].voisins= {plants[0]};
    plants[1].nbvoisins= 1;
     
    plants[2].voisins= {plants[0], plants[5]};
    plants[2].nbvoisins= 2;
  }
}

void loop() {
  // put your main code here, to run repeat
 
  plants[curPlant].update();
  if(plants[curPlant].sate == FREE){
    curPlant= (curPlant+1)%5;
  }
  
  /*for(int = 0; i < 5; i++){
    plants[i].update;
  }
  */
}
