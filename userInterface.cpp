#include "userInterface.h"
#include <iostream>

void userInterface::run()
{
	continueFlag = 1;

	intro();

	do {
		switch (mainMenu(P1, P2)) {
		case(1): readP(P1, P2, 1);
			break;
		case(2): readP(P1, P2, 2);
			break;
		case(3): add(P1, P2);
			break;
		case(4): tuto();
			break;
		case(5): continueFlag = 0;
			outro();
		}

	} while (continueFlag);

	system("pause");
}

void userInterface::intro() {
	cout << "--------------------------------------------------" << endl;
	cout << "       Welcome to the polynomial calculator" << endl;
	cout << "--------------------------------------------------" << endl;
	cout << endl;
}

int userInterface::mainMenu(Polynome& P1, Polynome& P2) {

	cout << " Main menu, press:";
	cout << "\n\t(1) Modify Polynomial P1: "; P1.print();
	cout << "\n\t(2) Modify Polynomial P2: "; P2.print();
	cout << "\n\t(3) Add P1 and P2";
	cout << "\n\t(4) Tutorial";
	cout << "\n\t(5) Exit";
	cout << "\n Please select a key: ";

	string answer;
	bool continueFlag = 1;

	do {
		getline(cin, answer);
		if (answer != "1" && answer != "2" && answer != "3" && answer != "4" && answer != "5") {
			cout << "  Enter a valid key: ";
		}
		else continueFlag = 0;
	} while (continueFlag);

	cout << endl;
	return stoi(answer);
}

void userInterface::readP(Polynome& P1, Polynome& P2, int i) {
	if (i == 1) {
		cout << "Enter first Polynomial: ";
		P1.read();
		P1.sort();
		cout << "You entered: ";
		P1.print();
	}

	else if (i == 2) {
		cout << "Enter second Polynomial: ";
		P2.read();
		P2.sort();
		cout << "You entered: ";
		P2.print();
	}

	cout << endl << endl;
}

void userInterface::add(Polynome P1, Polynome& P2) {
	P1.print();
	cout << " + ";
	P2.print();
	cout << " = ";

	P1.add(P2);
	P1.print();
	cout << endl;
	cout << endl;
}

void userInterface::tuto() {
	cout << "To enter the polynomials in a valid way, please enter terms as \"aX^b\"\n";
	cout << "These are examples of correct polynomials: \n"
		<< " 1+X+23X^5\n"
		<< " X\n"
		<< " x+3X^5+5\n"
		<< " x+2x^2\n";
	cout << "Please do not put the space character in the expression\n\n";
}

void userInterface::outro() {
	cout << "--------------------------------------------------" << endl;
	cout << "      Thank you for using the calculator! " << endl;
	cout << "--------------------------------------------------" << endl;

}

