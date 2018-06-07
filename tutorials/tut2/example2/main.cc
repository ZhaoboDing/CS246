#include <iostream>
#include <string>
#include "book.h"
#include "textbook.h"
#include "comic.h"
using namespace std;

// Polymorphism in action.
void printMyFavourites(Book *myBooks[], int numBooks) {
  for (int i=0; i < numBooks; ++i) {
    if (myBooks[i]->favourite()) cout << myBooks[i]->getTitle() << endl;
  }
}

int main() {
  Book* collection[6];

  collection[0] = new Book("War and Peace", "Tolstoy", 5000);
  collection[1] = new Book("Peter Rabbit", "Potter", 50);
  collection[2] = new TextBook("Programming for Beginners", "??", 200, "BASIC");
  collection[3] = new TextBook("Learning Thermonuclear Astrophysics in an Evening", "??", 200, "Thermonuclear Astrophysics");
  collection[4] = new Comic("Aquaman Swims Again", "??", 20, "Aquaman");
  collection[5] = new Comic("Deadpool Classic, Vol. 1", "Fabian Nicieza and Joe Kelly", 20, "Deadpool");

  printMyFavourites(collection, 6);
  for (int i=0; i < 6; ++i) delete collection[i];
}
