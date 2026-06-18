//!----ASSOCIATION---!
//It is of 3 types: 1.Simple , 2.Aggregation , 3.Composition
//1.SIMPLE:Two objects are related but neither owns the other.They can exist independently.

#include<iostream>
using namespace std;
class Student{
    public:
     string name;
    
     Student(string n){
        name=n;
     }
};
class Teacher{
  public:
   string name;
   Teacher(string n){
    name =n;
   }

   void teach(Student& student){              //passing refernce of student so that it isn't copied and unnecesary memory isn't used.Can also use pointers.
    cout<<name<<"teaches"<<student.name<<endl;
   }
};
int main(){
     Teacher teacher("John");
    Student student("Alice");

    teacher.teach(student);

    return 0;
}




//2.AGGREGATION:One object contains the other, but contained object can exist without the container.(Weak ownership)
//Ex: Department has teachers, but teacher doesnt require department to exist.

#include<iostream>
using namespace std;

class Teacher{
    public:
    string name;
    Teacher(string n){
        name=n;
    }

};

class Department{
    private:
    Teacher* teacher;
    public:
    Department(Teacher* t){
        teacher=t;
    }

    void showTeacher(){
     cout<<"Teacher:"<<teacher->name<<endl;
    }
};

int main(){
    Teacher teacher("John");      // Teacher created independently
    Department dept(&teacher);    // Department uses Teacher
    dept.showTeacher();
    return 0;

};



//3.COMPOSITION:The contained object cannot exist meaningfully without the container. The container owns the lifecycle of its parts.(Strong ownership0)
//One object owns another object , and the owned object's lifetime depends on owner.

#include<iostream>
using namespace std;
class Room{
   public:
   string name;
   Room(string n){
    name=n;
   }

   void showRoom(){
    cout<<"Room:"<<name<<endl;
   }

};

class House{
    private:
    Room room;

    public:
    House(string roomName){
         room=roomName;
    }
     void showHouse(){
        cout<<"House contains";
        room.showRoom();
     }


};

int main() {
    House house("Bedroom");
    house.showHouse();
    return 0;
}