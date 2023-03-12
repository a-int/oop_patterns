#pragma once
#include <iostream>
#include <string>
#include <unordered_map>
// flyweight interface
struct TreeFlyweight {
  virtual void draw(int x, int y, std::string colour) = 0;
};

// shared concrete flyweight class
class TreeBasic : public TreeFlyweight {
public:
  TreeBasic(const std::string& shp) : shape(shp) {}
  void draw(int x, int y, std::string colour) override {
    std::cout << "The basic tree shape of " << shape
              << " has been drawed in pos {x, y} = {" << x << "; " << y
              << "} with colour - " << colour<<std::endl;
  }

protected:
  std::string shape;
};

// unshared concrete flyweight class
class TreeSpecific : public TreeFlyweight {
public:
  TreeSpecific(const std::string& shp, const std::string& clr) : shape(shp) {}
  void draw(int x, int y, std::string colour = "green") override {
    std::cout << "The specific tree shape of " << shape
              << " has been drawed in pos {x, y} = {" << x << "; " << y
              << "} with colour - " << colour;
  }

protected:
  std::string shape;
};

class TreeFactory{
public:
	TreeFactory() = default;

	TreeFlyweight* getTree(const std::string& shp){
		if(trees.find(shp) == trees.end()) // add tree with new shape
			trees[shp] = new TreeBasic(shp);
		return trees[shp];
	}
private:
	std::unordered_map<std::string, TreeFlyweight*> trees;
};
