/* 
 * Andrew Miller
 * 915113828
 * amiller2@sfsu.edu
 * gcc version 4.9.3 (GCC)
 */

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>

#include "Map.h"

using namespace std;

struct Coords{
    int row,column;
};

//struct MapItem{
//    char type;
//};
//
//struct Map{
//    int size;
//    MapItem *items;
//};

enum MenuOptions{
    ERROR=-1,INIT=0, NEW_GAME=1,PRINT_MAP=2,BUILD=3,EXIT_PROGRAM=4
};

bool runGames(Map &mMap);
int getMenuOption();
void printOptions();
bool excecuteMenuItem(int MenuOption, Map & map);
bool create_new_game( Map & map );
bool print_map( Map & map );
bool build( Map & map );
int prompt_for_map_size();
Coords promptForCoords();
char promptForBuildCode();
bool buildCodeOnCoords(char code,Coords location, Map & map);

int main(int argc, char** argv) {
    Map *mMap = new Map();
    while(runGames(*mMap));
    return 0;
}

bool runGames(Map &mMap){
    int option = getMenuOption();
    bool success = excecuteMenuItem(option,mMap);
    return success;
}

int getMenuOption(){
    int get = ERROR;
    
    printOptions();
    
    cin >> get;
    
    return get;
}

/**
 * extend in enum 'MenuOptions' first, then add switch case
 * @return whether the driver should continue or not
 */
bool excecuteMenuItem(int MenuOption, Map & map){
    
    switch(MenuOption){
        
        case NEW_GAME:
            return create_new_game( map );
            
        case PRINT_MAP:
            cout << map;
            return true;
            
        case BUILD:
            // TODO: prompt user first then provide build code as arguement
            return  build( map );
            
        case EXIT_PROGRAM:
	    delete &map;
            return false;
            
        default:
            cout << "Invalid menu option" << endl;
            return false;
    }
    
    return true;
}

/*
 * extend by adding options to the enum 'MenuOptions' first
 */
void printOptions(){
    cout << endl;
    cout << NEW_GAME << ". New Game" << endl;
    cout << PRINT_MAP << ". Print Map" << endl;
    cout << BUILD << ". Build Something" << endl;
    cout << EXIT_PROGRAM << ". Exit" << endl;
    cout << "Enter your selection: ";
}

bool create_new_game( Map & map ){
	
    Map nMap (prompt_for_map_size());
    map = nMap;
    return true;
}

bool print_map( Map & map ){
    
    for(int row = 0; row < (map.getSize()*map.getSize()); row+=map.getSize()){
		
        for(int column =0; column < map.getSize(); column++){
            
//			cout << map.getMapItem(row,column) << " ";
			
        }
        cout << endl;
    }
    return true;
}

bool build( Map & map ){
    Coords buildOn = promptForCoords();
    char code = promptForBuildCode();
    return buildCodeOnCoords(code,buildOn,map);
}

int prompt_for_map_size(){
    int sz = 0;
    
    cout << "What size map would you like? ";
    
    cin >> sz;
    
    return sz;
}

Coords promptForCoords(){
    Coords cds;
    
    cout << "Enter x and y coordinate: ";
    
    if((cin>>cds.column)&&(cin>>cds.row)){
        return cds;
    }
    else{
        cds.column = -1;
        cds.row = -1;
    }
    
    return cds;
}

char promptForBuildCode(){
    char code;
    cout << "Enter a building code: ";
    cin >> code;
    return code;
}

//returns success/fail
bool buildCodeOnCoords(char code,Coords location, Map & map){
    map.build(location.row,location.column,code);
    return true;
}