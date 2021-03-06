#ifndef PENCIL_H
#define PENCIL_H

#include <string>
#include <iostream>
#include <vector>

struct Pencil {
	int curr_point = 100;
	int orig_point = 100;
	int eraser = 100;
	int length = 10;
};

void write(Pencil &pencil, std::string &paper, std::string &input);
bool erase(Pencil &pencil, std::string &paper, std::string &input);
//void create_pencil(std::vector<Pencil> &pencils, int &point, int &eraser);
bool sharpen(Pencil &pencil);
bool edit(Pencil &pencil, std::string &paper, std::string &add, std::string &deleted);
#endif