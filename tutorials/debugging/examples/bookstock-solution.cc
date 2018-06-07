#include <iostream>

class Book {
  std::string title_, author_;
  int numPages_;

  public:
    Book(std::string title, std::string author, int numPages)
        :title_(title), author_(author), numPages_(numPages) {}

    int numPages() const { return numPages_; }
    std::string title() const { return title_; }
    std::string author() const { return author_; }

    void title(std::string title) { title_ = title; }
    void author(std::string author) { author_ = author; }
    void numPages(int numPages) { numPages_ = numPages; }
};

class AntiqueBook : public Book {
  int year_;
  int value_;

  public:
    AntiqueBook(std::string title, std::string author, int numPages, int year, int value)
               :Book(title, author, numPages), year_(year), value_(value) {}

    int year() const { return year_; }
    int value() const { return value_; }

    void year(int year) { year_ = year; }
    void value(int value) { value_ = value; }
};

class BookStock {
  const Book & theBook_;
  int numCopies_;

  public:
    BookStock(const Book &b, int numCopies):theBook_(b), numCopies_(numCopies) {}
    Book &theBook() { return const_cast<Book&>(theBook_); }
    const Book &theBook() const { return theBook_; }

    int numCopies() const { return numCopies_; }
    void numCopies(int numCopies) { numCopies_ = numCopies; }
};

std::ostream &operator<<(std::ostream &out, const BookStock &stock) {
  out << "Currently stocking: " << stock.theBook().title()
      << " by " << stock.theBook().author()
      << " with " << stock.theBook().numPages() << " pages. "
      << "There are currently " << stock.numCopies() << " copies in stock.";
  return out;
}

int main() {
  AntiqueBook odyssey("Odyssey", "Homer", 500, -760, 500);
  BookStock odysseyStock(odyssey, 10);

  std::cout << odysseyStock << std::endl;

  //We want to change the book to the Iliad
  //We know that odysseyStock is stocking an AntiqueBook,
  //so we can use static_cast.
  //There are 20 copies of the Iliad in stock.
  odysseyStock.numCopies(20);
  //static_cast<AntiqueBook&> is the same as (AntiqueBook&):
  //it just tells C++ to treat the Book& as an AntiqueBook&
  AntiqueBook &iliad = static_cast<AntiqueBook&>(odysseyStock.theBook());
  iliad.title("Iliad");
  iliad.numPages(400);
  iliad.year(-740);
  iliad.value(300);

  std::cout << odysseyStock << std::endl;

  return 0;
}
