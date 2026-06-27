#include<iostream>
#include<string>

using namespace std;

class Engine{
 public:
 virtual void start()=0;
 virtual ~Engine() {}
};

class PetrolEngine:public Engine{
    public:
    void start() override {
        cout<<"Petrol engine roaring to life!" << endl;
    }
};

class DieselEngine : public Engine {
public:
    void start() override {
        cout << "Diesel engine roaring to life!" << endl;
    }
};

class ElectricEngine : public Engine {
public:
    void start() override {
        cout << "Electric engine powering up silently!" << endl;
    }
};

class Car {
protected:
    Engine* engine;
public:
    Car(Engine* e) {
        engine = e;
    }
    virtual void drive() = 0;
};

class Sedan : public Car {
public:
    Sedan(Engine* e) : Car(e) {}

    void drive() override {
        engine->start();
        cout << "Driving a Sedan on the highway." << endl;
    }
};

class SUV : public Car {
public:
    SUV(Engine* e) : Car(e) {}

    void drive() override {
        engine->start();
        cout << "Driving an SUV off-road." << endl;
    }
};

int main() {
   Engine* petrolEng = new PetrolEngine();
    Engine* dieselEng = new DieselEngine();
    Engine* electricEng = new ElectricEngine();

     Car* mySedan = new Sedan(petrolEng);
    Car* mySUV = new SUV(electricEng);
    Car* yourSUV = new SUV(dieselEng);

    mySedan->drive();   
    mySUV->drive();     
    yourSUV->drive();

     return 0;
};
