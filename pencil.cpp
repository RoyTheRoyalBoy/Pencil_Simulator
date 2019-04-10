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
		size_t end = start + input.length() - 1;
		//replace this substring with space
		while (end != start - 1) {
			//check if eraser is big enough to erase
			if (pencil.eraser > 0) {
				paper.replace(end, size_t(1), " ");
				//don't decrement when encountering space characters
				if (input[end] != ' ') {
					pencil.eraser--;
				}
			}
			//decrement end to start
			end--;
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

bool edit(Pencil &pencil, string &paper, string &add, string &deleted) {
	//find the erased substring
	size_t start = paper.rfind(deleted) - 1;
	if (start == string::npos) {
		//can't find deleted string
		return false;
	}
	else {
		for(unsigned int i = 0; i < add.length(); i++) {
			if (pencil.curr_point > 0) {
				if(isupper(add[i])) {
					pencil.curr_point -= 2;
				}
				else if(islower(add[i])) {
					pencil.curr_point--;
				}
				if (paper[start] != ' ') {
					paper[start] = '@';
				}
				else {
					paper[start] = add[i];
				}
				
			}
			start++;
		}
	}
	return true;
}