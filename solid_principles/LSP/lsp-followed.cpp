#include<iostream>
#include<vector>
using namespace std;

class nonwithdrawableAccount{
   public:
     virtual void deposit(double amount) = 0;
};

class withdrawableAccount:public nonwithdrawableAccount{
   public:
     virtual void withdraw(double amount) = 0;
};

class savingAccount:public withdrawableAccount{
  private:
    double balance;
  public:

  savingAccount(){
   this->balance = 0;
  }

  void deposit(double amount){
    this->balance += amount;
    cout << amount << ": is deposited to saving account" << endl;
  }

  void withdraw(double amount){
     if(this->balance>=amount){
       this->balance = max(0.0,balance-amount);
       cout << amount << ": is withdraw from the saving account" << endl;
     }
  }
};

class currentAccount : public withdrawableAccount
{
private:
  double balance;

public:
  currentAccount()
  {
    this->balance = 0;
  }

  void deposit(double amount)
  {
    this->balance += amount;
    cout << amount << ": is deposited to current account" << endl;
  }

  void withdraw(double amount)
  {
    if (this->balance >= amount)
    {
      this->balance = max(0.0, balance - amount);
      cout << amount << ": is withdraw from the current account" << endl;
    }
  }
};

class FixedAccount:public nonwithdrawableAccount{
  private:
    double balance;
  public:

  FixedAccount(){
    this->balance = 0;
  }

  void deposit(double amount){
    balance += amount;
    cout << amount << ": is successfully deposited to the fixed account" << endl;
  }
};

class BankClient{
  private:
    vector<nonwithdrawableAccount *> depositonlyAccount;
    vector<withdrawableAccount *> depositandwithdrawAccount;
  
  public:
  BankClient(vector<nonwithdrawableAccount*> depositonlyAccount, vector<withdrawableAccount*> depositandwithdrawAccount){
    this->depositonlyAccount = depositonlyAccount;
    this->depositandwithdrawAccount = depositandwithdrawAccount;
  }

  void processTransaction(){
     for(auto &acc:depositandwithdrawAccount){
       acc->deposit(1000);
       acc->withdraw(500);
     }

     for(auto &acc:depositonlyAccount){
       acc->deposit(1000);
     }
  }
};

int main(){
  vector<withdrawableAccount *> depositandWithdrawAccount;
  vector<nonwithdrawableAccount *> depositOnlyAccount;

  depositandWithdrawAccount.push_back(new savingAccount());
  depositandWithdrawAccount.push_back(new currentAccount());
  depositOnlyAccount.push_back(new FixedAccount());

  BankClient *client = new BankClient(depositOnlyAccount,depositandWithdrawAccount);
  client->processTransaction();
  return 0;
}