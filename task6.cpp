#include <iostream>
using namespace std;

class Vehicle {
protected:
    string brand;
    int year;
public:
    Vehicle(string brand, int year) {
        this->brand = brand;
        this->year = year;
    }

    virtual void displayInfo() = 0;

    void startEngine() {
        cout << "Engine started." << endl;
    }

    void startEngine(string key) {
        cout << "Engine started with key: " << key << endl;
    }

    friend void compareYears(Vehicle &v1, Vehicle &v2);
};

void compareYears(Vehicle &v1, Vehicle &v2) {
    if (v1.year > v2.year) {
        cout << v1.brand << " is newer than " << v2.brand << endl;
    } else if (v1.year < v2.year) {
        cout << v2.brand << " is newer than " << v1.brand << endl;
    }
}

class Car : public Vehicle {
private:
    int numberOfDoors;
public:
    Car(string brand, int year, int numberOfDoors) : Vehicle(brand, year) {
        numberOfDoors = this->numberOfDoors;
    }

    void setNumberOfDoors(int numberOfDoors) {
        numberOfDoors = this->numberOfDoors;
    }

    int getNumberOfDoors() {
        return numberOfDoors;
    }

    void displayInfo() override {
        cout << "Car: " << brand << " Year: " << year << " Doors: " << numberOfDoors << endl;
    }
};

class Motorcycle : public Vehicle {
private:
    bool hasSideCar;

public:
    Motorcycle(string brand, int year, bool hasSideCar) : Vehicle(brand, year) {
        hasSideCar = this->hasSideCar;
    }

    void setHasSideCar(bool hasSideCar) {
        hasSideCar = this->hasSideCar;
    }

    bool getHasSideCar() {
        return hasSideCar;
    }

    void displayInfo() {
        cout << "Motorcycle: " << brand << " Year: " << year<<" ";
         if(hasSideCar == true){
             cout<<"Yes"<<endl;
         }else{
             cout<<"No"<<endl;
         }
    }
};

int main() {
    Car car1("Honda", 2019, 4);
    Motorcycle Motorcycle1("Yamaha", 2021, false);

    car1.setNumberOfDoors(2);
    Motorcycle1.setHasSideCar(true);

    car1.displayInfo();
    car1.startEngine();

    Motorcycle1.displayInfo();
    Motorcycle1.startEngine("KEY-568");

    compareYears(car1, Motorcycle1);

    Vehicle* vehicles[2];
    vehicles[0] = &car1;
    vehicles[1] = &Motorcycle1;

    cout << endl << "Displaying from pointer array:" << endl;
    for (int i = 0; i < 2; i++) {
        vehicles[i]->displayInfo();
    }

    return 0;
}
