#pragma once

#include <string>


using namespace std;
class Term {
private:
	double coeff;
	int power;
public:
	//constructor
	Term() { power = 0; coeff = 0; }
	Term(double c, int p) { power = p; coeff = c; }

	// getters and setters
	int getPower() { return power; }
	double getCoeff() { return coeff; }
	void setPower(int n) { power = n; }
	void setCoeff(double c) { coeff = c; }

	// compare powers
	bool operator< (Term& T) {
		return power < T.getPower();
	}
	bool operator== (Term& T) {
		return power == T.getPower();
	}
	bool operator> (Term& T) {
		return power > T.getPower();
	}

	// add coeff
	Term operator+ (Term T);

	// print term
	void print(bool first);
};
