#include <string>

//Implementor
class MediaContent{
public:
    virtual std::string getImage() =0;
    virtual std::string getSnippet() =0;
    virtual std::string getURL() =0;
};

class Author: public MediaContent{
private:
    std::string getBIO() const {return name;};
    std::string name;
public:
    std::string getImage() override {/*return Image; */}
    std::string getSnippet() override {
        return getBIO();
    }
    std::string getURL() override{/*return URL; */}
};

class Movie: public MediaContent{
private:
    std::string getISBN() const {return isbn;};
    std::string isbn;
public:
    std::string getImage() override {/*return Image; */}
    std::string getSnippet() override {
        return getISBN();
    }
    std::string getURL() override{/*return URL; */}
};

//Abstaction
class Render{
protected:
    MediaContent& media;
    virtual ~Render() = default;
public:
    virtual std::string show() const =0;
};

class PhoneRender: public Render{
public:
    std::string show() const override{
        media.getImage();
        media.getSnippet();
        //render the stuff
    }
};

class ComputerRedner: public Render{
        std::string show() const override{
        media.getImage();
        media.getSnippet();
        media.getURL();
        //Implementation of rendering
    }
};
