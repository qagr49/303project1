#include <iostream>
#include <algorithm> // to use replace
#include "Polynome.h"
#include "list_iterator.h"

using namespace std;

// read polynomial from standard input
void Polynome::read() {
	string line;

	do {
		getline(cin, line);
		if (line == "") cout << "No polynomial enterred, please try again:";
	} while (line == "");
	
	
	lineRead = line;
	len = lineRead.length(); // number of carracters read

	if (lineRead == "0") {
		while (li.empty() != 1)
			li.pop_back();
		sorted = 1;
		return;
	}

	replace(lineRead.begin(), lineRead.end(), 'x', 'X'); // replace all 'x' by 'X'

	lineToPolynomial(); // convert the line into terms and store them in li (not sorted)
}

// sort polynomial terms to be in decreasing order of exponents
void Polynome::sort() {
	if (sorted) return;
	else if (li.empty() || li.size() == 1) return;

	list<Term>::iterator slow = li.begin(); // iterator at the begining of the list
	list<Term>::iterator fast = (li.begin()); fast++; // iterator at the second element of the list
	Term temp;

	// we are going to iterate through the list with the slow iterator, 
	// then the fast one will go from slow to the end and:
	//   swap its element with slow if: slow Term > fast Term 
	//   add them if: slow Term = fast Term (+ remove fast Term)
	
	while(slow != --(li.end()) && slow != --(li.end()) ){ // slow goes from the 1st to the n-1th element
		fast = slow;
		fast++;
		while(fast != li.end()){ // fast goes from slow+1 to the nth element
			if (*slow > *fast) {
				temp = *slow;
				*slow = *fast;
				*fast = temp;
				fast++;
			}
			else if (*slow == *fast) {
				*slow + *fast;
				fast = li.erase(fast);
			}
			else {
				fast++;
			}
		}
		if (slow == li.end() || slow == --(li.end())) break; // in case fast deleted all the list after slow
		slow++;
	}

	sorted = 1;
}

void Polynome::lineToPolynomial() {
	// reset the list
	while (li.empty() == 0){
		li.pop_back();
	}
	
	
	int i = 0;
	string current = "";

	current = current + lineRead.at(i++); // for the case where the line begins with minus
	while (i < len) {
		// create a string with only one term 
		if (lineRead.at(i) != '+' && lineRead.at(i) != '-') {
			current = current + lineRead.at(i++);
		}
		else {
			stringToTerm(current); // create the Term and add it to li
			current = lineRead.at(i++);
		}
	}
	stringToTerm(current); // saving last term read

	sorted = 0; // list is not sorted yet
}

void Polynome::stringToTerm(string& current) {
	string coefficient = "", exponent = "";
	double doubleCoeff;
	int intExp;
	unsigned int i = 0;
	while (i < current.length()) {// read coeff
		if (current.at(i) != 'X' && current.at(i) != 'x') {
			coefficient = coefficient + current.at(i++);
		}
		else break;
	}

	if (i < current.length()) { // if there is still something to read: current has "X" in it
		i++; // skip X

		if (i < current.length()) { // if there is still something to read: current has "X^"
			i++; // skip ^
			while (i < current.length()) {
				exponent = exponent + current.at(i++);

			}
		}
		else exponent = "1"; // current is "...X" which means X^1

	}
	else exponent = "0"; // current has no "X"

	if (coefficient == "") coefficient = "1"; // in case the user entered "X..."
	if (coefficient == "+") coefficient = "+1"; // in case the user entered "-X..." or "+X..."
	if (coefficient == "-") coefficient = "-1";
	
	if (coefficient == "0") return; // nothing to add to the list
	
	doubleCoeff = stod(coefficient); // convert string to double and int
	intExp = stoi(exponent);


	Term currentTerm(doubleCoeff, intExp);
	li.push_back(currentTerm);  // add term to polynomial list (not sortted yet)

}

void Polynome::print() {

	if (li.empty()) { // list is empty
		cout << "0";
		return;
	}
	else if (li.size() == 1) {
		(*(li.begin())).print(1);
		return;
	}

	list<Term>::iterator iter = --(li.end()); // iterator at the last nonNULL element
	(*iter).print(1); // first term: X^n
	iter--;
	while (iter != li.begin()) {
		(*iter).print(0);  
		iter--;
	}
	(*iter).print(0); // last term: X^0

}

// add polynomial P2 to our polynomial
void Polynome::add(Polynome P2){
	if (P2.li.empty()) return;
	if (li.empty()) {
		list<Term>::iterator iterP2 = P2.li.begin(); // iterator at the first element of the polynomial passed as argument
		while (iterP2 != P2.li.end()) {
			li.push_back(*iterP2);
			iterP2++;
		}
	}
	list<Term>::iterator iterP1 = li.begin(); // iterator at the first element of the polynomial
	list<Term>::iterator iterP2 = P2.li.begin(); // iterator at the first element of the polynomial passed as argument

	// add to our polynomial list (P1) the terms that are in P2 but missing in P1. ex: P1 = X, P2 = 1, this will add the node with term coeff =1, power =0 to li
	while (iterP2->getPower() < iterP1->getPower()) {
		
		li.insert(iterP1, *(iterP2)); // insert the P 2terms before the P1 term that had the smallest power in P1 at the begining
		iterP2++;
		if (iterP2 == P2.li.end()) return; // everything was read
	}

	// add the P2 terms to P1, creating a node if missing
	while (iterP2 != P2.li.end()) {
		if (iterP1->getPower() == iterP2->getPower()) { // easy case, we found 2 matching powers, we add terms
			(*iterP1) + (*iterP2);
			if(iterP1 != --(li.end())) ++iterP1;
			++iterP2;
		}

		else if (iterP1->getPower() < iterP2->getPower()) { // either we reached the end of P1 or we can advance P1 to find the term to add or to insert before
			if (iterP1 == --(li.end())) {
				li.push_back(*iterP2);
				iterP1 = --(li.end());
				++iterP2;
			}
			else ++iterP1;
		}

		else { // if iterP1->getPower() > iterP2->getPower() happens, that means iterP1->getPower() == iterP2->getPower() never happened for that iterP2 so the term is missing in P1
			li.insert(iterP1, *iterP2);
			++iterP2;
		}
	}
}
