#include <iostream>
#include "singleton.hpp"

Log* Log::Instance = 0;

int main(){
    Log* newInst = newInst->get();
    newInst->add("First Log");
    newInst->add("Second Log");
    std::cout<<newInst->back();
    delete newInst;
    return 0;
}

Log* Log::get(){
    if(Instance == NULL){
        Instance = new Log();
    }
    return Instance;
}