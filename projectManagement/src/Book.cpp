#include "../include/Book.h"
#include<iostream>
#include<string>
using namespace std;


Book::Book(int id,string name,string author){
  this->id = id;
  this->name = name;
  this->author = author;
  this->issuse= false;
}

int Book:: getId()const{
  return this->id;
}

string Book:: getname()const{
  return this->name;
}

string Book::getAuthor()const{
  return this->author;
}

bool Book::isIssused()const{
  return this->issuse;
}

void Book::issueBook(){
  this->issuse = true;
}

void Book::returnBook(){
  this->issuse = false;
}

void Book::display(){
  cout << "BookId: " << this->id
       << "| Title :" << this->name
       << "| Author: " << this->author
       <<"| status: "<<(this->issuse ? "issused" :"available")
       << endl;
}