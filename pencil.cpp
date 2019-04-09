#include "Pencil.h"

using namespace std;


void write(string &paper, string &input) {
	paper += input;
}

void erase(string &paper, string &input) {
	cout << "erase " << input << " from " << paper;
}