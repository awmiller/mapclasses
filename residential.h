#ifndef RESIDENTIAL_H
#define RESIDENTIAL_H

#include "map_item.h"

class Residential : public MapItem{
    
  private:
    int capacity;
    double taxRevenue;
    
  public:
    Residential();
    virtual ~Residential(); 
    void tick();
    double collectTaxes();
    
};

#endif