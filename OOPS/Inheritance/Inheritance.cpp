//!---INHERITANCE---!
//Child can reuse the parent properties and functions

#include<iostream>
using namespace std;

class Employee{
   public:
   string name;
   int id;
   void showDetails(){
       cout<<"Name:"<<name<<endl;
       cout<<"Id:"<<id<<endl;
    }
};
 class Developer: public Employee {
    public:
    string programmingLanguage;

    void showLanguage()
    {
        cout << "Language: " << programmingLanguage << endl;
    }

 };
 class Manager : public Employee
{
public:
    int teamSize;

    void showTeam()
    {
        cout << "Team Size: " << teamSize << endl;
    }
};

int main()
{
    Developer d;
    d.name = "Arun";
    d.id = 101;
    d.programmingLanguage = "C++";

    Manager m;
    m.name = "Priya";
    m.id = 102;
    m.teamSize = 10;

    d.showDetails();
    d.showLanguage();

    cout << "----\n";

    m.showDetails();
    m.showTeam();
}