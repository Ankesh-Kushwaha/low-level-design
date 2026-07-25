#include<bits/stdc++.h>
using namespace std;

class Product{
   public:
     string name;
     int price;

     Product(string name,int price){
       this->name = name;
       this->price = price;
     }
};

class CartManagement{
  vector<Product *> products;

  public:
  void addProducts(Product* p){
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
  CartManagement *cart;
  
  public:
  CartInvoicePrinter(CartManagement* cart){
    this->cart = cart;
  }
  
  void printInvoice(){
    cout << "printing invoice......" << endl;
    for(auto p:cart->getProducts()){
      cout << p->name << " " << "is for Rs. " << p->price << endl;
    }
  }
};

class CartStorage{
  CartManagement *cart;
  public:
  CartStorage(CartManagement* cart){
    this->cart = cart;
  }

  void saveToSQL(){
    cout << "data is being saved to SQL" << endl;
  }

  void savetomngo(){
    cout << "data is being saved to mongo" << endl;
  }

  void savetoFile(){
    cout << "data is being saved to file" << endl;
  }
};

int main(){
  CartManagement *cart = new CartManagement();

  cart->addProducts(new Product("mobile", 50000));
  cart->addProducts(new Product("bike", 60000));
  cart->addProducts(new Product("laptop", 100000));

  CartInvoicePrinter *printer = new CartInvoicePrinter(cart);
  printer->printInvoice();

  CartStorage *storage = new CartStorage(cart);
  storage->savetoFile();
  storage->savetomngo();
  storage->saveToSQL();
  return 0;
}