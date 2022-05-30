#ifndef PROTOTYPEHPP
#define PROTOTYPEHPP
#include <string>

class Notification{
protected:
    std::string message;
public:
    void showNotification() const;
    Notification(const char* msg): message(msg) {}
    virtual Notification* clone() =0;
};

class SystemNotification: public Notification{
public:
    SystemNotification(const char* msg): Notification(msg) {}
    Notification* clone() override {return new SystemNotification(message.c_str());}
};

class AppNotification: public Notification{
public:
    AppNotification(const char* msg): Notification(msg) {}
    Notification* clone() override {return new AppNotification(message.c_str());}
};

class NotificationFactory{
public:
    Notification* const notification = NULL;
    NotificationFactory(Notification* const newNotification): notification(newNotification) {}
};

#endif
