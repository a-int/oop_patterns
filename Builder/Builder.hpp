#include <iostream>

class House{
protected:
    int square;
    int numDoors;
    int numFloors;
    bool isPool;
public:
    House(int s, int d, int f, int p): square(s), numDoors(d), numFloors(f), isPool(isPool) {};
    const char* info() const {std::cout<<"House has "<<square<<" square "<<numDoors<<" doors "<<numFloors<<(numFloors? " floor":" floors")<<(isPool?" and pool":" no pool");}
};

class House_Builder{
private:
    int square = 0;
    int numDoors = 0;
    int numFloors = 0;
    bool isPool = false;
public:
    House_Builder() = default;
    void setSquare(int sqr) {square = sqr;}
    void setDoors(int doors) {numDoors = doors;}
    void setFloors(int floors) {numFloors = floors;}
    void setPool() {isPool = !isPool;}
    House* getResult(){
        return new House(square,numDoors,numFloors,isPool);
    }
};