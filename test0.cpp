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
	Pencil pencil;
	string paper = "How much wood would a woodchuck chuck if a woodchuck could chuck wood?";
	//erase the last appearing chuck
	string chuck = "chuck";
	erase(pencil, paper, chuck);
	//check to see if last chuck has been erased
	string expected = "How much wood would a woodchuck chuck if a woodchuck could       wood?";
	assert(paper == expected);
	//erase chuck again
	erase(pencil, paper, chuck);
	expected = "How much wood would a woodchuck chuck if a wood      could       wood?";
	assert(paper == expected);
	cout << "test_erase() passed!" << endl;
}

void test_erase_edge() {
	//testing edge cases for erase function
	Pencil pencil;
	//test if sub-string does not exist
	string paper = "hello world!";
	string not_existant = "not";
	//nothing should change, outcome should be same as paper
	string outcome = paper;
	erase(pencil, paper, not_existant);
	assert(paper == outcome);
	cout << "test_erase_not_exist() passed!" << endl;
}

void test_point_durability() {
	//testing point durability of pencil
	Pencil pencil;
	string paper = "";
	//set current point durability to 4
	pencil.curr_point = 4;
	string text = "text";
	write(pencil, paper, text);
	//output should be same as input since durability doesn't run out
	assert(paper == text);
	//reset paper and pencil
	paper = "";
	pencil.curr_point = 4;
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
	//Pencil will be given an original point durability value, default at 100
	//in this case, set orig_point to 40000
	Pencil pencil;
	pencil.orig_point = 40000;
	//set current point to 5 to simulate usage
	pencil.curr_point = 5;
	//make sure that this value was changed prior to sharpen function
	assert(pencil.curr_point != 10);
	sharpen(pencil);
	//assert that sharpening resets the point durability back to 40000
	assert(pencil.curr_point == 40000);
	cout << "test_sharpen() passed!" << endl;
}

void test_length() {
	//testing the length aspect of pencil
	Pencil pencil;
	pencil.length = 1;
	sharpen(pencil);
	//make sure sharpen reduced length by 1 
	assert(pencil.length == 0);
	//set point to 10 to simulate usage
	pencil.curr_point = 10;
	sharpen(pencil);
	//since length is 0, sharpen should not have changed point from 10 nor length from 0
	assert(pencil.length == 0);
	assert(pencil.curr_point == 10);
	cout << "test_length() passed!" << endl;
}

void test_erase_durability() {
	//testing the eraser durability
	Pencil pencil;
	string paper = "Buffalo Bill";
	//set eraser durability to 3 to simulate usage
	pencil.eraser = 3;
	string Bill = "Bill";
	erase(pencil, paper, Bill);
	//due to eraser running out of durability, erase only last 3 characters
	string expected = "Buffalo B   ";
	assert(paper == expected);
	//set eraser to 2
	pencil.eraser = 2;
	string space = "lo B";
	erase(pencil, paper, space);
	//since space shouldn't decrement eraser value, 'o' should also be replaced
	string check_space = "Buffal      ";
	assert(paper == check_space);
	cout << "test_erase_durability() passed!" << endl;
}

void test_edit() {
	//testing the edit functionality
	Pencil pencil;
	string paper = "An       a day keeps the doctor away";
	string erased = "     ";
	string onion = "onion";
	edit(pencil, paper, onion, erased);
	//onion is now edited into the white space
	string expected = "An onion a day keeps the doctor away";
	assert(paper == expected);
	//reset paper for another test
	paper = "An       a day keeps the doctor away";
	string artichoke = "artichoke";
	//a collision should result in colliding non-space character to be replaced with @
	string collision = "An artich@k@ay keeps the doctor away";
	edit(pencil, paper, artichoke, erased);
	assert(paper == collision);
	//assume editing is also affected by eraser and pencil degradation
	cout << "test_edit() passed!" << endl;
}

int main() {
	test_write();
	test_erase();
	test_erase_edge();
	test_point_durability();
	test_sharpen();
	test_length();
	test_erase_durability();
	test_edit();
}