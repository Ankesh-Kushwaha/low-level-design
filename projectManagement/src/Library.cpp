#include "../include/Library.h"
#include<iostream>
using namespace std;

void Library::addBook(Book book){
  books.push_back(book);
} 

void Library::addMember(Member member){
  members.push_back(member);
}

void Library::issueBook(int bookId){
      for(auto &book:books){
           if(book.getId()==bookId){
              if(book.isIssused()){
                cout << "Book is already issused not available" << endl;
                return;
              }
              book.issueBook();
              cout << "Book issussed successfully" << endl;
              return;
           }
      }
}

void Library:: returnBook(int bookId){
     for(auto &book:books){
         if(book.getId()==bookId){
             if(!book.isIssused()){
               cout << "book is never issued" << endl;
             }

             book.returnBook();
             cout << "Book returned successfully" << endl;
             return;
         }
     }
}

void Library:: showBooks(){
  cout << "showing all stocks book" << endl;
  for (auto book : books)
  {
    book.display();
    cout << endl;
  }
}

void Library:: showMembers(){
  cout << "Showing all active members of the library" << endl;
  for(auto member:members){
    member.display();
    cout << endl;
  }
}