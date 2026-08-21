#ifndef MEMBER_H
#define MEMBER_H
#include<iostream>

class Member{
   private:
     int id;
     std::string name;
  
  public:
   Member(int id, std::string name);

    int getId();
    std::string getname();
    void display();
};


#endif