#ifndef FACTORY_H
#define FACTORY_H

#define FACTORY_NO_ITEM_PRODUCED -1

#include "queue.h"
#include "map_item.h"

class Factory : public MapItem{

  private:
        
    int countSinceLastProduced;
    Queue * production;
    Queue * produced;
    
  public:
        
    Factory();
    virtual ~Factory();
    void tick();
    void produceItem(int item);
    int getProducedItem();
    int productionCount();
    int producedCount();
};

#endif