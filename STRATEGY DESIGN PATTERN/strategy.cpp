#include<iostream>
using namespace std;

class PaymentStrategy{
     public:
     virtual void pay(int amount)=0;
      virtual ~PaymentStrategy() {}
};

class upiPayment: public PaymentStrategy{
   public:
    void pay(int amount) override {
         cout<<"Paid Rs." << amount << " using UPI." << endl;
    }
};

class cardPayment:public PaymentStrategy{
 public:
 void pay(int amount) override {
    cout<<"paid Rs."<<amount<<"using Card."<<endl;
 }
};

class CashOnDelivery : public PaymentStrategy {
public:
    void pay(int amount) override {
        cout << "Cash Rs." << amount << " will be collected on delivery." << endl;
    }
};

class DeliveryStrategy {
public:
    virtual void deliver() = 0;
    virtual ~DeliveryStrategy() {}
};

class StandardDelivery : public DeliveryStrategy {
public:
    void deliver() override {
        cout << "Standard delivery in 45 minutes." << endl;
    }
};

class ExpressDelivery : public DeliveryStrategy {
public:
    void deliver() override {
        cout << "Express delivery in 15 minutes." << endl;
    }
};

class PickupDelivery : public DeliveryStrategy {
public:
    void deliver() override {
        cout << "Customer will pick up the order." << endl;
    }
};


class FoodOrder{
   protected:
    PaymentStrategy* paymentBehavior;
    DeliveryStrategy* deliveryBehavior;

    public:
     FoodOrder(PaymentStrategy* p, DeliveryStrategy* d) {
        paymentBehavior = p;
        deliveryBehavior = d;
    }

    void makePayment(int amount) {
        paymentBehavior->pay(amount);
    }

    void deliverOrder() {
        deliveryBehavior->deliver();
    }

    virtual void showOrderType() = 0;
};

class RegularOrder : public FoodOrder {
public:
    RegularOrder(PaymentStrategy* p, DeliveryStrategy* d)
        : FoodOrder(p, d) {}

    void showOrderType() override {
        cout << "Regular Customer Order" << endl;
    }
};

class PremiumOrder : public FoodOrder {
public:
    PremiumOrder(PaymentStrategy* p, DeliveryStrategy* d)
        : FoodOrder(p, d) {}

    void showOrderType() override {
        cout << "Premium Customer Order" << endl;
    }
};

int main() {

    FoodOrder* order1 =
        new RegularOrder(
            new upiPayment(),
            new StandardDelivery()
        );

    order1->showOrderType();
    order1->makePayment(250);
    order1->deliverOrder();

    cout << "\n------------------------\n" << endl;

    FoodOrder* order2 =
        new PremiumOrder(
            new cardPayment(),
            new ExpressDelivery()
        );

    order2->showOrderType();
    order2->makePayment(800);
    order2->deliverOrder();

    return 0;
}

