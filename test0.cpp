#include <cassert>
#include "Pencil.h"

using namespace std;

//Tests cases designed to test out our pencil

void test_write() {
	//new process, create pencil named pen
	pencil pen;
	//simple write test, see if output matches what we expect
	string paper = "";
	string first = "She sells sea shells";
	write(pen, paper, first);
	assert(paper == first);
	string second = " down by the sea shore";
	write(pen, paper, second);
	assert(paper != second);
	string expected_output = "She sells sea shells down by the sea shore";
	assert(paper == expected_output);
	cout << "test_write() passed!" << endl;
}

void test_erase() {
	//test erase functionality using the example provided by the specs
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

void test_erase_edge() {
	//testing edge cases for erase function
	//test if sub-string does not exist
	string paper = "hello world!";
	string not_existant = "not";
	//nothing should change, outcome should be same as paper
	string outcome = paper;
	erase(paper, not_existant);
	assert(paper == outcome);
	cout << "test_erase_not_exist() passed!" << endl;
}

void test_point_durability() {
	//testing point durability

}

void test_erase_durability() {

}

int main() {
	test_write();
	test_erase();
	test_erase_edge();
}