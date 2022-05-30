#include "Prototype.hpp"
#include <iostream>

int main(){
    SystemNotification update("IOS was successfully updated");
    auto cpUpdate = update.clone();
    cpUpdate->showNotification();
    return 0;
}

void Notification::showNotification() const {std::cout<<message<<std::endl;}