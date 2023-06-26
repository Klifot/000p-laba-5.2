#include <iostream>
#include <string>

class Engine {
private:
    int power;

public:
    Engine(int power) : power(power) {
    }

    int getPower() const {
        return power;
    }
};

class Car {
private:
    std::string* brand;
    double price;
    Engine engine;

public:
    Car(const std::string& brand, double price, int enginePower)
        : brand(new std::string(brand)), price(price), engine(enginePower) {
    }

    Car(const Car& other)
        : brand(new std::string(*other.brand)), price(other.price), engine(other.engine) {
    }

    ~Car() {
        delete brand;
    }

    void print() const {
        std::cout << "Brand: " << *brand << std::endl;
        std::cout << "Price: " << price << std::endl;
        std::cout << "Engine Power: " << engine.getPower() << std::endl;
    }
};

class Truck : public Car {
private:
    int cargoCapacity;

public:
    Truck(const std::string& brand, double price, int enginePower, int cargoCapacity)
        : Car(brand, price, enginePower), cargoCapacity(cargoCapacity) {
    }

    Truck(const Truck& other)
        : Car(other), cargoCapacity(other.cargoCapacity) {
    }

    void print() const {
        Car::print();
        std::cout << "Cargo Capacity: " << cargoCapacity << std::endl;
    }
};

int main() {
    // Create a car
    Car car("Lamborgini", 20000.0, 150);
    car.print();
    std::cout << std::endl;

    // Create a truck
    Truck truck("Ferrari", 30000.0, 200, 5000);
    truck.print();

    return 0;
}