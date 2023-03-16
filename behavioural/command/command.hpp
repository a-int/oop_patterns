#pragma once
#include <iostream>

//--------------------Reciever----------------------------------
class Window{//Reciever of the request 
public:
	void close() {std::cout<<"Close window...\n";}
	void hide() {std::cout<<"Hide window...\n";}
	void restore() { std::cout << "Restore the window";}
	bool canClose(){return false;}
};

//-------------Request encapsulation-----------------------------
struct IRequest{ //Interface for binding request to window
	virtual void execute() =0;
	virtual void undo() =0;
	virtual ~IRequest() = default;
};

class NoComand : public IRequest{
public:
	void execute() override {}
	void undo() override {}
};

class WindowRequestClose: public IRequest{
public:
	WindowRequestClose(Window* w): win(w) {}
	void execute() override {win->close();}
	void undo() override {win->restore();}
protected:
	Window* win;
};

class WindowRequestHide: public IRequest{
public:	
	WindowRequestHide(Window* w): win(w) {}
	void execute() override {win->hide();}
	void undo() override {win->restore();}
protected:
	Window* win;
};

//--------------------Invoker------------------------------------
class Button{ //Invoker
public:
	Button(IRequest* c = new NoComand): cmd(c) {}
	void clicked(){cmd->execute();}
	void setRequest(IRequest* r){
		delete cmd;
		cmd = r;
	}

	~Button() {delete cmd;}
protected:
	IRequest* cmd;
};