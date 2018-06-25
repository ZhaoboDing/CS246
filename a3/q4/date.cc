#include <string>
#include <iostream>
#include "date.h"

int maxDayInMonth[13] = {0, 31, 28, 31, 30, 31, 30,
                          31, 31, 30, 31, 30, 31}; // The maximum days in a month in non-leap year
std::string weekdays[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
// Name of each weekday
std::string months[13] = {"#", "Jan", "Feb", "Mar", "Apr", "May", "Jun",
                                 "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
// Name of each month

bool Date::isLeapYear(int y) {
  if (y & 3)
    return false;
  else
    return y % 400 == 0 || y % 100 != 0;
}

bool Date::isValidDate(int y, int m, int d) {
  if (y < 1753 || y > 9999) return false; // As is required in .h file
  if (isLeapYear(y) && m == 2 && d == 29)
    return true;
  else
    return (m >= 1) && (m <= 12) && (d >= 1) && (d <= maxDayInMonth[m]);
}

int Date::getDayOfWeek(int y, int m, int d) {
  m = (m + 9) % 12 + 3;
  y = y - m / 13;
  int c = y / 100;
  y %= 100;

  int w = (y + y / 4 + c / 4 - 2 * c + 26 * (m + 1) / 10 + d - 1) % 7;
  if (w >= 0)
    return w;
  else
    return w + 7;
}

Date::Date(int y, int m, int d): year{y}, month{m}, day{d} {}

void Date::setDate(int y, int m, int d) {
  if (isValidDate(y, m ,d)) {
    year = y;
    month = m;
    day = d;
  }
  else
    throw std::out_of_range("The date is invalid.");
}

int Date::getYear() const {
  return year;
}

int Date::getMonth() const {
  return month;
}

int Date::getDay() const {
  return day;
}

void Date::setYear(int y) {
  if (isValidDate(y, month, day))
    year = y;
  else
    throw std::out_of_range("The date is invalid.");
}

void Date::setMonth(int m) {
  if (isValidDate(year, m, day))
    month = m;
  else
    throw std::out_of_range("The date is invalid.");
}

void Date::setDay(int d) {
  if (isValidDate(year, month, d))
    day = d;
  else
    throw std::out_of_range("The date is invalid.");
}

void Date::print() const {
  std::cout << weekdays[getDayOfWeek(year, month, day)] << ", ";
  std::cout << day << " ";
  std::cout << months[month] << " ";
  std::cout << year << std::endl;
}

// For every function below, we must specially consider Feb 29th for a leap year

Date &Date::nextDay() {
  if (year == 9999 && month == 12 && day == 31)
    throw std::out_of_range("The next day is invalid.");

  day++;
  if (day > maxDayInMonth[month])
    if (!(isLeapYear(year) && month == 2 && day == 29)) {
      day = 1;
      month++;
      if (month > 12) {
        month = 1;
        year++;
      }
    }

  return *this;
}

Date &Date::previousDay() {
  if (year == 1753 && month == 1 && day == 1)
    throw std::out_of_range("The previous day is invalid.");

  day--;
  if (day < 1)
    if (isLeapYear(year) && month == 3 && day == 0) {
      day = 29;
      month = 2;
    }
    else {
      month--;
      if (month < 1) {
        month = 12;
        year--;
      }
      day = maxDayInMonth[month];
    }
  else {};

  return *this;
}

Date &Date::nextMonth() {
  if (year == 9999 && month == 12)
    throw std::out_of_range("The next month is invalid.");

  month++;
  if (month > 12) {
    month = 1;
    year++;
  }

  if (day > maxDayInMonth[month])
    if (isLeapYear(year) && month == 2)
      day = 29;
    else
      day = maxDayInMonth[month];
  else {};

  return *this;
}

Date &Date::previousMonth() {
  if (year == 1753 && month == 1)
    throw std::out_of_range("The previous year is invalid.");

  month--;
  if (month < 1) {
    month = 12;
    year--;
  }

  if (day > maxDayInMonth[month])
    if (isLeapYear(year) && month == 2)
      day = 29;
    else
      day = maxDayInMonth[month];
  else {};

  return *this;
}

Date &Date::nextYear() {
  if (year == 9999)
    throw std::out_of_range("The next year is invalid.");

  year++;
  if (month == 2 && day == 29)
    day = 28;

  return *this;
}

Date &Date::previousYear() {
  if (year == 1753)
    throw std::out_of_range("The previous year is invalid.");
  year--;

  if (month == 2 && day == 29)
    day = 28;

  return *this;
}

