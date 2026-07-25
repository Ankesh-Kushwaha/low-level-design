#include<bits/stdc++.h>
using namespace std;

// open close means class is open for extension but can not be modify;
class Product
{
public:
  string name;
  int price;

  Product(string name, int price)
  {
    this->name = name;
    this->price = price;
  }
};

class CartManagement
{
  vector<Product *> products;

public:
  void addProducts(Product *p)
  {
    products.push_back(p);
  }

  const vector<Product *> &getProducts()
  {
    return products;
  }

  double calculateTotal()
  {
    double price = 0;
    for (auto p : products)
    {
      price += p->price;
    }
    return price;
  }
};

class CartInvoicePrinter
{
  CartManagement *cart;

public:
  CartInvoicePrinter(CartManagement *cart)
  {
    this->cart = cart;
  }

  void printInvoice()
  {
    cout << "printing invoice......" << endl;
    for (auto p : cart->getProducts())
    {
      cout << p->name << " " << "is for Rs. " << p->price << endl;
    }
  }
};

//create a persistence class 
class DBPersistance{
  CartManagement *cart;

  public:
    virtual void save(CartManagement *cart) = 0;
};

//extend the DBPersistance class
class SQLPersistance:public DBPersistance{
  public:
  void save(CartManagement* cart) override{
    cout << "cart is going to saved in SQL database" << endl;
  }
};

class MongoPersistance:public DBPersistance{
  public:
  void save(CartManagement* cart) override{
    cout << "cart is going to saved in Mongo database" << endl;
  }
};

class FilePersistance:public DBPersistance{
  public:
  void save(CartManagement*cart) override{
    cout << "cart is going to saved in a file" << endl;
  }
};

int main(){
  CartManagement *cart = new CartManagement();

  cart->addProducts(new Product("mobile", 50000));
  cart->addProducts(new Product("bike", 60000));
  cart->addProducts(new Product("laptop", 100000));

  CartInvoicePrinter *printer = new CartInvoicePrinter(cart);
  printer->printInvoice();

  DBPersistance *db = new SQLPersistance();
  DBPersistance *mongo = new MongoPersistance();
  DBPersistance *file = new FilePersistance();

  db->save(cart);
  mongo->save(cart);
  file->save(cart);
  return 0;
}