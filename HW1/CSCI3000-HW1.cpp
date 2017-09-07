/*
Developed by NotADeveloper
C++ Simple Equation Checker
---------------------------
XXXXXXXXXX - XXXXXXXXXXX
CSCI 3000, HW1
August 21, 2017
---------------------------
*/

/*
=================================================================================================
-------------------------------------------------------------------------------------------------
----------------------------------------ATTENTION------------------------------------------------
-------------------------------------------------------------------------------------------------
=================================================================================================

 You cannot compile this program as a regular program with G++; below is how you NEED to compile:

=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=
				  =+=+=+= g++ -std=c++11 CSCI3000-HW1.cpp -o out =+=+=+=
=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=

					Again, the regular: g++ CSCI3000-HW1.cpp -o out
    Will *NOT* work; you will be greeted with compiling errors and it will not compile at all.

=================================================================================================
-------------------------------------------------------------------------------------------------
----------------------------------------ATTENTION------------------------------------------------
-------------------------------------------------------------------------------------------------
=================================================================================================
*/

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <unistd.h>

/*
Define colour codes for use in this and future projects.
For ease of use and compatibility.
Also, becuase it looks better in code and better in the finished product...
*/

#define RST  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"
#define FRED(x) KRED x RST
#define FGRN(x) KGRN x RST
#define FYEL(x) KYEL x RST
#define FBLU(x) KBLU x RST
#define FMAG(x) KMAG x RST
#define FCYN(x) KCYN x RST
#define FWHT(x) KWHT x RST
#define BOLD(x) "\x1B[1m" x RST
#define UNDL(x) "\x1B[4m" x RST

using namespace std;

bool checkEquation(int x,int y); //Define prototype
void isEquationTrue(bool result,int x,int y),intro(); //Define prototype

main(){
	//Define variables
	int menuSelection,x,y;
	bool boolResult,nestedLoopCheck = false;
	string line;
	//End define variables

	intro(); //Call intro function

	//Begin menu
	cout << FYEL("######################################################################################") << endl << endl;
	cout << BOLD(FGRN("Would you like to let the program pick from an array, or from a text file to continue?")) << endl << endl;
	cout << FYEL("######################################################################################") << endl << endl; //Menu selection header
	cout << FMAG(" [1] ") << UNDL(FBLU("Array")) << endl << endl; //First menu selection
	cout << FMAG(" [2] ") << UNDL(FBLU("File")) << endl << endl; //Second menu selection
	cout << BOLD(FCYN("Selection: ")); //Selection text for user (choice)
	cin >> menuSelection; //Store user selection for the menu to pick from
	if (menuSelection == 1){ //Array code
		system("clear"); //Clear the screen
		int menuArray[10][2] = {
		{-4,-13},
		{5,-8},
		{2,-3},
		{-1,2},
		{7,7},
		{1,15},
		{2,17},
		{3,22},
		{-4,27},
		{5,32}
		}; //Define our 2D Array to be used if selected
		for(int i=0;i < 10;i++){
			for(int j=0;j < 2;j++){ //Nested loop to store our array values into seperate variables
				if(nestedLoopCheck){ //Check to store the array in the nested loop into seperate variables
					y = menuArray[i][j]; //Store the current array value into Y if the check is true
				}
				else{
					x = menuArray[i][j]; //Store the current array value into X if the check is false
				}
				nestedLoopCheck = true; //Set the loop check to true (Default: False)
			}
		nestedLoopCheck = false; //Reset the loop check back to Default: False
		//cout << "(" << x << "," << y << ")" << endl; //Debug Purposes -- Ignore This
		boolResult = checkEquation(x,y); //Call the function for each variable
		isEquationTrue(boolResult,x,y); //Function that is responsible for telling the user if it's true or not
		}
	}
	else if(menuSelection == 2){ //Pick from file
		system("clear"); //Clear the screen.
		cout << UNDL(FYEL("Before we continue, please assure that the file")) BOLD(FWHT(" 'pairs.txt' ")) UNDL(FYEL("exists in the same directory that this program is being run in.")) << endl << endl; //Print info message.
		cout << UNDL(FYEL("If this file exists in the afforementioned directory, please press")) BOLD(FGRN(" ENTER ")) UNDL(FYEL("to continue...")) << endl << endl; //Print info message
		cin.get();
		cin.get(); //Workaround for bug in G++ that doesn't allow cin.ignore() to be run twice without glitches
		system("clear"); //Clear the screen
		ifstream inFile; //Declare our file stream variable to use
		inFile.open("pairs.txt"); //Define our filename to be opened
		if(!inFile){ //Error Code [The file "pairs.txt" does not exist!]
			cerr << BOLD(FRED("---------------------------------------------------------------------------------------")) << endl;
			cerr << BOLD(FRED("							Unable to open 'pairs.txt'!")) << endl << endl; //Print error message
			cerr << BOLD(FRED("Please make sure you have the file in the correct directory so the program can read it.")) << endl << endl; //Print error info message
			cerr << BOLD(FRED("---------------------------------------------------------------------------------------")) << endl;
			return 0; //End program
		}
		while(getline(inFile,line)){ //Run loop for as many lines are in the file
			istringstream ss(line); //Actually pull data from file
			ss >> x >> y; //Store x and y from the file into stringstream
			// cout << x << " " << y << endl; //Debug Purposes -- Ignore This
			boolResult = checkEquation(x,y); //Call the function for each line in the file
			isEquationTrue(boolResult,x,y); //Function that is responsible for telling the user if it's true or not
		}
		inFile.close(); //Close our file
	}
	else{ //Error Code [User selected something other than 1, or 2]
		system("clear"); //Clear the screen
		cerr << BOLD(FRED("---------------------------------------------------------------------------------------")) << endl;
		cerr << BOLD(FRED("		Please restart the program and pick either 1, or 2.")) << endl; //Print error message to user
		cerr << BOLD(FRED("---------------------------------------------------------------------------------------")) << endl;
		return 0; //End program
	}
	//End menu
	return 0; //End program if the menu scope is escaped
}

void intro(){ //Intro function
	system("clear"); //Clear screen
	cout << BOLD(FCYN("-----------------------------------------------------------------------------------------------------------")) << endl;
	cout << BOLD(FCYN("-----------------------------------------------------------------------------------------------------------")) << endl;
	cout << BOLD(FCYN("---------------------------------------PLEASE SET YOUR WINDOW OF-------------------------------------------")) << endl;
	cout << BOLD(FCYN("-------------------------------------THIS TERMINAL TO MAXIMUM SIZE-----------------------------------------")) << endl;
	cout << BOLD(FCYN("-----------------------------------------------------------------------------------------------------------")) << endl;
	cout << BOLD(FCYN("--------------------------------------PRESS ")) << UNDL(FGRN("ENTER")) BOLD(FCYN(" ONCE COMPLETED-------------------------------------------")) << endl;
	cout << BOLD(FCYN("-----------------------------------------------------------------------------------------------------------")) << endl;
	cin.ignore(); //Wait until user presses ENTER
	system("clear"); //Clear screen
	string asciiNotADeveloper[6] = { //Define string array for ascii goodness
	"███╗   ██╗ ██████╗ ████████╗ █████╗ ██████╗ ███████╗██╗   ██╗███████╗██╗      ██████╗ ██████╗ ███████╗██████╗",
	"████╗  ██║██╔═══██╗╚══██╔══╝██╔══██╗██╔══██╗██╔════╝██║   ██║██╔════╝██║     ██╔═══██╗██╔══██╗██╔════╝██╔══██╗",
	"██╔██╗ ██║██║   ██║   ██║   ███████║██║  ██║█████╗  ██║   ██║█████╗  ██║     ██║   ██║██████╔╝█████╗  ██████╔╝",
	"██║╚██╗██║██║   ██║   ██║   ██╔══██║██║  ██║██╔══╝  ╚██╗ ██╔╝██╔══╝  ██║     ██║   ██║██╔═══╝ ██╔══╝  ██╔══██╗",
	"██║ ╚████║╚██████╔╝   ██║   ██║  ██║██████╔╝███████╗ ╚████╔╝ ███████╗███████╗╚██████╔╝██║     ███████╗██║  ██║",
	"╚═╝  ╚═══╝ ╚═════╝    ╚═╝   ╚═╝  ╚═╝╚═════╝ ╚══════╝  ╚═══╝  ╚══════╝╚══════╝ ╚═════╝ ╚═╝     ╚══════╝╚═╝  ╚═╝"
	};
	for(int i=0;i < 6;i++){ //Loop cout for the string array to print with a small delay between each line.
		cout << asciiNotADeveloper[i] << endl; //Printing each line of the string array -- Can't colour this since it's being called by variable.
		sleep(1); //Sleep for one second between loops
	}
	cout << BOLD(FGRN("				---------------------------------------------------")) << endl; //Displays under printed array
	cout << BOLD(FGRN("				Simple Equation Checker - Developed by NotADevelper")) << endl; //Displays under printed array
	cout << BOLD(FGRN("				---------------------------------------------------")) << endl; //Displays under printed array
	cout << endl << endl << BOLD(FCYN("					Please press ")) << UNDL(FGRN("ENTER")) << BOLD(FCYN(" to continue...")) << endl; //Displays under printed array
	cin.ignore(); //Ignore all input except 'ENTER'.
	system("clear"); //Clear the screen.
}

bool checkEquation(int x,int y){ //Equation: Y = 5*x+7 -- with the structure of the file being Y,X
	bool result = false; //Default to false
	if(y == (5*x+7)){
		result = true; //Equation is true
	}
	else {
		result = false; //Equation is false
	}
	return result; //Return boolean response back to main -> isEquationTrue
}

void isEquationTrue(bool result,int x,int y){
	if(result){ //If result is true, execute code
		cout << BOLD(FGRN("TRUE")) << " -- " FYEL("Point ") << BOLD(FBLU("(")) << x << FYEL(",") << y << BOLD(FBLU(")")) << " " BOLD(FGRN("DOES")) FYEL(" satisfy the equation ") UNDL(FCYN("Y=5*X+7")) << "." << endl; //If the result was true from checkEquation, we print success
	}
	else { //Any other result, execute code
		cout << BOLD(FRED("FALSE")) << " -- " FYEL("Point ") << BOLD(FBLU("(")) << x << FYEL(",") << y << BOLD(FBLU(")")) << FYEL(" does ") BOLD(FRED("NOT")) FYEL(" satisfy the equation ") UNDL(FCYN("Y=5*X+7")) << "." << endl; //If the result was false from checkEquation, we print faliure
	}
}