#include <iostream>
#include "factory.hpp"

int main()
{
    SystemNotification* update = new SystemNotification("ios 16 was successufly updated!");
    NotificationFactory* newNotification = new NotificationFactory(update);
    newNotification->notification->showNotification();
    delete update;
    delete newNotification;
    return 0;
}

void SystemNotification::showNotification()const {
    std::cout<<message<<std::endl;
};
void AppNotification::showNotification()const {
    std::cout<<message<<std::endl;
}
