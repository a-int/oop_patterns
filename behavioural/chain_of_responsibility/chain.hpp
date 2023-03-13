#pragma once
#include <iostream>

struct Event{
	virtual ~Event() = default;
};
struct ButtonEvent:public Event {};
struct WindowEvent:public Event {};

struct EventHandler{ //interface for Even handlers
	virtual void handleEvent(Event* ev) =0;
};

//abstract class for all widgets
struct Widget: public EventHandler{
	Widget(): handler(0) {}
	void handleEvent(Event* ev) override {
		//forward request by default if hanndler exists
		//otherwise ignore request
		if(handler) handler->handleEvent(ev); 
	}
	EventHandler* setHandler(EventHandler* handler) {
		this->handler = handler; 
		return handler; //make possible chaining set up
	}
	//~Widget() = default;
private:
	EventHandler* handler;
};


class Button: public Widget{
public:
	void handleEvent(Event* ev) override {
		//Do button specific response if button event
		//or default actions for catched event
		if(dynamic_cast<ButtonEvent*>(ev))
			std::cout<<"Button event catched.\n";
		else {
			std::cout<<"Forward request to handler ...\t";
			Widget::handleEvent(ev);
		}
	}
};

class Window: public Widget{
public:
	void handleEvent(Event* ev) override {
		//Do window specific response if window event
		//or default actions for catched event
		if(dynamic_cast<WindowEvent*>(ev))
			std::cout<<"Window event catched.\n";
		else {
			std::cout<<"Forward request to handler ...\t";
			Widget::handleEvent(ev);
		}
	}
};