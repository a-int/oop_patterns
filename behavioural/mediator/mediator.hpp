#pragma once

#include <algorithm>
#include <stdexcept>
#include <string>
#include <iostream>
#include <vector>
#include <list>

class ChatMediator;
class Person{
public:
	Person(const std::string& msg, ChatMediator& cm): Name(msg), chatMediator(&cm) {}

	std::string getName();

	void initChat();

	void sendMessgae(Person& p, const char* msg);

	void recieve(Person& from, const char* msg);
protected:
	std::string Name;
	ChatMediator* chatMediator;
};

class ChatMediator{
public:
	ChatMediator& addParticipant(Person& p){
		participants.push_back(&p);
		return *this;
	}

	ChatMediator& removeParticipant(Person& p){
		participants.remove(&p);
		return *this;
	}
	void send(Person& from, Person& to, const char* msg){
		if(std::find(participants.begin(), participants.end(), &from) != participants.end())
			if(std::find(participants.begin(), participants.end(), &to) != participants.end())
				to.recieve(from, msg);
			else
				std::cout<<to.getName()+" not in chat\n";
		else
			std::cout<<from.getName()+" not found\n";
	}
protected:
	std::list<Person*> participants;
};

std::string Person::getName(){return Name;}

void Person::initChat(){
	chatMediator->addParticipant(*this);
}

void Person::sendMessgae(Person& p, const char* msg){
	if(chatMediator)
		chatMediator->send(*this, p, msg);
}

void Person::recieve(Person& from, const char* msg){
	std::cout<<"\""<<msg<<"\" from "<<from.getName()<<std::endl;		
}





