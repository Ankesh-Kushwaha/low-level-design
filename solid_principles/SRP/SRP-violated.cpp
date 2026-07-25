#include<bits/stdc++.h>
using namespace std;

//SRP violeted
class Product{
  public:
  int price;
  string name;
  Product(string name,int price){
    this->name = name;
    this->price = price;
  }
};

class CartManagement{
  vector<Product *> products;

  public:
    // add products;
    void addProducts(Product *p){
      products.push_back(p);
    }

    //calculate price
    int calculateTotal(){
      int price = 0;
      for (auto p : products)
      {
        price += p->price;
      }
      return price;
    }
    
    //print invoice
    void printInvoice(){
       for(auto p:products){
         cout << p->name << " " << "is for " << "Rs. " << p->price << endl;
       }
    }

    // save the cart to database;
    void saveToDB(){
      cout << "products is saving to database" << endl;
    }
};

int main(){
  CartManagement *cart = new CartManagement();

  cart->addProducts(new Product("cell Phone",20000));
  cart->addProducts(new Product("Laptop", 40000));

  cout << cart->calculateTotal() << endl;
  cart->printInvoice();
  cart->saveToDB();
  return 0;
}