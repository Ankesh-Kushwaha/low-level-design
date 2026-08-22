#include<bits/stdc++.h>
using namespace std;

class Burger{
   public:
     virtual void prepare() = 0;
};

//product 1
class BasicBurger:public Burger{
  public:
  void prepare()override{
    cout << "preparing a basic burger" << endl;
  }
};

class StandardBurger:public Burger{
  public:
  void prepare() override{
    cout << "preparing a standard burger" << endl;
  }
};

class PremiumBurger:public Burger{
  public:
  void prepare()override{
    cout << "preparing a premium burger" << endl;
  }
};


class BasicwheatBurger:public Burger{
  public:
   void prepare() override{
     cout << "preparing a basic wheat burger" << endl;
   }
};

class StandardWheatBurger:public Burger{
  public:
  void prepare() override{
    cout << "Preparing a standard wheat burger" << endl;
  }
};

class PremiumWheatBurger:public Burger{
  public:
  void prepare() override{
    cout << "preparing a premium wheat burger" << endl;
  }
};

// product 2;
class GarlicBurger{
   public:
    virtual void prepare() = 0;
};

class BasicGarlicBurger:public GarlicBurger{
  public:
  void prepare() override{
    cout << "preparing a basic garilc burger" << endl;
  }
};

class StandardGarlicBurger:public GarlicBurger{
  public:
  void prepare() override{
    cout << "preparing a standard garlic burger" << endl;
  }
};

class PremiumGarlicBurger:public GarlicBurger{
  public:
  void prepare() override{
    cout << "preparing a premium garlic burger" << endl;
  }
};


class MealFactory{
  public:
    virtual Burger *createBurger(string type) = 0;
    virtual GarlicBurger *createrGarlicBurger(string type) = 0;
};

class KingBurger:public MealFactory{
  public:
  Burger* createBurger(string type){
     if(type=="basic"){
       return new BasicwheatBurger();
     }
     else if(type=="standard"){
       return new StandardWheatBurger();
     } 
     else if(type=="premium"){
       return new PremiumWheatBurger();
     }
     else{
       cout << "invalid:: burger type" << endl;
       return nullptr;
     }
  }

  GarlicBurger* createrGarlicBurger(string type){
      if(type=="basic"){
        return new BasicGarlicBurger();
      }
      else if(type=="standard"){
        return new StandardGarlicBurger();
      }
      else if(type=="premium"){
        return new PremiumGarlicBurger();
      }
      else{
        cout << "invalid:: Burger type" << endl;
        return nullptr;
      }
  }
};

class SinghBurger:public MealFactory{
   Burger* createBurger(string type) override{
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
        cout << "invalid:: Burger type" << endl;
        return nullptr;
      }
   }

   GarlicBurger* createrGarlicBurger(string type){
      if(type=="basic"){
        return new BasicGarlicBurger();
      }
      else if(type=="standard"){
        return new StandardGarlicBurger();
      }
      else if(type=="premium"){
        return new PremiumGarlicBurger();
      }
      else{
        cout << "invalid:: Burger type" << endl;
        return nullptr;
      }
   }
};

int main(){
  MealFactory *factory = new KingBurger();
  MealFactory *factory2 = new SinghBurger();

  string type = "premium";

  Burger *burger = factory->createBurger(type);
  GarlicBurger *burger2 = factory->createrGarlicBurger(type);

  burger->prepare();
  burger2->prepare();
  delete factory;
  delete factory2;
  return 0;
}
