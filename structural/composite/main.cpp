#include "todoComponent.hpp"
#include <iostream>

int main(){
	TodoComposite todoList("TODO LIST");
	todoList.add("Press kachat");
	todoList.add("Onjumaniya");

	TodoComposite anotherList("Read GoF book");
	anotherList.add("Repeat Creational patterns");
	anotherList.add("Read Composite pattern");
	anotherList.remove("Read Composite pattern");

	todoList.add(anotherList);
	std::cout<<todoList.getHtml()<<std::endl;
	return 0;
}
