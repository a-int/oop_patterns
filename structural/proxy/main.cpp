#include "proxy.hpp"

int main(){
	ImageProxy proxy("img.jpeg");
	proxy.draw();
	std::cout<<"Extent of image is " << proxy.getExtent()<<std::endl;
	return 0;
}