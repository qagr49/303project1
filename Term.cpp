#include "Term.h"
#include <iostream>
using namespace std;

// add coeff
Term Term::operator+ (Term T) {
	if (power == T.getPower()) {
		coeff+= T.getCoeff();
		return *this;
	}
	else {
		throw exception("powers are different");
	}
	
}

// print term
void Term::print(bool first) {
	if (!first && coeff > 0) { // if it's not first and there is no "-" so "+" is missing

		cout << "+";
		if (coeff != 1) cout << coeff; // don't print "1X" but "X"
		if (power == 0) { if (coeff == 1) cout << coeff; } // print "1" if there is no X
		else if (power == 1) cout << "X";
		else cout << "X^" << power;
	}
	else if (coeff < 0) { // if it's "-..."
		double c = -coeff;
		cout << "-";
		if (c != 1) cout << coeff;
		if (power == 0) { if (c == 1) cout << c; }
		else if (power == 1) cout << "X";
		else cout << "X^" << power;
	}
	else if (first && coeff > 0) { // if it's first and positive: "aX^..."
		if (coeff != 1) cout << coeff;
		if (power == 0) { if (coeff == 1) cout << coeff; }
		else if (power == 1) cout << "X";
		else cout << "X^" << power;
	}
}
