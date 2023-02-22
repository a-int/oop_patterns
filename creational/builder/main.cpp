#include <iostream>
#include "ui.hpp"

int main(){
	//default director
	ButtonDirector* d = new ButtonDefaultDirector;
	ButtonBuilder* builder = new WindowsButtonBuilder;
	Button* bttn = d->build(*builder); //make default button with rectangle shape and resolution 720p

	bttn->getInfo();
	bttn->render();

	std::cout<<std::endl;
	
	//Custom button director
	delete d;
	d = new ButtonCustomDirector;
	bttn = d->build(*builder); //make custom windows button

	bttn->getInfo();
	bttn->render();

	return 0;
}