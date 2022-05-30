#ifndef ABSTRACTHPP
#define ABSTRACTHPP
#include <string>
#include <iostream>
class Auto{
protected:
    std::string name;
public:
    Auto() = default;
    Auto(const char* nm): name(nm) {}
    virtual void drive() =0;
    void setName(const char* nm) {name = nm;}
};

class BudgetAuto: public Auto{
public:
    BudgetAuto() = default;
    BudgetAuto(const char* nm): Auto(nm) {}
    void drive() override;
    void setName(const char* nm) {name = nm;}
};

class LuxaryAuto: public Auto{
public:
    LuxaryAuto() = default;
    LuxaryAuto(const char* nm): Auto(nm) {}
    void drive() override;
};

class Boat{
private:
    std::string name;
public:
    Boat() = default;
    Boat(const char* nm): name(nm) {}
    virtual void drive() =0;
};

class BudgetBoat: public Boat{
public:
    BudgetBoat() = default;
    BudgetBoat(const char* nm): Boat(nm) {}
    void drive() override;
};

class LuxaryBoat: public Boat{
public:
    LuxaryBoat() = default;
    LuxaryBoat(const char* nm): Boat(nm) {}
    void drive() override;
};

class TransportFactory{
public:
    virtual Auto* autoFactory() =0;
    virtual Boat* boatFactory() =0;
};

class BudgetTransportFactory: public TransportFactory{
public:
    Auto* autoFactory() override;
    Boat* boatFactory() override;
};

class LuxaryTransportFactory: public TransportFactory{
public:
    Auto* autoFactory() override;
    Boat* boatFactory() override;
};

class Client{
private:
    TransportFactory* factory;
    Auto* autoTransport;
    Boat* boatTransport;
public:
    Client(TransportFactory* f): factory(f) {}
    void shipTransport()
    {
        autoTransport = factory->autoFactory();
        boatTransport = factory->boatFactory();
    }
    void driveAuto(){autoTransport->drive();}
    void driveBoat(){boatTransport->drive();}
};

#endif