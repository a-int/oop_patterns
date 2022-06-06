#include <iostream>
#include "adapter.hpp"
#include <math.h>

int main(){
    RoundHole hole(10);
    SquarePegAdapter sPeg(2);
    std::cout<<"For the hole of radius eqaul to 10 a square peg of width 2 "<<(hole.fits(sPeg)? "fits":"doesnt fit")<<std::endl;
    return 0;
}

bool RoundHole::fits(RoundPeg& peg) const{
    return (peg.getRadius() <= radius);
}

double SquarePegAdapter::getRadius() const{
    return sqrt(pow(sqPeg.getWidth()/2, 2) * 2);
}