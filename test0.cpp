#include <cassert>
#include <string>
#include <iostream>
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

void test_new_lines() {
	//more advanced write test case to see how new lines will be treated
	string paper = "";
	string first = "hello \n";
	write(paper, first);
	string second = "world";
	write(paper, second);
	string expected = "hello \nworld";
	assert(paper == expected);
	cout << "paper :" << paper << endl;
	cout << "expected string: " << expected << endl;
	cout << "test_new_lines() passed!" << endl;
}

int main() {
	test_write();
	test_new_lines();
}