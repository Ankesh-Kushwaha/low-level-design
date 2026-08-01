#include<bits/stdc++.h>
using namespace std;

class Account{
 public:
 virtual void deposit(double amount)=0;
 virtual void withdrawal(double amount)=0;
};

class SavingAccount:public Account{
    private:
      double balance;

    public:
    SavingAccount(){
      balance = 0;
    }

    void deposit(double amt){
      balance += amt;
      cout << amt << " :" << "is deposited to the saving Account" << endl;
    }

    void withdrawal(double amt){
      if(balance>=amt){
        balance = min(0.0, balance - amt);
        cout << amt << " :" << "is successfully withdraw from the saving account" << endl;
      }
      else{
        cout << "unable to process transaction due to insufficient balance" << endl;
      }
    }
};

class currentAccount : public Account
{
private:
  double balance;

public:
  currentAccount()
  {
    balance = 0;
  }

  void deposit(double amt)
  {
    balance += amt;
    cout << amt << " :" << "is deposited to the current Account" << endl;
  }

  void withdrawal(double amt)
  {
    if (balance >= amt)
    {
      balance = min(0.0, balance - amt);
      cout << amt << " :" << "is successfully withdraw from the current account" << endl;
    }
    else
    {
      cout << "unable to process transaction due to insufficient balance" << endl;
    }
  }
};

class FixedAccount : public Account
{
private:
  double balance;

public:
  FixedAccount()
  {
    balance = 0;
  }

  void deposit(double amt)
  {
    balance += amt;
    cout << amt << " :" << "is deposited to the fixed Account" << endl;
  }

  void withdrawal(double amt)
  {
    throw logic_error("withdrawal is not applicable in fixed term account");
  }
};

class BankCLient{
  vector<Account *> accounts;

  public:
  BankCLient(vector<Account*> accounts){
    this->accounts = accounts;
  }

  void processTransaction(){
        for(auto acc:accounts){
          acc->deposit(1000);

          try{
            acc->withdrawal(500);
          }
          catch(const logic_error& e){
            cout << "Exception :" << " " << e.what() << endl;
          }
        }
  }
};

int main(){
  vector<Account *> accounts;
  accounts.push_back(new SavingAccount());
  accounts.push_back(new currentAccount());
  accounts.push_back(new FixedAccount());

  BankCLient *client =new BankCLient(accounts);
  client->processTransaction();

  return 0;
}