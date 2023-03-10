#pragma once
#include <vector>
#include <string>
#include <iostream>

struct NotifierInterface{
	virtual void send(const char* msg, std::vector<std::string>& clients) =0;
};

class SMSNotifier : public NotifierInterface{
public:
	void send(const char* msg, std::vector<std::string>& clients) override;
};

class EmailDecorator: public NotifierInterface{
public:
	EmailDecorator(NotifierInterface* ntf): notifier(ntf) {}
	void send(const char* msg, std::vector<std::string>& clients) override;
protected:
	NotifierInterface* notifier;
};

void SMSNotifier::send(const char* msg, std::vector<std::string>& clients){
	for(auto& i: clients)
		std::cout<<i + " got sms\n";
}

void EmailDecorator::send(const char* msg, std::vector<std::string>& clients){
	notifier->send(msg, clients);
	for(auto& i: clients)
		std::cout<<i + " got email\n";
}
