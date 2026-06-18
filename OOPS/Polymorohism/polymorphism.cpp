//!---POLYMORPHISM----!
//One name, many forms.
//It is of two types : 1. Dynamic Polymorphism
//                     2.Static polymorphism

//1. Static Polymorphism: Decision is made at compile time(before program runs)--Function overloading
#include<iostream>
using namespace std;
class Math{
    public:
     int add(int a, int b){
        return a+b;
     }

     int add(int a, int b, int c){
        return a+b+c;                       
     }

};

int main() {
    Math obj;
    cout<<obj.add(2,3)<<endl;
    cout<<obj.add(2,3,4)<<endl; 
}
//c++ decides at complie time, add(2,3) call 2 parameter function etc.

//2.Static Polymorphism:Decision is made at runtime.
// ---Happens through inheritance, virtual functions,pointers/references.

//!--VIRTUAL FUNCTION-- :- It is a member function in base class that gets overriden in derived classes.

#include <iostream>
using namespace std;

class Animal
{
public:
    virtual void sound()
    {
        cout << "Animal sound\n";
    }
};

class Dog : public Animal
{
public:
    void sound()
    {
        cout << "Bark\n";
    }
};

class Cat : public Animal
{
public:
    void sound()
    {
        cout << "Meow\n";
    }
};

int main()
{
    Animal* a;

    Dog d;
    Cat c;

    a = &d;
    a->sound();  //can also be called by doing d.sound(), then why doing this method? because one code can work for many different objects.

    a = &c;
    a->sound();
}

//Its a flexible call.