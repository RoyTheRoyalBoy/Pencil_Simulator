#include "Pencil.h"

using namespace std;


void write(pencil& pencil, string &paper, string &input) {
	//measure durability amount, evaluate whether the next character can be added
	for (unsigned int i = 0; i < input.length(); i++) {
		if (pencil.point > 0) {
			if(isupper(input[i])) {
				pencil.point -= 2;
			}
			else if(islower(input[i])) {
				pencil.point--;
			}
			paper += input[i];
		}
		else{
			paper += " ";
		}
	}

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
