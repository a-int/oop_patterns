#include "factory.hpp"

Truck* Truck::createTransport(){return new Truck;}
void Truck::deliver(){std::cout<<"the truck is delivering the package";}
Boat* Boat::createTransport(){return new Boat;}
void Boat::deliver(){std::cout<<"the boat is delivering the package";}

Truck* RoadLogistics::createTransport(){return new Truck;}
double RoadLogistics::calcCost(uint32_t distance) {return 5*distance;}
Boat* BoatLogistics::createTransport(){return new Boat;}
double BoatLogistics::calcCost(uint32_t distance) {return 1.5*distance+3000;}

Logistics* LogisticsFactory(const std::string& type){
	if(type == "car") return new RoadLogistics;
	if(type == "boat") return new BoatLogistics;

	return nullptr;
}