#include "Pencil.h"

using namespace std;


void write(string &paper, string &input) {
	//simply append input onto paper
	paper += input;
}

void erase(string &paper, string &input) {
	//find the position of the last instance of input
	//simulate a substring with start and end value
	size_t start = paper.rfind(input);
	if (start == string::npos) {
		cout << "Word does not exist on paper!" << endl;
	}
	else {
		size_t end = start + input.length();
		//replace this substring with space
		while (start != end) {
			paper.replace(start, size_t(1), " ");
			start++;
		}
	}
}