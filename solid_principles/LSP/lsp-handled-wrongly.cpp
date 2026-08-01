#include<bits/stdc++.h>
using namespace std;

class Account{
  public:
    virtual void deposit(double amount) = 0;
    virtual void withdrawal(double amount) = 0;
};

class savingAccount:public Account{
  private:
    double balance;
  public:

  savingAccount(){
    balance = 0;
  }

  void deposit(double amount){
    balance += amount;
    cout << amount << " :is successfully deposit to saving account" << endl;
  }

  void withdrawal(double amount){
    if(balance>=amount){
      balance = max(0.0, balance - amount);
      cout << amount << " :is successfully withdraw from saving account" << endl;
    }
    else{
      cout << "insufficienr fund.declined" << endl;
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

  void deposit(double amount)
  {
    balance += amount;
    cout << amount << " :is successfully deposit to current account" << endl;
  }

  void withdrawal(double amount)
  {
    if (balance >= amount)
    {
      balance = max(0.0, balance - amount);
      cout << amount << " :is successfully withdraw from current account" << endl;
    }
    else
    {
      cout << "insufficienr fund.declined" << endl;
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

  void deposit(double amount)
  {
    balance += amount;
    cout << amount << " :is successfully deposit to fixed account" << endl;
  }

  void withdrawal(double amount)
  {
    throw logic_error("cannot withdraw from fixed account");
  }
};


//change the client side implementation but it violet the open close principle so that it is not recommended
//we  hard bind our interface to the client which is wrong.
class BankClient{
  vector<Account *> accounts;
  public:

  BankClient(vector<Account*> accounts){
    this->accounts = accounts;
  }

  void processTransaction(){
      for(auto &acc:accounts){
        acc->deposit(1000);

        if (typeid(*acc) == typeid(FixedAccount))
        { // if account is fixed term account skip the withdrawal
          cout << "fixed account no withdrawal" << endl;
        }
        else{
          try{
            acc->withdrawal(500);
          }
          catch(const logic_error& e){
            cout << "error: " << e.what() << endl;
          }
        }
      }
  }
};

int main(){
  vector<Account *> accounts;

  for (int i = 0; i <= 1000;i++){
    accounts.push_back(new savingAccount());
    accounts.push_back(new currentAccount());
    accounts.push_back(new FixedAccount());
  }


  BankClient *client = new BankClient(accounts);
  client->processTransaction();

  return 0;
}