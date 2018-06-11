#include <string>
#include <iostream>
#include "date.h"

int maxDayInMonth[13] = {0, 31, 28, 31, 30, 31, 30,
                          31, 31, 30, 31, 30, 31};
std::string weekdays[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
std::string months[13] = {"#", "Jan", "Feb", "Mar", "Apr", "May", "Jun",
                                 "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

bool Date::isLeapYear(int y) {
  if (y & 3)
    return false;
  else
    return y % 400 == 0 || y % 100 != 0;
}

bool Date::isValidDate(int y, int m, int d) {
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

Date::Date(int y, int m, int d) {
  year = y;
  month = m;
  day = d;
}

void Date::setDate(int y, int m, int d) {
  year = y;
  month = m;
  day = d;
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
  year = y;
}

void Date::setMonth(int m) {
  month = m;
}

void Date::setDay(int d) {
  day = d;
}

void Date::print() const {
  std::cout << weekdays[getDayOfWeek(year, month, day)] << ", ";
  std::cout << day << " ";
  std::cout << months[month] << " ";
  std::cout << year << std::endl;
}

Date &Date::nextDay() {
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
  year++;

  if (month == 2 && day == 29)
    day = 28;

  return *this;
}

Date &Date::previousYear() {
  year--;

  if (month == 2 && day == 29)
    day = 28;

  return *this;
}

