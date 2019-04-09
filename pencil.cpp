#include "Pencil.h"

using namespace std;


void write(pencil& pencil, string &paper, string &input) {
	//simply append input onto paper
	pencil.point = 100;
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

void create_pencil(vector<pencil> &pencils, int &point, int &eraser) {
	pencil new_pencil;
	new_pencil.point = point;
	new_pencil.eraser = eraser;
	pencils.push_back(new_pencil);
}