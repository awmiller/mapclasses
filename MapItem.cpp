/* 
 * File:   MapItem.cpp
 * Author: awmil_000
 * 
 * Created on October 3, 2015, 10:55 AM
 */

#include "MapItem.h"

MapItem::MapItem() {
    type = 'E';
}

MapItem::MapItem(const MapItem& orig) {
    type = orig.getType();
}

char MapItem::getType() const{
    return type;
}

void MapItem::setType(char newType){
    type = newType;
}
    
std::ifstream& operator>>(std::ifstream& nifstr, MapItem& mapitem){}
    
std::ostream& operator<<(std::ostream& ostrizr, MapItem& mapitem){
    ostrizr << mapitem.type;
}
