#ifndef BOOK_H
#define BOOK_H 
#include<string>

class Book{
   private:
     int id;
     std::string name;
     std::string author;
     bool issuse;

  public:
    Book(int id, std::string name, std::string author);

    int getId() const;
    std::string getname() const;
    std::string getAuthor() const;
    bool isIssused() const;

    void issueBook();
    void returnBook();
    void display();
};

#endif
