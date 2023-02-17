#pragma once
#include <iostream>
#include <string>

class Transport{ //interface for transport class
public:
	virtual ~Transport() = default;
	virtual Transport* createTransport() =0;
	virtual void deliver() =0;
};
class Truck: public Transport{ //Implementation of the transport interface
	Truck* createTransport();
	void deliver();
};
class Boat: public Transport{ //Implementation of the transport interface
	Boat* createTransport();
	void deliver();
};

class Logistics{ //Factory interface
public:
	virtual ~Logistics() = default;
	virtual Transport* createTransport() =0;
	virtual double calcCost(uint32_t distance) =0;
};
class RoadLogistics: public Logistics{ //Implementation of factory interface
public:
	Truck* createTransport();
	double calcCost(uint32_t distance);
};
class BoatLogistics: public Logistics{ //Implementation of factory interface
public:
	Boat* createTransport();
	double calcCost(uint32_t distance);
};

Logistics* LogisticsFactory(const std::string& type); //get appropriate logistics implementation