#ifndef CC_PAYMENT_STRATEGY
#define CC_PAYMENT_STRATEGY

#include "PaymentStrategy.h"
#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

class CCPaymentStrategy: public PaymentStrategy{
    private:
    string cardNumber;

    public:
    CCPaymentStrategy(const string& card){
        cardNumber=card;
    }

    void pay(double amount) override {
        cout<<"Paid Rupess"<<amount<<"using Credit Card (" <<cardNumber<<")" <<endl;
    }
};


#endif