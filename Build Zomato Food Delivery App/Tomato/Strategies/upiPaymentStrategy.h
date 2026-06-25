#ifndef UPI_PAYMET_STRATEGY_H
#define UPI_PAYMENT_STRATEGY_H

#include "PaymentStrategy.h"
#include<iostream>
#include<string>
#include<iomanip>

using namespace std;

class upiPaymentStrategy : public PaymentStrategy{
  private:
  string mobile;

  public:
  upiPaymentStrategy(const string& mob){
    mobile=mob;
  }

  void pay(double amount) override {
    cout<<"Paid Rupees"<<amount<<"using UPI ("<<mobile<<")"<<endl;
  }

};

#endif