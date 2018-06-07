#include "textbook.h"
#include <string>
using namespace std;


TextBook::TextBook(string title, string author, int numPages, string topic):
  Book(title, author, numPages), topic(topic) {}
string TextBook::getTopic() const { return topic; }

bool TextBook::isItHeavy() const{return getNumPages() > 400;}
bool TextBook::favourite() const{return topic == "Thermonuclear Astrophysics";}
