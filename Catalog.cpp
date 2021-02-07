#include "Catalog.h"

Catalog::Catalog(string inputFile) {
	ifstream inFS;
	inFS.open(inputFile);
	string line;
	while(getline(inFS, line)) {
		istringstream iss(line);
		string s; iss >> s;
		s.pop_back(); //first course:
		Course* c = 0;
		std::map<string,Course*>::iterator it;
		it = cs.find(s);	
		if(it == cs.end()) {
			c = create(s);
		} else {
			c = it->second;
		} //acquired pointer of first course;
		string follow = "";
		Course* f = 0;
		while(iss >> follow) {
			it = cs.find(follow);	
			if(it == cs.end()) {
				f = create(follow);
			} else {
				f = it->second;
			} //acquired pointer for following courses;
			c->addPrec(f);
		}
	}
}

Course* Catalog::create(string c) {
	pair<string, Course*> p;
	Course* cp = new Course(c);
	p = make_pair(c, cp);
	cs.insert(p);
	return cp;
}

void Catalog::printAll() {
	std::map<string,Course*>::iterator it;
	Course* cp = 0;
	for(it = cs.begin(); it != cs.end(); it++) {
		cp = it->second;
		cp->printPrec();
	}
	cout << endl;

	for(it = cs.begin(); it != cs.end(); it++) {
		cp = it->second;
		cp->printNext();
	}
}

void Catalog::printAll(string outputFile) {
	ofstream outFS;
	outFS.open(outputFile);
	std::map<string,Course*>::iterator it;
	Course* cp = 0;
	for(it = cs.begin(); it != cs.end(); it++) {
		cp = it->second;
		cp->printPrec(outFS);
	}
	outFS << endl;

	for(it = cs.begin(); it != cs.end(); it++) {
		cp = it->second;
		cp->printNext(outFS);
	}
}

void Catalog::print(string c, bool isPre) {

}

Catalog::~Catalog() {
	std::map<string,Course*>::iterator it;
	Course* cp = 0;
	for(it = cs.begin(); it != cs.end(); it++) {
		delete it->second;
	}
}

