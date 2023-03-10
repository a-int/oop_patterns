#include <iostream>
#include <vector>
#include "decorator.hpp"

int main(){
	std::vector<std::string> cliesnts{"Adam", "Mike", "John"};
	EmailDecorator email(new SMSNotifier);
	email.send("test message", cliesnts);
	return 0;
}
