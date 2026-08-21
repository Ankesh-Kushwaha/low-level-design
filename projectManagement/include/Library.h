#ifndef LIBRARY_H
#define LIBRARY_H
#include "Member.h"
#include "Book.h"
#include <vector>


class Library{
   private:
    std:: vector<Member> members;
    std:: vector<Book> books;

  public:
    void addBook(Book book);
    void addMember(Member member);

    void showBooks();
    void showMembers();

    void issueBook(int bookId);
    void returnBook(int bookId);
};
#endif