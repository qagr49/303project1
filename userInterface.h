#pragma once
#include "Polynome.h"
class userInterface {
private:
	Polynome P1, P2, Psum;
	bool continueFlag;
	
	/// functions for the interface
	// introduction message printed 
	void intro();

	// print main menu, return the command entered by the user
	int mainMenu(Polynome& P1, Polynome& P2);

	// read Pi (1 or 2) from user
	void readP(Polynome& P1, Polynome& P2, int i);

	// add polynomials P1 and P2
	void add(Polynome P1, Polynome& P2);

	// tutorial to enter polynomials correctly
	void tuto();

	// exit message
	void outro();


public:
	// constructor
	userInterface() {}

	// run the application
	void run();
};
