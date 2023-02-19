#pragma once 
#include <string>

class DataBase{
public:
	static DataBase* get(){
		static DataBase* db = nullptr;
		if(!db) db = new DataBase;
		return db;
	}
	static const std::string& read(){return content;}
	static void write(const std::string& str){content.append(str);}
	static void clear(const std::string& str){content.clear();}
private:
	DataBase() = default;
	static std::string content;
};
std::string DataBase::content = "";