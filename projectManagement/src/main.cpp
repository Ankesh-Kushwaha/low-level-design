#include "../include/Library.h"
#include<iostream>

int main(){
  Library *library = new Library();

  Book book1(
      101,
      "Clean Code",
      "Robert Martin");

  Book book2(
      102,
      "The Pragmatic Programmer",
      "Andrew Hunt");

  Member member1(
      1,
      "Ankesh");

  Member member2(
      2,
      "Rahul");

  library->addBook(book1);
  library->addBook(book2);

  library->addMember(member1);
  library->addMember(member2);

  library->issueBook(102);

  library->showBooks();
  library->showMembers();
  library->returnBook(102);
  library->showBooks();

  delete library;
  return 0;
}