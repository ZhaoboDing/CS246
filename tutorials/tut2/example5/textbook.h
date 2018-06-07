#ifndef TEXTBOOK_H
#define TEXTBOOK_H
#include <string>
#include "book.h"

class TextBook: public Book {
  std::string topic;
 public:
  TextBook(std::string title, std::string author, int numPages, std::string topic);
  std::string getTopic() const;
  bool isItHeavy() const;
  bool favourite() const;
};

#endif
