#include<iostream>
using namespace std;

class Burger{
 public:
   virtual void prepare()=0;
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

class PremimumBurger:public Burger{
  public:
  void prepare() override{
    cout << "preparing premium burger" << endl;
  }
};

class BasicWeatBurger:public Burger{
   public:
   void prepare() override{
     cout << "preparing basic wheat burger" << endl;
   }
};

class StandardWeatBurger:public Burger{
  public:
  void prepare() override{
    cout << "preparing standard wheat burger" << endl;
  }
};

class PremiumWheatBurger:public Burger{
  void prepare(){
    cout << "preparing premium wheat burger" << endl;
  }
};

class BurgerFactory{
   public:
     virtual Burger *createBurger(string type) = 0;
};

class SinghBurger:public BurgerFactory{
  public:
   Burger* createBurger(string type) override{
        if(type=="basic"){
          return new BasicBurger();
        }
        else if(type=="standard"){
          return new StandardBurger();
        }
        else if(type=="premium"){
          return new PremimumBurger();
        }
        else{
          cout << "Invalid :: type of burger" << endl;
          return nullptr;
        }
   }
};


class KingBurger:public BurgerFactory{
   public:
    Burger* createBurger(string type) override{
      if(type=="basic"){
        return new BasicWeatBurger();
      }
      else if(type=="standard"){
        return new StandardWeatBurger();
      }
      else if(type=="premium"){
        return new PremiumWheatBurger();
      }
      else{
        cout << "invalid:: type of buger" << endl;
        return nullptr;
      }
    }
};


int main(){
  BurgerFactory *factory = new SinghBurger();
  string type = "basic";

  Burger *burger = factory->createBurger(type);
  burger->prepare();
  return 0;
}