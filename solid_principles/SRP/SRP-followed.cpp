#include<bits/stdc++.h>
using namespace std;

class Product{
   public:
     double price;
     string name;

     Product(string name,double price){
       this->name = name;
       this->price = price;
     }
};

class CartManagement{
  vector<Product *> products;
  public:

  void addProduct(Product* p){
    products.push_back(p);
  }
  
  const vector<Product*>& getProducts(){
    return products;
  }
  
  double calculateTotal(){
    double price = 0;
    for(auto p:products){
      price += p->price;
    }
    return price;
  }
};

class CartInvoicePrinter{
  CartManagement *cart = new CartManagement();

  public:
  CartInvoicePrinter(CartManagement* cart){
    this->cart = cart;
  }

  void printInvoice(){
    cout << "Printing Invoice" << endl;
    for (auto p : cart->getProducts())
    {
      cout << p->name << " " << "is for Rs. " << p->price << endl;
    }

    cout << "Cart Total: " << cart->calculateTotal() << endl;
  }
};

class CartStorage{
  CartManagement *cart;

public:
  CartStorage(CartManagement* cart){
    this->cart = cart;
  }

  void SavingToDataBase(){
    cout << "Cart Items is being processed for dataBase" << endl;
  }
};

int main(){
  CartManagement *cart = new CartManagement();

  cart->addProduct(new Product("modile", 50000));
  cart->addProduct(new Product("laptop", 100000));
  cart->addProduct(new Product("grocieries", 20000));

  CartInvoicePrinter *printer = new CartInvoicePrinter(cart);
  printer->printInvoice();

  CartStorage *storage = new CartStorage(cart);
  storage->SavingToDataBase();

  return 0;
}