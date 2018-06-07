#include "comic.h"
#include <string>
using namespace std;

Comic::Comic(string title, string author, int numPages, string protag):
  Book(title, author, numPages), protag(protag) {}

string Comic::getProtagonist() const { return protag; }

bool Comic::isItHeavy() const {return getNumPages() > 30;}

bool Comic::favourite() const { return protag == "Deadpool"; }
