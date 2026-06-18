#include<iostream>
#include<vector>

using namespace std;

class Product{
    public:
    string name;
    double price;

    Product(string name, double price){
         this->name=name;
         this->price=price;
    }
};

class ShoppingCart {
    private:
    vector<Product*>products;

    public:
    void addProduct(Product*p){
        products.push_back(p);
    }

    const vector<Product*>& getProducts(){
        return products;
    }

    double calculateTotal() {
        double total = 0;
        for (auto p : products) {
            total += p->price;
        }
        return total;
    }



};

class ShoppingCartPrinter {
private:
    ShoppingCart* cart; 

public:
    ShoppingCartPrinter(ShoppingCart* cart) { 
        this->cart = cart; 
    }

    void printInvoice() {
        cout << "Shopping Cart Invoice:\n";
        for (auto p : cart->getProducts()) {
            cout << p->name << " - Rs " << p->price << endl;
        }
        cout << "Total: Rs " << cart->calculateTotal() << endl;
    }
};

class ShoppingCartStorage {
private:
    ShoppingCart* cart; 

public:
    ShoppingCartStorage(ShoppingCart* cart) { 
        this->cart = cart; 
    }

    void saveToSQLDatabase() {
        cout << "Saving shopping cart to SQL DB..." << endl;
    }

    void saveToMongoDatabase() {
        cout << "Saving shopping cart to Mongo DB..." << endl;
    }

    void saveToFile() {
        cout << "Saving shopping cart to File..." << endl;
    }
};


int main() {
    ShoppingCart* cart = new ShoppingCart();

    cart->addProduct(new Product("Laptop", 50000));
    cart->addProduct(new Product("Mouse", 2000));

    ShoppingCartPrinter* printer = new ShoppingCartPrinter(cart);
    printer->printInvoice();

    ShoppingCartStorage* db = new ShoppingCartStorage(cart);
    db->saveToSQLDatabase();

    return 0;
};   
//Here it is violating OCP because, if we further add someother method of saving data to DB
// --then whole class will be modified as new method is introduced.

//Better practice is to introduce an interface class/ abstract class and create a new derived class
//--- for each storage type, allowing adding new functionality without modifying a class.

