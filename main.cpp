#include "Pencil.h"

using namespace std;


int main() {
	std::ios_base::sync_with_stdio(false); //speed up for inputs and outputs
	cout << "Starting Pencil simulator" << endl; //initializing program, display all options
	cout << "Type 'help' for options" << endl;
	cout << "Type 'write' followed by a string to append to paper | example: 'write hello' to write 'hello' onto paper" << endl;
	cout << "Type 'erase' followed by a string to erase from paper | example: 'erase hello' to erase 'hello' from paper" << endl;
	cout << "Type 'print' or 'show' to show what's on the paper" << endl;
	cout << "Type 'quit' to close the pencil simulator" << endl;
	string paper;
	vector<pencil> pencils;
	while (true) { //accepts inputs until "quit" is called, then close application
		cout << "Enter a command: ";
		string command;
		cin >> command;
		if (command == "write") { //call write function to add input to paper
			string input;	
			getline(cin, input);
			input.erase(0,1);
			cout << "Pencil wrote: " << input << endl;
			//write(paper, input);
		}
		if (command == "erase") {
			string input;
			getline(cin, input);
			input.erase(0,1);
			cout << "Erasing: " << input << endl;
			erase(paper, input);
		}
		if (command == "print" || command == "show") { //print or show paper
			cout << "Paper content: " << paper << endl;
		}
		if (command == "help") { //display all options
			cout << "Type 'write' followed by a string to append to paper | example: 'write hello' to write 'hello' onto paper" << endl;
			cout << "Type 'erase' followed by a string to erase from paper | example: 'erase hello' to erase 'hello' from paper" << endl;
			cout << "Type 'print' or 'show' to show what's on the paper" << endl;
			cout << "Type 'quit' to close the pencil simulator" << endl;
		}
		if (command == "quit") {
			cout << "Closing Pencil Simulator..." << endl;
			break;
		}
	}
	return 0;
}