#include <iostream>
#include "ui.hpp"

int main(){
	BuilderButton* builder = new LinuxBuilderButton;
	builder->makeSquareButton();
	builder->makeHighResolutionButton();
	Button* bttn = builder->getButton();

	bttn->getInfo();
	bttn->render();
	return 0;
}