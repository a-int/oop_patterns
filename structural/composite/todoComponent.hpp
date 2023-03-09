#pragma once
#include <string>
#include <list>

class TodoComponent{ //interface for ToDo components 
public:
	virtual std::string getHtml() {return "";}	//generate apropriate HTML code
	std::string getTitle() {return title;}

	virtual ~TodoComponent() = default;
protected:
	TodoComponent(const std::string s):title(s){}
	std::string title;
};

class TodoTask: public TodoComponent{ //basic todo task
public:
	std::string getHtml() override;

	TodoTask(const std::string& s) : TodoComponent(s) {}
	virtual ~TodoTask() = default;
};

class TodoComposite: public TodoComponent{ //Composition of todo tasks
public:
	virtual ~TodoComposite() = default;
	TodoComposite(const std::string& s)
		: TodoComponent(s) {}
	std::string getHtml() override;
	std::string getHtmlComponents(); //generate apropriate HTML code for components

	void add(TodoComponent& comp);
	void add(const std::string&);
	void remove(TodoComponent& comp);
	void remove(const char*);
protected:
	std::list<TodoComponent*> tasks;
};

std::string TodoTask::getHtml(){
	return title;
}

std::string TodoComposite::getHtml(){
	std::string res(title);
	res += "\n<ul>\n";
	for(auto& it: tasks){
		res += "<li>" + it->getTitle() + "</li>\n";
		if(auto obj = dynamic_cast<TodoComposite*>(it)){
			res += obj->getHtmlComponents();
		}
	}
	res += "</ul>\n";
	return res;
}

std::string TodoComposite::getHtmlComponents(){
	if(!tasks.size()) return "";
	std::string res;
	res += "<ul>\n";
	for(auto& it: tasks){
		res += "<li>" + it->getTitle() + "</li>\n";
		if(auto obj = dynamic_cast<TodoComposite*>(it)){
			res += obj->getHtmlComponents();
		}
	}
	res += "</ul>\n";
	return res;
}

void TodoComposite::add(TodoComponent& comp){
	tasks.push_back(&comp);
}
void TodoComposite::add(const std::string& s){
	tasks.push_back(new TodoTask(s));
}
void TodoComposite::remove(TodoComponent& comp){
	for(auto it = tasks.begin(); it != tasks.end(); ++it){
		if(*it == &comp)
			tasks.erase(it);
	}
}


void TodoComposite::remove(const char* title){
	for(auto it = tasks.begin(); it != tasks.end(); ++it){
		if((*it)->getTitle() == title){
			tasks.erase(it);
			break;
		}
	}
}











