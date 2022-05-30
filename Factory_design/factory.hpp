#ifndef factory_hpp
#define factory_hpp
#include <string>
#include <iostream>

class Notification{
protected:
    std::string message;
public:
    virtual void showNotification() const =0;
    Notification(const char* msg): message(msg) {}
};

class SystemNotification: public Notification{
public:
    void showNotification() const override;
    SystemNotification(const char* msg): Notification(msg) {}
};

class AppNotification: public Notification{
public:
    void showNotification() const override;
    AppNotification(const char* msg): Notification(msg) {}

};

class NotificationFactory{
public:
    Notification* const notification = NULL;
    NotificationFactory(Notification* const newNotification): notification(newNotification) {}
};

#endif
