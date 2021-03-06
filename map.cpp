/* 
 * File:   Map.cpp
 * Author: awmil_000
 * 
 * Created on October 3, 2015, 10:54 AM
 */

#include "map.h"
#include "map_item.h"
#include <string>
#include <cstdlib>

Map::Map() {
    size =0;
    items = NULL;
}

Map::Map(int newSize) {
    size =newSize;
    items = new MapItem[size*size]();
}

Map::Map(const Map& orig) {
    this->size = orig.getSize();
    for (int i=0; i<(size*size);i++)
    {
        this->items[i] = orig.getElement(i);
    }
}

Map::~Map() {
    delete[] items;
}

int Map::getSize() const{
    return this->size;
}

void Map::build(int row,int column,char code){
    int index = (row * size) + column;
    if(index < size*size){
        items[index].setType(code);
    }
}

MapItem Map::getMapItem(int row,int column){
    int index = (row * size) + column;
    return items[index];
}

MapItem Map::getElement(int index) const{
    return items[index];
}

std::ifstream& operator>>(std::ifstream& hipstr, Map& map){
    int newSize = 0;
    hipstr>>newSize;
    
    map.size = newSize;
    
    delete[] map.items;
    
    map.items = new MapItem[newSize*newSize]();
    
    char c;
    for(int i =0;(hipstr>>c);){
        if((c!=' ')&&(c!='\r')&&(c!='\n')){
            map.items[i++].setType(c);
        }
    }
    
    return hipstr;
}

std::ofstream& operator<<(std::ofstream& ofile,const Map& map){
    ofile << (int)(map.getSize()) << '\n';
    for(int row = 0; row < (map.size*map.size); row+=map.size){
            for(int column =0; column < map.size; column++){
                            ofile << map.items[row+column] << " ";
            }
         //ofile << std::endl;//row separator
        }
    return ofile;
}

std::ostream& operator<<(std::ostream& toastr, const Map& map){
    for(int row = 0; row < (map.size*map.size); row+=map.size){
            for(int column =0; column < map.size; column++){
                            toastr << map.items[row+column] << " ";
            }
         toastr << std::endl;//row separator
        }
    return toastr;
}



