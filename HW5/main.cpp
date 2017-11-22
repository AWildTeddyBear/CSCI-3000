/*
Developed by NotADeveloper
C++ 
---------------------------
XXXXXXXXXXXXXXXXX - XXXXXX
CSCI 3000, HW5
October 30, 2017
---------------------------
Hours spent so far: Do I even keep track of this anymore?
*/

/*
Uploaded to GitHub (With Header Changed Above)

https://github.com/AWildTeddyBear/CSCI-3000

User AWildTeddyBear: https://github.com/AWildTeddyBear
Is NotADeveloper (As shown in this program (and any others written and uploaded here))
*/

/*
=================================================================================================
-------------------------------------------------------------------------------------------------
----------------------------------------ATTENTION------------------------------------------------
-------------------------------------------------------------------------------------------------
=================================================================================================

 You cannot compile this program as a regular program with G++; below is how you NEED to compile:

=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=
        =+=+=+= g++ -std=c++17 main.cpp -lboost_system -lboost_filesystem -o out =+=+=+=
=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=

=================================================================================================
-------------------------------------------------------------------------------------------------
----------------------------------------ATTENTION------------------------------------------------
-------------------------------------------------------------------------------------------------
=================================================================================================
*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <string>
#include "functions.hpp"

using namespace std;

main(){
	ifstream employeesFile("employees.txt");
	if(!employeesFile){
		cout << "Error: File does not exist!" << endl;
		exit(EXIT_FAILURE);
	}

	//Create variables and default in case of a read error
	string nullText = "";
	int maxEmployees = 0;

	//Find maxEmployess
	while(employeesFile >> nullText >> maxEmployees)
		break;

	//Allocate memory
	employee employeeList* = new employeeList[maxEmployees];

	//Allocate variables
	int employeeID,departmentID,salary;
	string employeeName,departmentName;

	//Store our employee information
	for(int i = 1;i <= maxEmployees;i++){
		employeesFile >> employeeID >> employeeName >> departmentID >> departmentName >> salary;
		cout << "Employee ID: " << employeeID << endl;
		cout << "Employee Name: " << employeeName << endl;
		cout << "Department ID: " << departmentID << endl;
		cout << "Depreatment Name: " << departmentName << endl;
		cout << "Salary: " << salary << endl << endl;
		employee.addEmployee(employeeID);
		employee.setEmployeeInfo(i,employeeID,employeeName,departmentID,departmentName,salary);
	}

	intro();
	while(!menuCallback)
		menu(maxEmployees);

  	exit(EXIT_SUCCESS);
}