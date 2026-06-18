//!----ENCAPSULATION----!
//It is bundling of data and methods into single unit while restricting direct access to the data using access modifiers.

#include<iostream>
using namespace std;
class Employee {
    private:
     int salary;

     public:
      void setSalary(int s){
          if(s>=0){
            salary=s;
          }
      }

      int getSalary() {
        return salary;
      }

};

int main() {
    Employee e;
    e.setSalary(50000);
    cout<<e.getSalary();
}