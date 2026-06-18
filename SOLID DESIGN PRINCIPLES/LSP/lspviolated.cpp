#include<iostream>
#include<vector>
using namespace std;

class Account{
  public:
  virtual void deposit(double amount)=0;  //here it is not violating SRP as it deals single responsibility that is account operations
  virtual void withdraw(double amount)=0;   
};

class SavingsAccount:public Account {
   private:
    double balance;

   public:
    SavingsAccount(){
        balance=0;
    } 

    void deposit(double amount){
        balance+=amount;
        cout<<"Deposited:"<<amount<<"in Savings acoount.New balance"<<balance<<endl;
    }

      void withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
            cout << "Withdrawn: " << amount << " from Savings Account. New Balance: " << balance << endl;
        } else {
            cout << "Insufficient funds in Savings Account!\n";
        }
    }
};

class CurrentAccount : public Account {
private:
    double balance;

public:
    CurrentAccount() { 
        balance = 0; 
    }

    void deposit(double amount) {
        balance += amount;
        cout << "Deposited: " << amount << " in Current Account. New Balance: " << balance << endl;
    }

    void withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
            cout << "Withdrawn: " << amount << " from Current Account. New Balance: " << balance << endl;
        } else {
            cout << "Insufficient funds in Current Account!\n";
        }
    }
};


class FixedTermAccount : public Account {
private:
    double balance;

public:
    FixedTermAccount() { 
        balance = 0; 
    }

    void deposit(double amount) {
        balance += amount;
        cout << "Deposited: " << amount << " in Fixed Term Account. New Balance: " << balance << endl;
    }

    void withdraw(double amount) {
        throw logic_error("Withdrawal not allowed in Fixed Term Account!");
    }
};

class BankClient {
private:
    vector<Account*> accounts;

public:
    BankClient(vector<Account*> accounts) { 
        this->accounts = accounts; 
    }

    void processTransactions() {
        for (Account* acc : accounts) {
            acc->deposit(1000);  //All accounts allow deposits

            //Assuming all accounts support withdrawal (LSP Violation)
            try {
                acc->withdraw(500);
            } catch (const logic_error& e) {
                cout << "Exception: " << e.what() << endl;
            }
        }
    }
};

int main() {
    vector<Account*> accounts;
    accounts.push_back(new SavingsAccount());
    accounts.push_back(new CurrentAccount());
    accounts.push_back(new FixedTermAccount());

    BankClient* client = new BankClient(accounts);
    client->processTransactions(); //  Throws exception when withdrawing from FixedTermAccount

    return 0;
}

//Here FixedTermAccount violates the LSP rule as it cannot be used to withdraw amount.
//We can write a condition in BankClient that FixedTerm is only used for savings. But in future what if we 
//---some other account with some other condition. Then again have to change code for Bank Client which violates OCP.