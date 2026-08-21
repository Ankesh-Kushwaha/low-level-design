#include "../include/Member.h"
#include<iostream>
#include<string>
using namespace std;

Member::Member(int id,string name){
  this->id = id;
  this->name = name;
}

int Member::getId(){
  return this->id;
}

string Member::getname(){
  return this->name;
}

void Member::display(){
  cout << "Member_id: " << this->id
       << "Member_name: " << this->name
       << endl;
}