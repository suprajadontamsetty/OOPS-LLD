//--The .h extension means file contains declarations rather than implementations
//--It is intended to be included iun other source files.
//--Such as class definations,constants,struct definations,, template declarations 
//--will have corresponding declaration file named as .cpp


#ifndef RESTAURANT_H
#define RESTAURANT_H

#include<iostream>
#include<string>
#include<vector>
#include "MenuItem.h"

using namespace std;

class Restaurant {
    private:
    static int nextRestaurantId;  // one counter is created for all the objects.
    int restaurantId;
    string name;
    string location;
    vector<MenuItem>menu;

    public:
    Restaurant(const string& name, const string& location){
        this->name=name;
        this->location=location;
        this->restaurantId=++nextRestaurantId;

    }

    ~Restaurant(){
         cout << "Destroying Restaurant: " << name << ", and clearing its menu." << endl;
        menu.clear();
    }

    string getName() const{
       return name;
    }

    void setName(const string &n){
        name=n;
    }

    string getLocation() const{
        return location;
    }

    void setLocation(const string &loc){
        location=loc;
    }

    void addMenuItem(const MenuItem &item){
        menu.push_back(item);
    }

    const vector<MenuItem>& getMenu() const{
        return menu;
    }


};

int Restaurant :: nextRestaurantId=0;  //create single shared static variable for the restaurant class and start it with 0.

#endif

