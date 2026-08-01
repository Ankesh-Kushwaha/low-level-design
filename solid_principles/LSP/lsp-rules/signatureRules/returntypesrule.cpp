#include<bits/stdc++.h>
using namespace std;

// Return Type Rule :
// Subtype overriden method return type should be either identical
// or narrower then the parent method's return type.
// This is also called as return type covariance.
// C++ enforces this by covariance.

class Animal{
   //some common methods for animal
};

class Dog:public Animal{
   //all animal method but some additional features for the dog
};

class Parent{
  public:
    virtual Animal* getAnimal(){
      cout << "getting animal instance" << endl;
      return new Animal();
    }
};

class Child:public Parent{
  public:
   Animal* getAnimal(){
    cout << "getting dog instances" << endl;
    return new Dog();
  }
};

class Client{
  private:
    Parent *p;
  public:
  Client(Parent* p){
    this->p = p;
  }

  void getAnimal(){
    this->p->getAnimal();
  }
};

int main(){
  Parent *p = new Parent();
  Child *c = new Child();

  Client *ci = new Client(c);
  ci->getAnimal();
  return 0;
}