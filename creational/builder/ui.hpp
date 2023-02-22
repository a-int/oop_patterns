#pragma once
#include <iostream>
#include <string>

class Button{ //interface for Button type
public:
	Button(std::string tp = "default", int res = 720): type(tp), resolution(res) {}
	virtual void render() {std::cout<<type<<" button rendered\n";}
	virtual void getInfo() {std::cout<<type<<" resolution("<<resolution<<")\n";}
	void setResolution(int res) {resolution = res;}
	void setType(const char* tp) {type = tp;}
	virtual ~Button() = default;
protected:
	std::string type = "default";
	int resolution = 720;
};

class WindowsButton: public Button{ //Implementation of the Button interface
public:
	WindowsButton(std::string tp = "default", int res = 720): Button(tp, res) {}
	void render() {std::cout<<"Windows Button has been rendered\n";}
	void getInfo() {std::cout<<"Windows button type of "<<type<<" with resolution "<<resolution<<"p\n";}
};
class LinuxButton: public Button{ //Implementation of the Button interface
public:
	LinuxButton(std::string tp = "default", int res = 720): Button(tp, res) {}
	void render() {std::cout<<"Linux Button has been rendered\n";}	
	void getInfo() {std::cout<<"Linux button type of "<<type<<" and resolution "<<resolution<<"p\n";}
};

class ButtonBuilder{ //Interface for abstract factory of UI rendering
public:
	virtual Button* getButton(){return bttn;}
	virtual void buildButton(){}
	virtual void setShape(const char*){}
	virtual void setResolution(uint32_t x){}
	
	virtual ~ButtonBuilder(){delete bttn;}
protected:
	ButtonBuilder() = default;
	Button* bttn = 0;
};

class WindowsButtonBuilder: public ButtonBuilder{ //Implementation of UI Factory interface
public:
	void buildButton(){if(!bttn) bttn = new WindowsButton;}
	void setShape(const char* shape){bttn->setType(shape);}
	void setResolution(uint32_t res){bttn->setResolution(res);}
};

class LinuxButtonBuilder: public ButtonBuilder{ //Implementation of UI Factory interface
public:
	void buildButton(){if(!bttn) bttn = new LinuxButton;}
	void setShape(const char* shape){bttn->setType(shape);}
	void setResolution(uint32_t res){bttn->setResolution(res);}
};

class ButtonDirector{
public:
	virtual Button* build(ButtonBuilder& builder) =0;
	virtual ~ButtonDirector() = default;
};

class ButtonDefaultDirector: public ButtonDirector{
public:
	Button* build(ButtonBuilder& builder){
		builder.buildButton();
		builder.setShape("rectangle");
		builder.setResolution(720);
		return builder.getButton();
	}
};

class ButtonCustomDirector: public ButtonDirector{
public:
	Button* build(ButtonBuilder& builder){
		builder.buildButton();
		builder.setShape("custom shape");
		builder.setResolution(1080);
		return builder.getButton();
	}
};









