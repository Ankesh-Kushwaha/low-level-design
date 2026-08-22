#include<bits/stdc++.h>
using namespace std;

class Burger{
  public:
  virtual void prepare() = 0;
};

class BasicBurger:public Burger{
  public:
   void prepare()override{
     cout << "preparing basic burger" << endl;
   }
};

class StandardBurger:public Burger{
  public:
   void prepare() override{
     cout << "preparing standard burger" << endl;
   }
};

class PremiumBurger:public Burger{
  public:
  void prepare() override{
    cout << "Preparing premium burger" << endl;
  }
};

class BurgerFactory{
  public:
  Burger* createBurger(string type){
     if(type=="basic"){
       return new BasicBurger();
     }
     else if(type=="standard"){
       return new StandardBurger();
     }
     else if(type=="premium"){
       return new PremiumBurger();
     }
     else{
       return NULL;
     }
  }
};

int main(){
  string type = "basic";
  string type1 = "standard";
  string type3 = "premium";
  BurgerFactory *factory = new BurgerFactory();

  Burger* burger=factory->createBurger(type3);
  burger->prepare();

  return 0;
}