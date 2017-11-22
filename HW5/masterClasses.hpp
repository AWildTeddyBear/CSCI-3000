/*
Name: NotADeveloper
Date: 11-2-2017
Description: Come back to this ---------------------
Copyright: https://github.com/AWildTeddyBear/CSCI-3000/blob/master/LICENSE
*/

using namespace std;

class employee{
private:
	//All private variables
	int maxSize,currentSize,employeeID,departmentID,salary;
	string employeeName,departmentName;
	employee *employeeList = nullptr;
public:
	//Constructor Class Defaults/Overloads
	employee(){
		employeeID = 0;
		employeeName = "";
		departmentID = 0;
		departmentName = "";
		salary = 0;	
	};
	employee(int empID, string empName, int depID, string depName, int sal){
		employeeID = empID;
		employeeName = empName;
		departmentID = depID;
		departmentName = depName;
		salary = sal;
	};

	//Function Definitions
	void addEmployee(int newName){
		employeeList[currentSize] = newName;
		employeeList[currentSize].employeeID = 0;
		employeeList[currentSize].employeeName = "";
		employeeList[currentSize].departmentID = 0;
		employeeList[currentSize].departmentName = " ";
		employeeList[currentSize].salary = 0;
	}
	void setEmployeeInfo(int number, int ID, string empName, int dID, string depName, int sal){
		employeeList[currentSize].employeeID = ID;
		employeeList[currentSize].employeeName = empName;
		employeeList[currentSize].departmentID = dID;
		employeeList[currentSize].departmentName = depName;
		employeeList[currentSize].salary = sal;
		currentSize++;
	}
	void printEmployeeInfo(int maxSize){
		for (int i = 0; i < maxSize; i++) {    
			cout << "The Employee's name is " << employeeList[i].employeeName << endl;
			cout << employeeList[i].employeeName << "'s salary is " << employeeList[i].salary << endl;
			cout << employeeList[i].employeeName << "'s department is " << employeeList[i].departmentName << endl;
			cout << employeeList[i].employeeName << "'s Department ID is " << employeeList[i].departmentID << endl;
			cout << employeeList[i].employeeName << "'s ID is " << employeeList[i].employeeID << endl;
		}
	}
	void printByDepartment(int depID, int maxSize){
		for (int i = 0; i < maxSize; i++) {
			if (employeeList[i].departmentID == depID){
				cout << "The Employee's name is " << employeeList[i].employeeName << endl;
				cout << employeeList[i].employeeName << "'s salary is " << employeeList[i].salary << endl;
				cout << employeeList[i].employeeName << "'s department is " << employeeList[i].departmentName << endl;
				cout << employeeList[i].employeeName << "'s Department ID is " << employeeList[i].departmentID << endl;
				cout << employeeList[i].employeeName << "'s ID is " << employeeList[i].employeeID << endl;
			}
			else
				continue;
		}
	}
	void printBySalary(int minSalary, int maxSize){
	for (int i = 0; i < maxSize; i++) {
		if (employeeList[i].salary >= minSalary){
			cout << "The Employee's name is " << employeeList[i].employeeName << endl;
			cout << employeeList[i].employeeName << "'s salary is " << employeeList[i].salary << endl;
			cout << employeeList[i].employeeName << "'s department is " << employeeList[i].departmentName << endl;
			cout << employeeList[i].employeeName << "'s Department ID is " << employeeList[i].departmentID << endl;
			cout << employeeList[i].employeeName << "'s ID is " << employeeList[i].employeeID << endl;
		}
		else
			continue;
		}
	}
};