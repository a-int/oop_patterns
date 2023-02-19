#include <iostream>
#include "ui.hpp"

int main(){
	UIFactory* factory = new LinuxUIFactory;
	factory->render();
	return 0;
}