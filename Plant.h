#ifndef Plant_h
#include "FIFO.h"
#define Plant_h

#include "Arduino.h"

class Plant{
  const int FREE;
  const int BUSY;
  
  public:
    Plant();
    void update();
    void post();
    Plant[] voisins;
    int nbVoisins;
    void
    int state;
    private:
     FIFO_buffer;
     
};

#endif
