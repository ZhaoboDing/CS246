#include <iostream>
#include <utility>
#include "bst.h"
using namespace std;

int main() {
	BST bst;

	cin >> bst;
	cin.clear();
	cin.ignore();

	char cmd;
	while(cin >> cmd) {
		switch(cmd) {
			case 'i': {
				int e;
				cin >> e;
				if (!bst.insert(e)) {
					cout << "Failed to add " << e << endl;
				}

				break;
			}

			case 'p': {
				cout << bst << endl;
				break;
			}

			case 'c': {
				BST read;
				if (cin.peek() == '=') {
					cin >> cmd;
				}

				cin >> read;
				cin.clear();
				cin.ignore();

				if (cmd == '=') {
					bst = read;
					cout << bst << endl;
				}

				else {
					BST copy{read};
					cout << copy << endl;
				}

				break;
			}

			case 'm': {
				BST read;
				if (cin.peek() == '=') {
					cin >> cmd;
				}

				cin >> read;
				cin.clear();
				cin.ignore();

				if (cmd == '=') {
					bst = move(read); // std:: from <utility>
					cout << bst << endl;;
				}

				else {
					BST dest{move(read)}; // std:: from >utility>
					cout << dest << endl;
				} // else

				break;
			} // case

		} // switch

	} // while

} // main
