#include <iostream>
#include "complex.h"
using namespace std;

int main(){
	complex c1(15,5);
	complex c2(1,-2);	
	
	cout << "Number 1: "; c1.print();
	cout << "Number 2: "; c2.print();
	cout << "--------------" << endl;
	
	complex c3 = c1 + c2;
	cout << "Addition: "; c3.print();
	
	complex c4 = c1 - c2;
	cout << "Subtraction: "; c4.print();
	
	complex c5 = c1 * c2;
	cout << "Multiplication: "; c5.print();
	
	complex c6 = c1 / c2;
	cout << "Division: "; c6.print();
	
	cout << "--------------" << endl;
	
	cout << "Comparison: " << endl;
	if(c1 == c2)
		cout << "Number 1 and Number 2 are equal" << endl;
	else
		cout << "Number 1 and Number 2 are NOT equal" << endl;
	
	return 0;
}