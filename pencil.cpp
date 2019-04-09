#include "Pencil.h"

using namespace std;


void write(string &paper, string &input) {
	//simply append input onto paper
	paper += input;
}

void erase(string &paper, string &input) {
	//find the position of the last instance of input
	size_t end = paper.find_last_of(input) + 1;
	size_t start = end - input.length();
	//replace this substring with space
	while (start != end) {
		paper.replace(start, size_t(1), " ");
		start++;
	}
}