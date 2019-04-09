#include <cassert>
#include "Pencil.h"

using namespace std;

//Tests cases designed to test out our pencil

void test_write() {
	//simple write test, see if output matches what we expect
	string paper = "";
	string first = "She sells sea shells";
	write(paper, first);
	assert(paper == first);
	string second = " down by the sea shore";
	write(paper, second);
	assert(paper != second);
	string expected_output = "She sells sea shells down by the sea shore";
	assert(paper == expected_output);
	cout << "test_write() passed!" << endl;
}

//disregard test case, new line functionality not required
void test_new_lines() {
	//more advanced write test case to see how new lines will be treated
	string paper = "\n";
	string first = "hello \n";
	write(paper, first);
	string second = "world";
	write(paper, second);
	string expected = "\nhello \nworld";
	assert(paper == expected);
	//manually ensure new line is processed correctly
	cout << "paper: " << paper << endl;
	cout << "expected string: " << expected << endl;
	cout << "test_new_lines() passed!" << endl;
}


void test_erase() {
	//test erase functionality using the specs example
	string paper = "How much wood would a woodchuck chuck if a woodchuck could chuck wood?";
	//erase the last appearing chuck
	string chuck = "chuck";
	erase(paper, chuck);
	//check to see if last chuck has been erased
	string expected = "How much wood would a woodchuck chuck if a woodchuck could       wood?";
	assert(paper == expected);
	//erase chuck again
	erase(paper, chuck);
	expected = "How much wood would a woodchuck chuck if a wood      could       wood?";
	assert(paper == expected);
	cout << "test_erase() passed!" << endl;
}

int main() {
	test_write();
	test_new_lines();
	test_erase();
}