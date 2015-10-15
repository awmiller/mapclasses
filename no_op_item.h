#ifndef NO_OP_ITEM_H
#define NO_OP_ITEM_H

#include "map_item.h"

class NoOpItem : public MapItem{
   public:
    NoOpItem();
    virtual ~NoOpItem();
    void tick();
};

#endif