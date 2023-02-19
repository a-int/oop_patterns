#include <iostream>
#include "singleton.hpp"

int main(){
	std::cout<<((DataBase::read().empty())? "Data base is empty":DataBase::read())<<std::endl;
	DataBase::write("new text");
	std::cout<<DataBase::read()<<std::endl;
	return 0;
}