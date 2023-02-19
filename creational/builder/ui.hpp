#pragma once
#include <iostream>
#include <string>

class Button{ //interface for Button type
public:
	Button(std::string tp = "default", int res = 720): type(tp), resolution(res) {}
	virtual void render() =0;
	virtual void getInfo() =0;
protected:
	std::string type = "default";
	int resolution = 720;
};

class WindowsButton: public Button{ //Implementation of the Button interface
public:
	WindowsButton(std::string tp = "default", int res = 720): Button(tp, res) {}
	void render() {std::cout<<"Windows Button has been rendered\n";}
	void getInfo() {std::cout<<"Windows button type of: "<<type<<" and resolution: "<<resolution<<"p\n";}
};
class LinuxButton: public Button{ //Implementation of the Button interface
public:
	LinuxButton(std::string tp = "default", int res = 720): Button(tp, res) {}
	void render() {std::cout<<"Linux Button has been rendered\n";}	
	void getInfo() {std::cout<<"Linux button type of: "<<type<<" and resolution: "<<resolution<<"p\n";}
};

class BuilderButton{ //Interface for abstract factory of UI rendering
public:
	virtual Button* getButton() =0;
	virtual void makeSquareButton() {type = "square";}
	virtual void makeHighResolutionButton() {resolution = 4096;}
	virtual void render(){
		Button* bttn = getButton();
		bttn->render();
	}
protected:
	std::string type = "default";
	int resolution = 720;
};

class WindowsBuilderButton: public BuilderButton{ //Implementation of UI Factory interface
public:
	Button* getButton(){return new WindowsButton(type, resolution);}
};

class LinuxBuilderButton: public BuilderButton{ //Implementation of UI Factory interface
public:
	Button* getButton(){return new LinuxButton(type, resolution);}
};











