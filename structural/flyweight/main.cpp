#include "flyweight.hpp"
#include <functional>
#include <vector>

int main(){
	TreeFactory factory;
    std::vector<std::pair<int, int>> positions = {{10, 20}, {30, 40}, {50, 60}};
    std::vector<std::string> shapes = {"pine", "oak", "maple"};
    std::vector<std::string> colors = {"red", "blue", "green"};
    
    for (int i = 0; i < positions.size(); i++) {
        TreeFlyweight* tree = factory.getTree(shapes[i]);
        tree->draw(positions[i].first, positions[i].second, colors[i]);
    }
    TreeFlyweight* tree = new TreeSpecific("oak", "green");
    tree->draw(0, 0, "red");

	return 0;
}