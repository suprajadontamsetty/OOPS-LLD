//!---POINTERS---!
//A* means pointer to A and A*a means a is the variable which stores the address of an object A or any object derived from A.
//B*b=new B() , New B() creates a new object of B in heap memory , and b stores the address of object. 
//If A*b=new B() , b stores the address of B, this happens only when B is derived class of A.(i.e B is a type of A)
//--b is a pointer of type A.
//A type pointer is pointing to B object, becaue it is derived from A.
#include<iostream>
using namespace std;

class A {
public:
    void showA() {}
};

class B : public A {
public:
    void showB() {}
};

int main(){
    A* a = new B();
    a->showA(); //allowed
    a->showB(); //since class A has no member with showB.
}


int x=10;
int* ptr=&x;
//here 1.cout<<ptr will give the address of x 
//     2.cout<<*ptr will give 10 
//     3. *ptr tells ptr is a pointer



//!----CONSTRUCTORS----!
//Initialize an object automatically when it is created, especially when different objects need diff values.
//1.A special function called when an object is created.
//2.Same name as the class
//3.Returns nothing
//4.Runs automatically

#include <iostream>
using namespace std;

class Student
{
public:
    string name;
    int age;

    Student()  //constructor, also called default constructor, constructor with no parameters.
    {
        name = "Unknown";
        age = 0;
    }
};

int main()
{
    Student s;

    cout << s.name << endl;
    cout << s.age << endl;
}
//Here values can be assigned even without constructor, then what is the use of constructor?
//1.If multiple students were there and each of them have different names and ages.
//---Because without constructor same name and age will be applied to all the students.


#include<iostream>
using namespace std;
class Students{
    public:
     string name;
     double age;

     Students(string name, double age){
        this->name=name;  
        this->age=age;
     }
};

int main() {
    Students s("Supraja",20);
    cout<<s.name<<endl;
    cout<<s.age<<endl;

}

