#include "Builder.hpp"

int main(){
    House_Builder hb1;
    hb1.setDoors(4);
    hb1.setFloors(1);
    hb1.setSquare(100);
    auto house = hb1.getResult();
    house->info();
    return 0;
}