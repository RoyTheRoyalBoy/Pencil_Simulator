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

/*disregard this test case, new line functionality not required
void test_new_lines() {
	//more advanced write test case to see how new lines will be treated
	string paper = "\n";
	string first = "hello \n";
	write(paper, first);
	string second = "world";
	write(paper, second);
	string expected = "\nhello \nworld";
	//manually ensure new line is processed correctly
	cout << "paper: " << paper << endl;
	cout << "expected string: " << expected << endl;
	assert(paper == expected);
	cout << "test_new_lines() passed!" << endl;
}*/


void test_erase() {
	//test erase functionality using the example provided by the specs
	string paper = "How much wood would a woodchuck chuck if a woodchuck could chuck wood?";
	//erase the last appearing chuck
	string chuck = "chuck";
	erase(paper, chuck);
	//check to see if last chuck has been erased
	string expected = "How much wood would a woodchuck chuck if a woodchuck could       wood?";
	//manually compare the content of paper to expected output
	cout << paper << endl;
	cout << expected << endl;
	assert(paper == expected);
	//erase chuck again
	erase(paper, chuck);
	expected = "How much wood would a woodchuck chuck if a wood      could       wood?";
	assert(paper == expected);
	cout << "test_erase() passed!" << endl;
}

void test_erase_edge() {
	//test if sub-string does not exist
	string paper = "hello world!";
	string not_existant = "not in this string";
	//nothing should change, outcome should just be paper
	string outcome = paper;
	erase(paper, not_existant);
	assert(paper == outcome);
	//test if sub-string is at the end of the paper
	cout << "test_erase_not_exist() passed!" << endl;
}


int main() {
	test_write();
	//test_new_lines();
	//test_erase();
	test_erase_edge();
}