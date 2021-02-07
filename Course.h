#ifndef __COURSE_H__
#define __COURSE_H__

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
struct Course {
	string name;
	vector<Course*> prec;
	vector<Course*> next;

	Course(string name);
	~Course();

	void addPrec(Course* c);
	void printPrec();
	void printNext();

	void printPrec(ofstream& fout);
	void printNext(ofstream& fout);
};

#endif //__COURSE_H__