#include <string>
#include <iostream>

struct Image{
	virtual void draw() =0;
	virtual int getExtent() =0;
};

class RealImage: public Image{
public:
	RealImage(const std::string& fName): fName(fName) {}
	void draw() override {std::cout<<"Load image from disk and draw ...\n";}
	int getExtent() override{return 100;}	
private:
	std::string fName;
};

class ImageProxy: public Image{
public:
	ImageProxy(const std::string& fName): fName(fName), img(0), extent(0) {}
	void draw() override {
		if(!img) img = new RealImage(fName);
		img->draw();
	}
	int getExtent() override {
		if(extent == 0){
			img = new RealImage(fName);
			extent = img->getExtent();
		}
		return extent;
	}
private:
	std::string fName;
	RealImage* img;
	int extent;
};