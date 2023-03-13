#include "iterator.hpp"
#include <iostream>
#include <list>
int main(){
	AbstactList<int> list;
	list.push_front(1);
	list.push_front(2);
	list.push_front(3);
	list.push_front(4);
	for(auto& it : list)
		std::cout<<it<<" ";
	//UB
	std::cout<<*list.end();
}