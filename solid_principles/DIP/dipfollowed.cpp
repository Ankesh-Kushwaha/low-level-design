#include<bits/stdc++.h>
using namespace std;

class Database{
  public:
    virtual void save(string data) = 0;
};

class MongoPersistance:public Database{
    public:
    void save(string data){
      cout << "data insert query is executed for mongo: User.create({data})" << endl;
    }
};

class SQLPersistance:public Database{
  public:
  void save(string Data){
    cout << "Data insert query is executed for sql: INSERT INTO USERS (data)" << endl;
  }
};

class UserService{
  Database *db;

  public:
  UserService(Database* db){
    this->db = db;
  }

  void saveData(string data){
    db->save(data);
  }
};

int main(){
  MongoPersistance mongo;
  SQLPersistance sql;

  UserService *service1 = new UserService(&mongo);
  service1->saveData("Ankesh");
  UserService service2(&sql);
  service2.saveData("ankesh");
  return 0;
}