#include <iostream>
#include <stdexcept>
#include <string>
#include "date.h"

using namespace std;

const int MAX=10;

int main(){ // Test harness for Date functions
    Date *dates[MAX];
    for (int i = 0; i < MAX; ++i){
		dates[i]=nullptr;
	}

	bool done = false;

	string command;
	char which; // reads in an character from a-j
	int year, month, day;
	bool leapYear, validDate;

	while (!done) {
		cin >> command;

		if (cin.eof()) break;
		if (command == "n") {
			cin >> which;
			cin >> year >> month >> day;
			try {

				if (dates[which - 'a']){
					delete dates[which - 'a'];
				}

				dates[which - 'a'] = new Date(year, month, day);
			} catch (out_of_range &ex) {
				cout << "An exception was caught." << endl;
                cerr << ex.what() << endl;
                delete dates[which - 'a'];
                dates[which - 'a'] = nullptr;
			}
		} else if (command == "s") {
			cin >> which >> year >> month >> day;
			if (!dates[which - 'a']){
				cout << "Invalid input." << endl;
				continue;
			}
			try {
				dates[which - 'a']->setDate(year, month, day);
			} catch (out_of_range &ex){
                cout << "An exception was caught." << endl;
                cerr << ex.what() << endl;
                delete dates[which - 'a'];
                dates[which - 'a'] = nullptr;
			}
		} else if (command == "sy") {
			cin >> which >> year;
			if (!dates[which - 'a']){
				cout << "Invalid input." << endl;
				 continue;
			}
			try {
				dates[which - 'a']->setYear(year);
			} catch (out_of_range &ex) {
                cout << "An exception was caught." << endl;
                cerr << ex.what() << endl;
                delete dates[which - 'a'];
                dates[which - 'a'] = nullptr;
			}
		} else if (command == "sm") {
			cin >> which >> month;
			if (!dates[which - 'a']){ 
                cout << "Invalid input." << endl; 
                 continue;
            }
			try {
				dates[which - 'a']->setMonth(month);
			} catch (out_of_range &ex){
                cout << "An exception was caught." << endl;
                cerr << ex.what() << endl;
                delete dates[which - 'a'];
                dates[which - 'a'] = nullptr;
			}
		} else if (command == "sd") {
			cin >> which >> day;
			if (!dates[which - 'a']){ 
                cout << "Invalid input." << endl; 
                 continue;
            }
			try {
				dates[which - 'a']->setDay(day);
			} catch (out_of_range &ex) {
                cout << "An exception was caught." << endl;
                cerr << ex.what() << endl;
                delete dates[which - 'a'];
                dates[which - 'a'] = nullptr;
			}
		} else if (command == "ly") {
			cin >> year;
			leapYear = Date::isLeapYear(year);
			if (leapYear) {
				cout << year << " is a leap year." << endl;
			} else {
				cout << year << " is not a leap year." << endl;
			}
		} else if (command == "vd") {
			cin >> year >> month >> day;
			validDate = Date::isValidDate(year, month, day);
			cout << year << ", " << month << " " << day;
			if (validDate) {
				cout << " is a valid date." << endl;
			} else {
				cout << " is not a valid date." << endl;
			}
		} else if (command == "gy") {
			cin >> which;
			if (!dates[which - 'a']){ 
                cout << "Invalid input." << endl; 
                 continue;
            }
			cout << dates[which - 'a']->getYear() << endl;
		} else if (command == "gm") {
			cin >> which;
			if (!dates[which - 'a']){ 
                cout << "Invalid input." << endl; 
                 continue;
            }
			cout << dates[which - 'a']->getMonth() << endl;
		} else if (command == "gd") {
			cin >> which;
			if (!dates[which - 'a']){ 
                cout << "Invalid input." << endl; 
                 continue;
            }
			cout << dates[which - 'a']->getDay() << endl;
		} else if (command == "+d") {
			cin >> which;
			if (!dates[which - 'a']){ 
                cout << "Invalid input." << endl; 
                 continue;
            }
			try {
				*dates[which - 'a'] = dates[which - 'a']->nextDay();
			} catch (out_of_range &ex) {
					cout << "An exception was caught." << endl;
					cerr << ex.what() << endl;
					delete dates[which - 'a'];
					dates[which - 'a'] = nullptr;
			}
		} else if(command == "-d") {
            cin >> which;
            if (!dates[which - 'a']){ 
                cout << "Invalid input." << endl; 
                 continue;
            }
			try {
                *dates[which - 'a'] = dates[which - 'a']->previousDay();
            } catch (out_of_range &ex) {
					cout << "An exception was caught." << endl;
                    cerr << ex.what() << endl;
                    delete dates[which - 'a'];
                    dates[which - 'a'] = nullptr;
            }
		} else if (command == "+m") {
			cin >> which;
            if (!dates[which - 'a']){ 
                cout << "Invalid input." << endl; 
                 continue;
            }
			try {
                *dates[which - 'a'] = dates[which - 'a']->nextMonth();
            } catch (out_of_range &ex) {
					cout << "An exception was caught." << endl;
                    cerr << ex.what() << endl;
                    delete dates[which - 'a'];
                    dates[which - 'a'] = nullptr;
            }
		} else if (command == "-m") {
			cin >> which;
            if (!dates[which - 'a']){ 
                cout << "Invalid input." << endl; 
                 continue;
            }
			try {
                *dates[which - 'a'] = dates[which - 'a']->previousMonth();
			} catch (out_of_range &ex) {
                    cout << "An exception was caught." << endl;
                    cerr << ex.what() << endl;
                    delete dates[which - 'a'];
                    dates[which - 'a'] = nullptr;
            }
        } else if (command == "+y") {
			cin >> which;
            if (!dates[which - 'a']){ 
                cout << "Invalid input." << endl; 
                 continue;
            }
			try {
                *dates[which - 'a'] = dates[which - 'a']->nextYear();
			} catch (out_of_range &ex) {
                    cout << "An exception was caught." << endl;
                    cerr << ex.what() << endl;
                    delete dates[which - 'a'];
                    dates[which - 'a'] = nullptr;
            }
        } else if (command == "-y") {
            cin >> which;
            if (!dates[which - 'a']){ 
                cout << "Invalid input." << endl; 
                 continue;
            }
			try {
                *dates[which - 'a'] = dates[which - 'a']->previousYear();
			} catch (out_of_range &ex) {
                    cout << "An exception was caught." << endl;
                    cerr << ex.what() << endl;
                    delete dates[which - 'a'];
                    dates[which - 'a'] = nullptr;
            }
        } else if (command == "p") {
			cin >> which;
			if (!dates[which - 'a']){ 
                cout << "Invalid input." << endl; 
                 continue;
            }
			dates[which - 'a']->print();
		} else if (command == "q") {
			done = true;
		}
	}

	for (int i = 0; i < MAX; ++i){
		delete dates[i];
	}
}
