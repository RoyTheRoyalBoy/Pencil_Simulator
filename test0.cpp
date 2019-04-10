#include <cassert>
#include "Pencil.h"

using namespace std;

//Tests cases designed to test out our pencil

void test_write() {
	//new process, create Pencil named pencil
	Pencil pencil;
	//simple write test, see if output matches what we expect
	string paper = "";
	string first = "She sells sea shells";
	write(pencil, paper, first);
	assert(paper == first);
	string second = " down by the sea shore";
	write(pencil, paper, second);
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
	//testing point durability of pencil
	Pencil pencil;
	string paper = "";
	//set point durability to 4
	pencil.point = 4;
	string text = "text";
	write(pencil, paper, text);
	//output should be same as input since durability doesn't run out
	assert(paper == text);
	//reset paper and pencil
	paper = "";
	pencil.point = 4;
	string Text = "Text";
	write(pencil, paper, Text);
	string expected = "Tex ";
	//output should replace the last T with space due to point durability running out 
	//since T takes up 2 points of durability
	assert(paper == expected);
	cout << "test_point_durability() passed!" << endl;
}

void test_sharpen() {
	//testing the sharpen function
	//Pencil will be given an original point durability value
	//in this case, set orig_point to 40000
	Pencil pencil;
	pencil.orig_point = 40000;
	//set actual point to 5 to simulate usage
	pencil.point = 5;
	//make sure that this value was changed prior to sharpen function
	assert(pencil.point != 10);
	sharpen(pencil);
	//assert that sharpening resets the point durability back to 40000
	assert(pencil.point == 40000);
	cout << "test_sharpen() passed!" << endl;
}

void test_erase_durability() {

}

int main() {
	test_write();
	test_erase();
	test_erase_edge();
	test_point_durability();
	test_sharpen();
}