#include "Course.h"
#include "Catalog.h"
using namespace std;

int main() {
	Catalog cat("input.txt");
	cat.printAll("output.txt");
	return 0;
}

/*

g++ main.cpp Course.cpp Catalog.cpp


*/