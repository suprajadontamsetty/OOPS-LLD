//!----ABSTRACTION---!
//Shows only necessary details and hiding the implementation details
//User knows what to do but not how it is done.

#include <iostream>
using namespace std;

class Payment
{
public:
    void pay(int amount)
    {
        validateUser();
        connectToBank();
        transferMoney(amount);

        cout << "Payment Successful\n";
    }

private:
    void validateUser()
    {
        cout << "Validating user...\n";
    }

    void connectToBank()
    {
        cout << "Connecting to bank...\n";
    }

    void transferMoney(int amount)
    {
        cout << "Transferring Rs." << amount << "\n";
    }
};

int main()
{
    Payment p;

    p.pay(500);
}

//We only need paying 500 nothing else and everything is hidden right, so follows abstraction