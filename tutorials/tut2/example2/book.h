#ifndef BOOK_H
#define BOOK_H
#include <string>


class Book {
  std::string title, author;
  int numPages;
 protected:
  int getNumPages() const;
 public:
  Book(std::string title, std::string author, int numPages);
  std::string getTitle() const;
  std::string getAuthor() const;
  virtual bool isItHeavy() const;
  virtual bool favourite() const;
  virtual ~Book() = default;
};

#endif

