#include <vector>
#include <string>

class Log{
public:
    typedef std::vector<std::string> sVec;

    Log* get();
    std::string back() const {return history.back();}
    void add(const std::string& elem) {history.push_back(elem);}
private:
    Log() = default;
    static Log* Instance;
    sVec history;
};