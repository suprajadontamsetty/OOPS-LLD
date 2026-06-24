#include<iostream>
using namespace std;

class Singleton{
    private:
    static Singleton* instance;

    Singleton(){
        cout<<"Singleton Constructor called"<<endl;
    }

    public:
    static Singleton* getInstance() {
        if(instance==nullptr){
            instance=new Singleton();
        }

        return instance;
    }

};

Singleton* Singleton::instance=nullptr;

int main(){
  Singleton* s1= Singleton::getInstance();
  Singleton* s2=Singleton::getInstance();

  cout<<(s1==s2)<<endl;
}

//It incorporates private construtor, which serves as a barricade
//--against external attempts to create instances of the Singleton class.
//--This ensures class has control over its instantiation process.


//Static Factory Method
//--We have static factory method. This methid acts as gateway, providing a global point of access
//--to the Singleton object.When someone requests an instance, this method 
//--either creates a new instance or returns the exisitng instance to the caller.




