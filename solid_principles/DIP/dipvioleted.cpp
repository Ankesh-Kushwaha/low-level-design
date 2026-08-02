#include<bits/stdc++.h>
using namespace std;

class saveToMongoDB{ //low level module deal with the database
  public:
  void save(string data){
    cout << "executing query for mongoDB insert: User.create({data})" << endl;
  }
};

class saveToSQL{ //low level module deal with the database
  public:
    void save(string data){
      cout << "executing query for SQL insert: INSERT INTO USER (data)" << endl;
    }
};

//what happens if we have to save data in a file then we have to made changes in the userService which breaks the open-close principle

class UserService{ //high level modulw deal with the bussiness logic
  private:
    saveToMongoDB mongo; // thightly coupled with the low - level design;
    saveToSQL sql;
  
  public:
  void saveTomongo(string data){
    mongo.save(data);
  }

  void saveToSql(string data){
    sql.save(data);
  }
};

int main(){
  UserService service;
  service.saveTomongo("ankesh");
  service.saveToSql("ankesh");
  return 0;
}