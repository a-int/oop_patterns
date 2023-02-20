#pragma once
#include <iostream>
#include <string>

//the class to hold basic methods and data for the example
class Data{
public:
	Data() = default;
	Data(const char* str): content(str){}
	std::string getContent() {return content;}
	void print(){std::cout<<content<<std::endl;}
protected:
	std::string content;
};

class JSON: public Data{
public:
	JSON(const char* str): Data(str){}
};

class XML:public Data{
public:
	XML(const char* str): Data(str) {}
};

class XMLtoJSON{
public:
	XMLtoJSON(XML& x): xml(x){}
	JSON parseXML(){
		std::string tmp = xml.getContent();
		tmp.erase(tmp.begin(), tmp.begin()+3);
		tmp.insert(0, "JSON");
		return tmp.c_str();
	}
private:
	XML xml;
};