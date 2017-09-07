/*
Developed by NotADeveloper
C++ Airplane Seat Reserver
---------------------------
XXXXXXXXXXXXX - XXXXXXXXXXX
CSCI 3000, HW2
September 9, 2017
---------------------------
Hours spent so far: 25ish? -- I lost count.
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
		=+=+=+= g++ -std=c++17 sha256.cpp CSCI-3000_HW2.cpp -o out =+=+=+=
=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=

			Again, the regular: g++ CSCI3000_HW2.cpp -o out
    Will *NOT* work; you will be greeted with compiling errors and it will not compile at all.

=================================================================================================
-------------------------------------------------------------------------------------------------
----------------------------------------ATTENTION------------------------------------------------
-------------------------------------------------------------------------------------------------
=================================================================================================
*/

#include <iostream>
#include <fstream>
#include <unistd.h>
#include <sstream>
#include "sha256.h"

/*
Define colour codes for use in this and future projects.
For ease of use and compatibility.
Also, becuase it looks better in code and better in the finished product...
*/

#define RST  "\x1B[0m" //Reset (No colour)
#define KRED  "\x1B[31m" //Red
#define KGRN  "\x1B[32m" //Green
#define KYEL  "\x1B[33m" //Yellow
#define KBLU  "\x1B[34m" //Blue
#define KMAG  "\x1B[35m" //Magenta
#define KCYN  "\x1B[36m" //Cyan
#define KWHT  "\x1B[37m" //White
#define FRED(x) KRED x RST //Red + Reset [So it doesn't go outside of the scope]
#define FGRN(x) KGRN x RST //Green + Reset [So it doesn't go outside of the scope]
#define FYEL(x) KYEL x RST //Yellow + Reset [So it doesn't go outside of the scope]
#define FBLU(x) KBLU x RST //Blue + Reset [So it doesn't go outside of the scope]
#define FMAG(x) KMAG x RST //Magenta + Reset [So it doesn't go outside of the scope]
#define FCYN(x) KCYN x RST //Cyan + Reset [So it doesn't go outside of the scope]
#define FWHT(x) KWHT x RST //White + Reset [So it doesn't go outside of the scope]
#define BOLD(x) "\x1B[1m" x RST //Bold + Reset [So it doesn't go outside of the scope]
#define UNDL(x) "\x1B[4m" x RST //Underlined + Reset [So it doesn't go outside of the scope]

#define arrayRows 10 //Define our values to not be changed
#define arrayColumns 4 //Define our values to not be changed

using namespace std; //So we don't have to do std:: on EVERYTHING

/*
-----------------------------------------------------------
---------------VOID FUNCTION PROTOTYPES--------------------
-----------------------------------------------------------
*/
void intro();
void menu(string doNotEditFilename,string writeableFilename,string reservationFilename);
void printCurrentSeats(string writeableFilename,string doNotEditFilename);
void reserveSeat(string writeableFilename,string reservationFilename,string doNotEditFilename);
void writeReserveSeats(string writeableFilename,bool inputArr[][arrayColumns]);
void resetReservedSeats(string doNotEditFilename,string writeableFilename);
void removeEmptyFileLines(string writeableFilename);
/*
-----------------------------------------------------------
-------------END VOID FUNCTION PROTOTYPES------------------
-----------------------------------------------------------
*/

/*
-----------------------------------------------------------
---------------BOOL FUNCTION PROTOTYPES--------------------
-----------------------------------------------------------
*/
bool calculateFileHash(string fileName);
bool isFileEmpty(string writeableFilename);
bool endOfAllFunctions();
/*
-----------------------------------------------------------
-------------END BOOL FUNCTION PROTOTYPES------------------
-----------------------------------------------------------
*/

main(){
	/*
	-----------------------------------------------------------
	-----------------------START CONFIG------------------------
	-----------------------------------------------------------
	*/
	string doNotEditFilename = ("Plane-Layout.NotADEV"); //FILENAME FOR MASTER SEATING CHART -- Don't change this or the file contents! -- READ ONLY
	string writeableFilename = ("Current-Plane-Layout.NotADEV"); //Filename for file that will be overriden/wiped/reset etc by the program -- READ/WRITE
	string reservationFilename = ("reservations.txt"); //Filename for reservations from file -- READ ONLY
	/*
	-----------------------------------------------------------
	------------------------END CONFIG-------------------------
	-----------------------------------------------------------
	*/
	intro(); //Call the intro function
	bool defaultMenuCallback = true; //We need to default this to true to make sure that our while loop runs
	while(defaultMenuCallback){ //Create a loop so we can re-call the menu function if we want
		menu(doNotEditFilename,writeableFilename,reservationFilename); //Call menu function and pass all our configs to be pushed to other functions
		defaultMenuCallback = endOfAllFunctions(); //Essentially adds this functioncall after EVERY function -- easier on all of us. -- it creates a dialog for the user to go back to menu
	}
	system("clear"); //Clear the screen right before the program exits
	exit(EXIT_SUCCESS); //Exit the program once functions are done
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
	cout << BOLD(FGRN("				----------------------------------------------------")) << endl; //Displays under printed array
	cout << BOLD(FGRN("				 Airplane Seat Reserver - Developed by NotADevelper")) << endl; //Displays under printed array
	cout << BOLD(FGRN("				----------------------------------------------------")) << endl; //Displays under printed array
	cout << endl << endl << BOLD(FCYN("					Please press ")) << UNDL(FGRN("ENTER")) << BOLD(FCYN(" to continue...")) << endl; //Displays under printed array
	cin.ignore(); //Ignore all input except 'ENTER'.
	system("clear"); //Clear the screen.
}

void menu(string doNotEditFilename,string writeableFilename,string reservationFilename){ //The mother function -- what ties everything together
	int menuSelection; //Create variable to be used to store our user's menu selection
	system("clear"); //Clear our screen
	cout << FCYN(R"(
                                |
                          --====|====--
                                |
                            .-"""""-.
                          .'_________'.
                         /_/_|__|__|_\_\
                        ;'-._       _.-';
   ,--------------------|    `-. .-'    |--------------------,
    ``""--..__    ___   ;       '       ;   ___    __..--""``
              `"-// \\.._\             /_..// \\-"`
                 \\_//    '._       _.'    \\_//
                  `"`        ``---``        `"`)") << endl; //Pretty airplane
	cout << FYEL("################################################################") << endl << endl; //Fancy borders
	cout << BOLD(FGRN("                   Airplane Seat Reserver Menu")) << endl << endl; //Program name
	cout << FYEL("################################################################") << endl << endl; //Fancy borders
	cout << FMAG(" [1] ") << UNDL(FBLU("Print current seating chart")) << endl << endl; //First menu selection
	cout << FMAG(" [2] ") << UNDL(FBLU("Reserve Seat")) << endl << endl; //Second menu selection
	cout << FMAG(" [3] ") << UNDL(FBLU("Reset seating chart")) << endl << endl;
	cout << FMAG(" [4] ") << UNDL(FBLU("Exit program")) << endl << endl;
	cout << BOLD(FCYN("Selection: ")); //Selection text for user (choice)
	cin >> menuSelection; //Store user selection for the menu to pick from
	switch(menuSelection){ //Let's do a switch for our user's selections
		case 1: //User selected "Print Current Seating Chart"
		printCurrentSeats(writeableFilename,doNotEditFilename); //Call our print seats function with the correct files passed
		break; //After function is done, make sure we break out of the case

		case 2: //User Selected "Reserve Seat"
		reserveSeat(writeableFilename,reservationFilename,doNotEditFilename); //Call our reserveSeat function with the correct files passed
		break; //After function is done, make sure we break out of the case

		case 3: //User Selected "Reset Seating Chart"
		resetReservedSeats(doNotEditFilename,writeableFilename); //Call our reset seats function with the correct files passed
		break; //After function is done, make sure we break out of the case

		case 4: //User Selected "Exit Program"
		system("clear"); //Clear our screen
		cout << BOLD(FGRN("Exiting program...")) << endl; //Print exit message to user
		exit(EXIT_SUCCESS); //Exit successfully
		break;

		default: //User dun goofed and selected something other than our wanted selections
		system("clear"); //Clear our screen
		cerr << BOLD(FRED("ERROR: INCORRECT MENU SELECTION!")) << endl << endl; //Print error message to user
		exit(EXIT_FAILURE); //Exit with error
	}
}


bool calculateFileHash(string doNotEditFilename){ //Let's make a SHA-256 hash checker! -- NOTE: This is inefficient and I know, it's a stepping stone into hashing for my programs.
	ifstream inFile; //Create variable to be used for our inputFile
	inFile.open(doNotEditFilename.c_str(),ios::out); //Open our filename from the variable passed to the functionCall and convert it to a string that it can use
    string currentLine; //Variable to store the current line of the file into later on in the file
    int hashResultNum = 0; //Initialize our integer at 0 so we know the current value
    string compareHashes[12] = { //DO NOT EDIT THIS -- This stores the values of sha256 hashed files that are supposed to be within Plane-Layout.NotADEV
    "99f6abf1fdc9fb8a8cc8ae8a4e649e3471f97fd0bae4cc8e6c7fb7211de3ce9d", //Hash 0
    "78b5d1a4cec12ef55824a17133fab244e87aa8e6e9e8658d757bb978c7b3e209", //Hash 1
    "e160dd8852d7a705da742e14c647b22ee60cc6f9e509dab66d78c114b23ba32a", //Hash 2
    "bf20a50d3f5ec39143518566dfe9e16ba0396fd1d454c945559bb37c2d322cb1", //Hash 3
    "157fb45340077ada5c157962576a517e4ddb32383f34a24b5e1c3d47a32c43ea", //Hash 4
    "032691f08673d72f6263dfd52aa1d670f6c1373a94faa482de0ef5425780bd06", //Hash 5
    "7d0bc0a31ff258086f3c45b3d4534d31259b72f8cbd9e2695eefa2971df550ec", //Hash 6
    "510e252de64c02dd1c934d3fa034a7d53d7e8e9431e75665b31e2cb983d4e367", //Hash 7
    "800e2b233712508d4fd06f188c34ce902b4e605b5f02d209dc50ca87d74c112e", //Hash 8
    "e65769fb3feaecf2884cfc5c480721c7f99408d96072846e88e692d817347bdd", //Hash 9
	"dffa9a3c557da096e75737b1c3d8b4191fd565bf8b77b8bc13522c8d38d60f21", //Hash 10
	"d1d5af10f693b9b1cba5935bce909f9150189df46c3aacf881f56579a90aa616" //Hash 11
	};
    while(getline(inFile,currentLine)){ //Loop until the end of the file, and store the current line into currentLine
    	for(int i = 0;i < 12;i++){ //Let's loop through the array so we can compare
    		if(sha256(currentLine) == compareHashes[i]){ //Compare hashes of our file and to the ones we already have to see if they are the same
    			hashResultNum += 1; //Add this number by one each time the loop returns true
    			break; //Once we've gotten true in this we need to break out of the loop since we don't need it anymore
    		}
    	}
    }
    inFile.close(); //Close our file
    return (hashResultNum == 12); //Return true if our hashes are right.
}

bool isFileEmpty(string writeableFilename){ //We won't need to check if the file exists here, as it will be called from another function with that built-in
    ifstream inFile; //Define our file variable for operations
    inFile.open(writeableFilename.c_str()); //Open our file to check
    inFile.seekg(0,ios::end); //Go to the end of the file
    bool empty = (inFile.tellg() == 0); //Check if there are 0 lines in the file (empty) - then store it as a bool result to return
    inFile.close(); //Close our file
    return empty; //Return true or false
}

bool endOfAllFunctions(){
	int selection; //Integer to hold menu selection
	cout << endl << endl << FMAG("Would you like to go back to the menu or exit?") << endl << endl; //Info message printed to user
	cout << FMAG(" [1] ") << UNDL(FGRN("Go back to the menu!")) << endl << endl; //First menu selection
	cout << FMAG(" [2] ") << UNDL(FRED("Exit the program!")) << endl << endl; //Second menu selection
	cout << BOLD(FCYN("Selection: ")); //Selection text for user (choice)
	cin >> selection; //Store user's choice
	if(selection == 1){ //If user chose to go back to the menu
		return true; //Return true to main()
	}
	else{ //Any other choice -- no need for error checking at this point
		return false; //Return false to main()
	}
}

void printCurrentSeats(string writeableFilename,string doNotEditFilename){
  system("clear"); //Clear our screen
  string currentLine,seatA,seatB,seatC,seatD; //Create our string variables to be used
  int currentRow; //Create integer to be used to store fileData
  ifstream inFile; //Create our file variable
  inFile.open(writeableFilename.c_str()); //Open our file passed
  if(!inFile){ //Error Code [The file << writeableFilename << does not exist!]
	system("clear");
	cerr << BOLD(FRED("---------------------------------------------------------------------------------------")) << endl; //Fancy lines
    cerr << BOLD(FRED("						   Unable to open ")) << writeableFilename << BOLD(FRED(" !")) << endl << endl; //Print error message
   	cerr << BOLD(FRED("Please make sure you have the file in the correct directory so the program can read it.")) << endl << endl; //Print error info message
    cerr << BOLD(FRED("---------------------------------------------------------------------------------------")) << endl; //Fancy lines
    exit(EXIT_FAILURE); //End program
  }
  if(isFileEmpty(writeableFilename)){ //Our file is empty
  	system("clear"); //Clear our screen
  	cerr << BOLD(FRED("-----------------------------------------------------------")) << endl; //Fancy lines
  	cerr << BOLD(FRED("===========================================================")) << endl << endl; //Fancy lines
  	cerr << BOLD(FRED("Seating chart is empty -- would you like to reset the file?")) << endl << endl; //Confirmation dialog
  	cerr << BOLD(FRED("===========================================================")) << endl; //Fancy lines
  	cerr << BOLD(FRED("-----------------------------------------------------------")) << endl << endl << endl; //Fancy lines
  	int resetSelection; //Create integer variable to be used to store and check user input
  	cout << FMAG(" [1] ") << UNDL(FGRN("Yes, let me reset the file!")) << endl << endl; //First menu selection
	cout << FMAG(" [2] ") << UNDL(FRED("No, exit now!")) << endl << endl; //Second menu selection
	cout << BOLD(FCYN("Selection: ")); //Selection text for user (choice)
	cin >> resetSelection; //Store our user input
	if(resetSelection == 1){ //If the user chose to reset the file
		resetReservedSeats(doNotEditFilename,writeableFilename); //Reset our file by passing doNotEditFilename and writeableFilename to our reset function
	}
	else{ //Any other selection
		system("clear"); //Clear our screen
		cout << BOLD(FRED("Exiting...")) << endl << endl << endl; //Print exit to user
		exit(EXIT_SUCCESS); //Exit success code
	}
  }
  else{ //Our file is not empty -- print out our chart {Note: I was going to make this a lot cooler, but I worried about other things at the time}
  	while(getline(inFile,currentLine)){
		istringstream ss(currentLine); //Use stringstream to read the values
		ss >> currentRow >> seatA >> seatB >> seatC >> seatD; //Store all the variables into memory and into seperate variables
		cout << "     " << currentRow << ": " << seatA << " " << seatB << " " << seatC << " " << seatD << endl; //I'm here for debug
 	 }
  }
  inFile.close(); //Close our file
}

void reserveSeat(string writeableFilename,string reservationFilename,string doNotEditFilename){
	system("clear"); //Clear our screen
	fstream inFile; //Define our file for reservationFilename
	fstream outFile; //Define our file for writeableFilename -- Read and write with fstream
	/*
	Variable Definitions
	*/
	int currentReservationRow,currentPlaneLayoutRow,foundReservationSeat,selectedRow,confirmSelection,selectedConvertedSeat,resetSelection = 999;
	char currentReservationSeat,seatA,seatB,seatC,seatD,selectedSeat,A = 'A',B = 'B',C = 'C',D = 'D',X = 'X';
	/*
	Variable Definitions
	*/
	inFile.open(reservationFilename.c_str(),ios::in); //Open our reservations file
	outFile.open(writeableFilename.c_str(),ios::in); //Open our seating chart file of read/write I/O
	if(!inFile){ //If our file doesn't exist
	system("clear"); //Clear our screen
	cout << BOLD(FRED("---------------------------------------------------------------------------------------")) << endl; //Fancy lines
    cerr << BOLD(FRED("						   Unable to open ")) << reservationFilename << BOLD(FRED(" !")) << endl << endl; //Print error message
   	cerr << BOLD(FRED("Please make sure you have the file in the correct directory so the program can read it.")) << endl << endl; //Print error info message
    cout << BOLD(FRED("---------------------------------------------------------------------------------------")) << endl; //Fancy lines
    exit(EXIT_FAILURE); //End program
	}
	if(!outFile){ //If our file doesn't exist
		system("clear"); //Clear our screen
		cout << BOLD(FRED("---------------------------------------------------------------------------------------")) << endl; //Fancy lines
    	cerr << BOLD(FRED("						   Unable to open ")) << writeableFilename << BOLD(FRED(" !")) << endl << endl; //Print error message
   		cerr << BOLD(FRED("Please make sure you have the file in the correct directory so the program can read it.")) << endl << endl; //Print error info message
    	cout << BOLD(FRED("---------------------------------------------------------------------------------------")) << endl; //Fancy lines
    	exit(EXIT_FAILURE); //End program
	}
	if(isFileEmpty(writeableFilename)){ //Our file is empty
  		system("clear"); //Clear our screen
  		cout << BOLD(FRED("-----------------------------------------------------------")) << endl; //Fancy lines
  		cout << BOLD(FRED("===========================================================")) << endl << endl; //Fancy lines
  		cerr << BOLD(FRED("Seating chart is empty -- would you like to reset the file?")) << endl << endl; //Confirmation message printed to user
  		cout << BOLD(FRED("===========================================================")) << endl; //Fancy lines
  		cout << BOLD(FRED("-----------------------------------------------------------")) << endl << endl << endl; //Fancy lines
  		cout << FMAG(" [1] ") << UNDL(FGRN("Yes, let me reset the file!")) << endl << endl; //First menu selection
		cout << FMAG(" [2] ") << UNDL(FRED("No, exit now!")) << endl << endl; //Second menu selection
		cout << BOLD(FCYN("Selection: ")); //Selection text for user (choice)
		cin >> resetSelection; //Store our user's selection
	}
	if(resetSelection == 1){ //User selected to rest
		resetReservedSeats(doNotEditFilename,writeableFilename); //Call our reset function with the right files passed
		resetSelection = 999; //Default back to normal
	}
	if(resetSelection == 999){ //Our default selection - (The file isn't empty)
		NULL; //Something to skip because our file isn't empty...
	}
	else{ //Something other than 1 was selected -- you had ONE job
		system("clear"); //Clear our screen
		cout << BOLD(FRED("Exiting...")) << endl << endl << endl; //Print exit message
		exit(EXIT_SUCCESS); //Exit with success
	}
	cout << BOLD(FGRN("Reserving seats from reservation file...")) << endl << endl; //Print reserving seat message to user
	sleep(2); //Sleep for 2 seconds
	system("clear"); //Clear our screen
	bool tempArray[arrayRows][arrayColumns] = {0}; //Create an array and default all values to false (0)
	for(int i = 0;i < arrayRows;i++){ //Loop through 10 times (because we only have 10 lines in the file)
		outFile >> currentPlaneLayoutRow >> seatA >> seatB >> seatC >> seatD; //Pull our variable from our file and store them into temp variables to be stored
		tempArray[i][0] = (seatA != A); //If seatA = not equal to A then return true (Reserved)
		tempArray[i][1] = (seatB != B); //If seatB = not equal to B then return true (Reserved)
		tempArray[i][2] = (seatC != C); //If seatC = not equal to C then return true (Reserved)
		tempArray[i][3] = (seatD != D); //If seatD = not equal to D then return true (Reserved)
	}
	outFile.close(); //Close our file
	while(inFile >> currentReservationRow >> currentReservationSeat){ //Pull our data from our reservation file into temporary variables
		if(currentReservationSeat == A) //If the seat in the reservation file equals 'A' then execute
			foundReservationSeat = 0; //Set our reservation seat in file to 0 for array
		else if(currentReservationSeat == B) //If the seat in the reservation file equals 'B' then execute
			foundReservationSeat = 1; //Set our reservation seat in file to 2 for array
		else if(currentReservationSeat == C) //If the seat in the reservation file equals 'C' then execute
			foundReservationSeat = 2; //Set our reservation seat in file to 3 for array
		else //Any other case (Which is 'D') then execute
			foundReservationSeat = 3; //Set our reservation seat in file to 4 for array
		tempArray[currentReservationRow-1][foundReservationSeat] = true; //Set current array selection to true [we -1 on currentReservationRow because it defaults one over]
	}
	inFile.close(); //Close our file
	cout << BOLD(FGRN("Please enter a row number to be reserved [1-10]: ")); //Print row number entry to user
	cin >> selectedRow; //Store our row from user
	cout << endl << BOLD(FGRN("Please enter a seat to be reserved [A,B,C,D]: ")); //Print seat entry to user
	cin >> selectedSeat; //Store our seat from user
	cout << endl << endl << BOLD(FMAG("Are you sure you want to reserve seat: ")) << endl << BOLD(FMAG("Row: ")) << selectedRow << endl << BOLD(FMAG("Seat: ")) << selectedSeat << endl << endl; //Print confirmation for seat and row
	cout << FMAG(" [1] ") << UNDL(FGRN("Confirm")) << endl << endl; //First menu selection
	cout << FMAG(" [2] ") << UNDL(FRED("Deny")) << endl << endl; //Second menu selection
	cout << BOLD(FCYN("Selection: ")); //Selection text for user (choice)
	cin >> confirmSelection; //Store our user's selection to confirm
	if(selectedSeat == A) //If user selected seat is equal to 'A' then execute
		int selectedConvertedSeat = 0; //Create integer value to be used for array corresponding to letter from user
	else if(selectedSeat == B) //If user selected seat is equal to 'B' then execute
		int selectedConvertedSeat = 1; //Create integer value to be used for array corresponding to letter from user
	else if(selectedSeat == C) //If user selected seat is equal to 'C' then execute
		int selectedConvertedSeat = 2; //Create integer value to be used for array corresponding to letter from user
	else //Any other case ('D') then execute
		int selectedConvertedSeat = 3; //Create integer value to be used for array corresponding to letter from user
	if(confirmSelection == 1){ //If our user selects 1 ("Confirm")
		if(tempArray[selectedRow-1][selectedConvertedSeat]){ //Check to see if the selected part of the array is true (reserved)
			cout << BOLD(FRED("That seat is already reserved!")) << endl; //Print reserved message to user
			exit(EXIT_SUCCESS); //Exit program successfully
		}
		else{ //If not reserved, then execute (prepare to write)
			tempArray[selectedRow-1][selectedConvertedSeat] = true; //Add user selected seat and row to the array
		}
	}
	else{ //If user selects anything else other than '1'
		cout << "Exiting program!" << endl; //Print exit message
		exit(EXIT_SUCCESS); //Exit with success
	}
	writeReserveSeats(writeableFilename,tempArray); //Call write function (Because had issues with reading/writing and fully overwriting file in one function)
	system("clear"); //Clear our screen
	cout << BOLD(FGRN("Reserved seat!")) << endl; //Print confirmation message to user
}

void writeReserveSeats(string writeableFilename,bool inputArr[][arrayColumns]){
	ofstream inFile; //Define file variable to be used for output
	char indexes[4] = {'A','B','C','D'}; //Store our chars into a small array
	string myString = ""; //Initilize empty string
	inFile.open(writeableFilename.c_str()); //Open our file to write
	for(int i = 0;i < arrayRows;i++){ //First for loop (for looping through rows)
		for(int j = 0;j < arrayColumns;j++){ //Second for loop (nested) for printing column in array
			//cout << inputArr[i][j] << " "; //Used for debug purposes (prints array)
			myString += (inputArr[i][j] ? 'X' : indexes[j]); //Using Elvis Operator [IFTRUE ? THIS : ELSETHIS]
			myString += " "; //Add a space after our letter
		}
		inFile << i+1 << " " << myString << endl; //Add our string and such to the file
		myString = ""; //Reset string for next entry
		//cout << endl; //Used for debug purposes (goes down a line for printing array)
	}
	inFile.close(); //Close our file
}

void resetReservedSeats(string doNotEditFilename,string writeableFilename){
	system("clear"); //Clear our screen
	string currentLine,seatA,seatB,seatC,seatD; //Define variables to be used later
	string ignoreLine = ("---------PLEASE DO NOT EDIT THIS FILE---------"); //Define line to be ignored in the file
	int currentRow,confirmSelection; //Define variables to be used later
	ifstream inFile; //Define our file variables
	ofstream outFile; //Define our file variables
	inFile.open(doNotEditFilename.c_str()); //Open our non-editable file
	outFile.open(writeableFilename.c_str()); //Open our editable file
	cout << FCYN("Checking if file hash matches file: ") << doNotEditFilename << " ..." << endl << endl; //Print info message to user
	sleep(1); //Sleep for 1 second
	cout << BOLD(FGRN("============================================================")) << endl << endl; //Fancy lines
	cout << BOLD(FGRN("		 File hash verified. Continuing...")) << endl << endl; //Print info message to user
	cout << BOLD(FGRN("============================================================")) << endl << endl; //Fancy lines
	sleep(2); //Sleep for 2 seconds -- adds affects (Why not?)
	system("clear"); //Clear our screen
	cout << UNDL(FMAG("Are you sure you want to reset the seating chart? This will reset ALL current reservations.")) << endl << endl;
	cout << FMAG(" [1] ") << UNDL(FGRN("Yes, reset all current reservations")) << endl << endl; //First menu selection
	cout << FMAG(" [2] ") << UNDL(FRED("No, exit now!")) << endl << endl; //Second menu selection
	cout << BOLD(FCYN("Selection: ")); //Selection text for user (choice)
	cin >> confirmSelection; //Store our selection
	system("clear"); //Clear our screen
	if(calculateFileHash(doNotEditFilename)){ //Do master hash check to make sure our file isn't modified
		if(confirmSelection == 1){ //User selected "Yes, reset all current reservations"
				if(!inFile){ //If our file doesn't exist
					system("clear"); //Clear screen so we show only the error message
					cerr << BOLD(FRED("---------------------------------------------------------------------------------------")) << endl; //Fancy lines
					cerr << BOLD(FRED("						   Unable to open ")) << doNotEditFilename << BOLD(FRED(" !")) << endl << endl; //Print error message
					cerr << BOLD(FRED("Please make sure you have the file in the correct directory so the program can read it.")) << endl << endl; //Print error info message
					cerr << BOLD(FRED("---------------------------------------------------------------------------------------")) << endl; //Fancy lines
					exit(EXIT_FAILURE); //End program with failure
				}
				if(!outFile){ //If our file doesn't exis
						system("clear"); //Clear screen so we show only the error message
						cerr << BOLD(FRED("---------------------------------------------------------------------------------------")) << endl; //Fancy lines
						cerr << BOLD(FRED("						   Unable to open ")) << writeableFilename << BOLD(FRED(" !")) << endl << endl; //Print error message
						cerr << BOLD(FRED("Please make sure you have the file in the correct directory so the program can read it.")) << endl << endl; //Print error info message
						cerr << BOLD(FRED("---------------------------------------------------------------------------------------")) << endl; //Fancy lines
						exit(EXIT_FAILURE); //End program with failure
				}
				while(getline(inFile,currentLine)){ //Do a loop for the entire file
					size_t findIgnoredLines = currentLine.find(ignoreLine); //Define how to find ignore part of the file
					if(findIgnoredLines == string::npos){ //Do a check to see if the line we want to ignore is there
							istringstream ss(currentLine); //Use stringstream to read the values
							ss >> currentRow >> seatA >> seatB >> seatC >> seatD; //Store all the variables into memory and into seperate variables
							outFile << currentRow << " " << seatA << " " << seatB << " " << seatC << " " << seatD << endl; //Write to new file
					}
				}
				inFile.close(); //Close our files
				outFile.close(); //Close our files
				cout << BOLD(FGRN("---------------------------------------------------------------------------------------")) << endl; //Fancy lines
				cout << BOLD(FGRN("---------------------------------------------------------------------------------------")) << endl; //Fancy lines
				cout << BOLD(FGRN("=======================================================================================")) << endl << endl; //Fancy lines
				cout << BOLD(FGRN("                           Successfully Reset Seating Chart!")) << endl << endl; //Print success message to user
				cout << BOLD(FGRN("=======================================================================================")) << endl; //Fancy lines
				cout << BOLD(FGRN("---------------------------------------------------------------------------------------")) << endl; //Fancy lines
				cout << BOLD(FGRN("---------------------------------------------------------------------------------------")) << endl; //Fancy lines
		}
		else if(confirmSelection == 2){ //User selected "No, exit now"
			system("clear"); //Clear screen so we show only the error message
			cout << BOLD(FRED("Exiting...")) << endl; //Print exit message to user
			exit(EXIT_SUCCESS); //Exit with success
		}
		else{ //Welp, the user managed to select literally anything other than 1, or 2 -- great job you broke it
			system("clear"); //Clear screen so we show only the error message
			cerr << BOLD(FRED("Invalid selection! Exiting...")) << endl << endl; //Print error message to user
			exit(EXIT_FAILURE); //Exit with failure
		}
	}
	else{ //Welp, someone dun goofed
		cerr << BOLD(FRED("---------------------------------------------------------------------------------------")) << endl; //Fancy lines
		cerr << BOLD(FRED("---------------------------------------------------------------------------------------")) << endl; //Fancy lines
		cerr << BOLD(FRED("=======================================================================================")) << endl << endl; //Fancy lines
		cerr << BOLD(FRED("                FILE HASH OF FILE IN CONFIG DOES NOT MATCH! EXITING...")) << endl << endl; //Ruh roh! Someone messed with the file. Little 'ol hash function doesn't like that
		cerr << BOLD(FRED("=======================================================================================")) << endl; //Fancy lines
		cerr << BOLD(FRED("---------------------------------------------------------------------------------------")) << endl; //Fancy lines
		cerr << BOLD(FRED("---------------------------------------------------------------------------------------")) << endl; //Fancy lines
		exit(EXIT_FAILURE); //End program
	}
}
