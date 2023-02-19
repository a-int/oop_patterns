#pragma once
#include <iostream>

class Button{ //interface for Button type
public:
	virtual void render() =0;
};

class WindowsButton: public Button{ //Implementation of the Button interface
public:
	void render() {std::cout<<"Windows Button has been rendered\n";}
};
class LinuxButton: public Button{ //Implementation of the Button interface
public:
	void render() {std::cout<<"Linux Button has been rendered\n";}	
};

class AlertWindow{ //Interface for alert window type
public:
	virtual void render() =0;
};
class WindowsAlertWindow: public AlertWindow{ //Implementation of the AlertWindow interface
public:
	void render() {std::cout<<"Windows alert window has been rendered\n";}
};
class LinuxAlertWindow: public AlertWindow{ //Implementation of the AlertWindow interface
public:
	void render() {std::cout<<"Linux alert window has been rendered\n";}
};

class UIFactory{ //Interface for abstract factory of UI rendering
public:
	virtual Button* getButton() =0;
	virtual AlertWindow* getAlertWindow() =0;
	virtual void render(){
		Button* bttn = getButton();
		AlertWindow* alWindow = getAlertWindow();

		bttn->render();
		alWindow->render();
	}
};

class WindowsUIFactory: public UIFactory{ //Implementation of UI Factory interface
public:
	Button* getButton(){return new WindowsButton;}
	AlertWindow* getAlertWindow(){return new WindowsAlertWindow;}
};

class LinuxUIFactory: public UIFactory{ //Implementation of UI Factory interface
public:
	Button* getButton(){return new LinuxButton;}
	AlertWindow* getAlertWindow(){return new LinuxAlertWindow;}
};
