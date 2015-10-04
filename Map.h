/* 
 * File:   Map.h
 * Author: awmil_000
 *
 * Created on October 3, 2015, 10:54 AM
 */

#ifndef MAP_H
#define	MAP_H
#include "MapItem.h"
#include <fstream>
class Map {
public:
    Map();
    Map(int newSize);
    Map(const Map& orig);
    virtual ~Map();
    int getSize() const;
    void build(int row,int column,char code);
    MapItem getMapItem(int row,int column);
    MapItem getElement(int index) const;
    friend std::ifstream& operator>>(std::ifstream& hipstr, Map& map);
    friend std::ofstream& operator<<(std::ofstream& ofstrch,const Map& map);
    friend std::ostream& operator<<(std::ostream& toastr, const Map& map);  
//private:
    int size;
    MapItem* items;

};

#endif	/* MAP_H */

