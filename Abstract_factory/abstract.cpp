#include <iostream>
#include "abstract.hpp"

int main()
{
    TransportFactory* f = new BudgetTransportFactory();
    Client c1(f);
    c1.shipTransport();
    c1.driveAuto();
    delete f;
    return 0;
}

void BudgetAuto::drive(){
    std::cout<<"Budget auto driven by a driver"<<std::endl;
}

void LuxaryAuto::drive(){
    std::cout<<"Luxary auto driven by an AI"<<std::endl;
}

void BudgetBoat::drive(){
    std::cout<<"Budget auto driven by yourself"<<std::endl;
}

void LuxaryBoat::drive(){
    std::cout<<"Luxary boat driven by a capitan"<<std::endl;
}

Auto* BudgetTransportFactory::autoFactory(){
    return new BudgetAuto;
}
Boat* BudgetTransportFactory::boatFactory(){
    return new BudgetBoat;
}

Auto* LuxaryTransportFactory::autoFactory(){
    return new LuxaryAuto;
}
Boat* LuxaryTransportFactory::boatFactory(){
    return new LuxaryBoat;
}
