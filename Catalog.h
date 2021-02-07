#ifndef __CATALOG_H__
#define __CATALOG_H__

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <utility>
#include "Course.h"
using namespace std;

class Catalog {
private:
	map<string, Course*> cs;
public:
	Catalog(string inputFile);
	~Catalog();
	void printAll();
	void printAll(string outputFile);
	void print(string c, bool isPre);
private:
	Course* create(string c);
};

#endif //__CATALOG_H__