#pragma once
#include "list.h"
#include "Term.h"
using namespace std;

class Polynome {
private:
	list<Term> li;
	string lineRead; // the line from the user
	int len; // number of carracters read
	bool sorted;
public:
	//constructor 
	Polynome() { sorted = 0; }

	// read polynomial from standard input
	void read();

	// sort polynomial terms to be in decreasing order of exponents
	void sort();

	// extract the information int he line read from the user to li
	void lineToPolynomial();

	// create the Term from the string current and add it to li
	void stringToTerm(string& current);

	// print polynomial
	void print() ;

	// add polynomials
	void add(Polynome P);

	
};
