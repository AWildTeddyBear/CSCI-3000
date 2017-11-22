/*
Name: NotADeveloper
Date: 10-28-2017
Description: Come back to this ---------------------
Copyright: https://github.com/AWildTeddyBear/CSCI-3000/blob/master/LICENSE
*/

#include "functions.hpp"

void menu(int maxEmployees){
	int menuSelection;

	
	cout << "Please select a menu selection: ";
	cin >> menuSelection;

	switch(menuSelection){
		case 1:
		employee.printEmployeeInfo(maxEmployees);
		break;

		case 2:
		employee.printByDepartment(depID,maxEmployees);
		break;

		case 3:
		employee.printBySalary(minSalary,maxEmployees);
		break;

		case 4:
		break;

		case 5:
		break;

		default:
		break;
	}
}