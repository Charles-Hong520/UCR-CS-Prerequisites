#include "Course.h"

Course::Course(string name) {
	this->name = name;
}
Course::~Course() {
}

void Course::addPrec(Course* c) {
	prec.push_back(c);
	c->next.push_back(this);
}

void Course::printPrec() {
	cout << this->name << " Prec: ";
	if(prec.size() <= 0) cout << "None";
	for(unsigned i = 0; i + 1 < prec.size(); i++) {
		cout << prec.at(i)->name << ", ";
	}
	if(prec.size() > 0) cout << prec.at(prec.size()-1)->name;

	cout << endl;
}

void Course::printNext() {
	cout << this->name << " Next: ";
	if(next.size() <= 0) cout << "None";
	for(unsigned i = 0; i + 1 < next.size(); i++) {
		cout << next.at(i)->name << ", ";
	}
	if(next.size() > 0) cout << next.at(next.size()-1)->name;
	cout << endl;
}

void Course::printPrec(ofstream& fout) {
	fout << this->name << " Prec: ";
	if(prec.size() <= 0) fout << "None";
	for(unsigned i = 0; i + 1 < prec.size(); i++) {
		fout << prec.at(i)->name << ", ";
	}
	if(prec.size() > 0) fout << prec.at(prec.size()-1)->name;

	fout << endl;
}

void Course::printNext(ofstream& fout) {
	fout << this->name << " Next: ";
	if(next.size() <= 0) fout << "None";
	for(unsigned i = 0; i + 1 < next.size(); i++) {
		fout << next.at(i)->name << ", ";
	}
	if(next.size() > 0) fout << next.at(next.size()-1)->name;
	fout << endl;
}