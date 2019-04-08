#include "Pencil.h"
#include <iostream>

using namespace std;


int main() {
	std::ios_base::sync_with_stdio(false); //speed up for inputs and outputs
	cout << "Starting Pencil simulator" << endl;
	cout << "type 'help' for options" << endl;
	string paper;
	while (true) { //accepts inputs until "quit" is called, then close application
		cout << "enter a command:" << endl;
		string command;
		cin >> command;
		if (command == "write") {
			cout << "write selected, enter a string: ";
			string input;
			getline(cin, input);
			write(paper, input);
		}
		if (command == "print") {
			cout << "Paper content: " << paper << endl;
		}
		if (command == "help") {
			cout << "Type 'write' followed by a string to append to paper" << endl;
			cout << "Type 'print' to show what's on the paper" << endl;
			cout << "Type 'quit' to close the pencil simulator" << endl;
		}
		if (command == "quit") {
			cout << "Closing Pencil Simulator..." << endl;
			break;
		}
	}
	return 0;
}