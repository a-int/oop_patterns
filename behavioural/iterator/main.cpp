#include "iterator.hpp"
#include <iostream>
#include <list>
int main(){
	List<int> list;
	list.push_back(1);
	list.push_back(2);
	list.push_back(3);
	list.push_back(4);
	for(auto& it : list)
		std::cout<<it<<" ";
	//UB
	std::cout<<*list.end();
}