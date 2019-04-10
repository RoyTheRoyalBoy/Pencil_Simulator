#ifndef PENCIL_H
#define PENCIL_H

#include <string>
#include <iostream>
#include <vector>

struct Pencil {
	int point = 100;
	int orig_point = 100;
	int eraser = 100;
	int length = 10;
};

void write(Pencil &pencil, std::string &paper, std::string &input);
bool erase(std::string &paper, std::string &input);
//void create_pencil(std::vector<Pencil> &pencils, int &point, int &eraser);
bool sharpen(Pencil &pencil);

#endif