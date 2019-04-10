#include "Pencil.h"

using namespace std;


void write(Pencil& pencil, string &paper, string &input) {
	//measure durability amount, evaluate whether the next character can be added
	for (unsigned int i = 0; i < input.length(); i++) {
		if (pencil.curr_point > 0) {
			if(isupper(input[i])) {
				pencil.curr_point -= 2;
			}
			else if(islower(input[i])) {
				pencil.curr_point--;
			}
			paper += input[i];
		}
		else{
			paper += " ";
		}
	}

}

bool erase(Pencil &pencil, string &paper, string &input) {
	//find the position of the last instance of input
	//simulate a substring with start and end value
	size_t start = paper.rfind(input);
	if (start == string::npos) {
		return false;
		//cout << "Word does not exist on paper!" << endl;
	}
	else {
		size_t end = start + input.length();
		//replace this substring with space
		while (start != end) {
			if (pencil.eraser > 0) {
				paper.replace(start, size_t(1), " ");
				if (input[start] != ' ') {
					pencil.eraser--;
				}
			}
			start++;
		}
		return true;
	}
	return true;
}

bool sharpen(Pencil& pencil) {
	//set point durability back to original point durability
	//only do this if length is greater than 0
	if (pencil.length > 0) {
		pencil.curr_point = pencil.orig_point;
		pencil.length--;
		return true;
	}
	else {
		return false;
		//cout << "Pencil too short, can't sharpen!" << endl;
	}
	return true;
}
