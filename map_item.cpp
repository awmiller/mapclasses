/* 
 * File:   MapItem.cpp
 * Author: awmil_000
 * 
 * Created on October 3, 2015, 10:55 AM
 */

#include "map_item.h"

MapItem::MapItem() {}

MapItem::~MapItem() {}


/*
MapItem::MapItem(char initializer) {
    type = initializer;
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
    
std::ifstream& operator>>(std::ifstream& nifstr, MapItem& mapitem){
    char incoming;
    nifstr >> incoming;
    while((incoming == ' ')||(incoming == '\r')||(incoming == '\n')){
        nifstr >> incoming;
    }

    mapitem.setType(incoming);

    return nifstr;

}
    
std::ostream& operator<<(std::ostream& ostrizr, MapItem& mapitem){
    ostrizr << mapitem.type;
    return ostrizr;
}
*/
