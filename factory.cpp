#include "factory.h"
#include <cstdlib>

Factory::Factory() : countSinceLastProduced(0){
    production = new Queue();
    produced = new Queue();
}

Factory::~Factory(){
    delete production;
    delete produced;
    production = NULL;
    produced = NULL;
}

void Factory::tick(){
    if(production->size()==0){
        countSinceLastProduced=0;
    }
    else
    if(countSinceLastProduced == production->front()){
      produced->enqueue(production->dequeue()); 
      countSinceLastProduced = 0;
    }
    else{
        countSinceLastProduced++;
    }
}

void Factory::produceItem(int item){
    production->enqueue(item);
}

int Factory::getProducedItem(){
    if(producedCount() >0 ){
        return produced->dequeue();
    }
    
    return FACTORY_NO_ITEM_PRODUCED;
}

int Factory::productionCount(){
    return production->size();
}

int Factory::producedCount(){
    return produced->size();
}