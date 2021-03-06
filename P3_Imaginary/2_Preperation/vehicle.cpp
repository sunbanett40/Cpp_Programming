#include <iostream>

class Vehicle
{
public:
    void printName()
    {
        std::cout << name << " hi" << std : endl;
    }

private:
    std::string name;
};

class Truck : public Vehicle
{
public:
    Truck()
    {
        name = "Truck!";
    }

    void printName()
    {
        std::cout << name << std : endl;
    }

    void honkHorn()
    {
        //... honk horn here
    }
}

class Hatchback : public Vehicle
{ //... }

    if (dynamic_cast<D2 *>(x) == nullptr)
    {
        std::cout << "NOT A D2" << std::endl;
    }
    if (dynamic_cast<D1 *>(x) == nullptr)
    {
        std::cout << "NOT A D1" << std::endl;
    }
};

Vehicle v; //some random Vehicle
if (...)
{
    Truck truck = static_cast<Truck>(v);
    truck.honkHorn();

    if (...)
    {
        Flatbed fb = static_cast<Flatbed>(truck);
        fb.lowerBed();
        fb.
    }
}

//is it a truck?
Truck *truck = dynamic_cast<Truck *>(v);
if (truck != nullptr)
{
    //yay it's a truck!
    truck->name = "OOOOOO";
    truck->honkHorn();
    // (*truck).honkHorn(); the arrow (->) does this!
}

//print name here
std::cout << v.printName() << std::endl; //prints "OOOOO" if truck