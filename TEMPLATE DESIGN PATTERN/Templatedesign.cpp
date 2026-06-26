#include<iostream>
using namespace std;

class BeverageMaker{
  public:
  void makeBevarage() {
    boilWater();
    brew();
    pourInCup();
    addCondiments();
  }

  virtual void brew()=0;
  virtual void addCondiments() = 0;

   void boilWater() {
        cout << "Boiling water" << endl;
    }

    void pourInCup() {
        cout << "Pouring into cup" << endl;
    }

};

class TeaMaker:public BeverageMaker{
    public:
    void brew() override{
         cout << "Steeping the tea" << endl; 
    }
     void addCondiments() override {
        cout << "Adding lemon" << endl;
    }



};

class CoffeeMaker: public BeverageMaker{
    public:
    void brew() override{
         cout << "Dripping coffee through filter" << endl;
    }

    void addCondiments() override {
        cout << "Adding sugar and milk" << endl;
    }

};

int main() {
    cout<<"Making tea:"<<endl;
    TeaMaker teamaker;
    teamaker.makeBevarage();

    cout<<"\nMaking coffee:"<<endl;
    CoffeeMaker coffeemaker;
    coffeemaker.makeBevarage();
}