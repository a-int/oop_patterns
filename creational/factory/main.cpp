#include <iostream>
#include <string>
#include "factory.hpp"


int main(){
	Logistics* logistics = LogisticsFactory("boat");
	double cost = logistics->calcCost(100);
	std::cout<<cost<<std::endl;
	return 0;
}