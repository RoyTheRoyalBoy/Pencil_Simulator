#ifndef PENCIL_H
#define PENCIL_H

#include <string>
#include <iostream>
#include <vector>

struct pencil {
	int point = 40000;
	int eraser = 100;
};

void write(pencil &pencil, std::string &paper, std::string &input);
void erase(std::string &paper, std::string &input);
void create_pencil(std::vector<pencil> &pencils, int &point, int &eraser);

#endif