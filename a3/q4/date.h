/* Header for the Date class (date.h) */
#ifndef DATE_H
#define DATE_H

#include <string>

class Date {
private:     // year should be between 1753-9999
    // You may add private fields and methods as you see fit
    // Do *not* change the provided methods.
  
  

public:
  static bool isLeapYear(int y);

  static bool isValidDate(int y, int m, int d); 

  // A static function that returns the day of the week
  // (0:Sun, 6:Sat) for the given date Wiki "Determination
  // of the day of the week" for the algorithm, it is also
  // provided as a pdf file for your convenience.
  static int getDayOfWeek(int y, int m, int d); 

  // With input validation
  Date(int y, int m, int d);

  // With input validation
  void setDate(int y, int m, int d);
  
  int getYear() const;
  int getMonth() const;
  int getDay() const;  

  void setYear(int y);
  void setMonth(int m);
  void setDay(int d);// Assuming that the year and month are 
                       // already set

  // Print this instance in the format "xxxday, dd mmm yyyy". 
  // where
  // - xxx is the day of the week, possible values are
  //   {Sun, Mon, Tue, Wed, Thu, Fri, Sat}
  // - dd is the day of the month, in digits
  // - mmm is the month, possible values are
  //    {Jan, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, 
  //                                                      Dec}
  // - yyyy is the year.
  void print() const; 

  Date &nextDay(); // Increment this instance to the next day 
                   //  and return this
                   // instance by reference
  Date &previousDay(); // Decrement this instance to the 
                       // previous day and return
                       // this instance by reference
  Date &nextMonth();   // Increment this instance to the next 
                       // month and return
                       // this instance by reference
  Date &previousMonth(); // Decrement this instance to the 
                         // previous month and
                         // return this instance by reference
  Date &nextYear(); // Increment this instance to the next year 
                    // and return this
                    // instance by reference
  Date &previousYear(); // Decrement this instance to the
                        // previous year and
                        // return this instance by reference
};

#endif


