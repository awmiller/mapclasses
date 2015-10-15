#include "residential.h"

Residential::Residential() : capacity(0){}

Residential::~Residential(){}

void Residential::tick(){
    taxRevenue += capacity *0.1;
}

double Residential::collectTaxes(){ 
    return taxRevenue;
}