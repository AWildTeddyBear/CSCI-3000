/*
	You found the debug menu who never really made it to the light of day, huh?
	This thing IS broken and was NOT finished. I am including it simply becuase I can.
	If you decide to use this, it's better to just re-write it entirely honestly.
*/

#include "allTheAscii.hpp" //Just so we have our headers and stuff...

using namespace std;

bool guessLetter(bool enableDebug,vector<char> charArray,char guess){
	(enableDebug ? cout << "DEBUG: Running convertToBlankPhrase function..." << endl : cout << "Error: Debug function being run incorrectly!" << endl);
	return find(charArray.begin(),charArray.end(),tolower(guess)) != charArray.end();
}

string convertToBlankPhrase(bool enableDebug,vector<char> output){
	(enableDebug ? cout << "DEBUG: Running convertToBlankPhrase function..." << endl : cout << "Error: Debug function being run incorrectly!" << endl);
	string blankPhrase;
    for(auto c : output) //Loop for each letter in the array
         blankPhrase.append((c ==  ' ') ? " " : "_"); //Append a space if a space is found, and a _ if a letter is found
    return blankPhrase;
}

void splitStringToChar(bool enableDebug,string input,vector<char> &output){
	(enableDebug ? cout << "DEBUG: Running splitStringToChar function..." << endl : cout << "Error: Debug function being run incorrectly!" << endl);
	for(int i = 0;i < input.size();output.push_back(tolower(input[i])),i++); //Reference our new char array back to where it was called
}

void debugMenu(bool enableDebug,vector<string> wordsConfig,vector<char> charArray,char guess){
	if(enableDebug){
		cout << string(100,'-') << endl;
		cout << string(100,'-') << endl;
		cout << string(42,'-') << " DEBUG ENABLED " << string(43,'-') << endl;
		cout << string(100,'-') << endl;
		cout << string(100,'-') << endl << endl << endl;

		cout << "(1) - Print wordsConfig [String Config Array]" << endl;
		cout << "(2) - Print charArray [Character dynamic array]" << endl;
		cout << "(3) - Print wordsConfig size [Total number of elements in our config array]" << endl;
		cout << "(4) - Print charArray size [Total number of elements in our dynamic char array]" << endl;
		cout << "(5) - Print convertToBlankPhrase output [Requires input]" << endl;
		cout << "(6) - Print splitStringToChar output [Requires input]" << endl;
		cout << "(7) - Print guessLetter output [Requires input]" << endl;
		cout << "(8) - Exit debug menu" << endl;

		int debugChoice;
		cout << "Selection: ";
		cin >> debugChoice;



		bool enableDebug = true; //Globally turn on debug for our functions



		switch(debugChoice){
			case 1: {
			system("clear");
			cout << "Printing wordsConfig [String Config Array]..." << endl;
			sleep(2);
			system("clear");
			for(int i = 0;i < wordsConfig.size();i++)
				cout << "wordsConfig[" << i << "] -- " << wordsConfig[i] << endl;
			break;
			}

			case 2: {
			system("clear");
			cout << "Printing charArray [Character dynamic array]..." << endl;
			sleep(2);
			system("clear");
			for(int i = 0;i < charArray.size();i++)
				cout << "charArray[" << i << "] -- " << charArray[i] << endl;
			break;
			}

			case 3: {
			system("clear");
			cout << "Printing wordsConfig size [Total number of elements in our config array]..." << endl;
			sleep(2);
			system("clear");
			cout << "wordsConfig Size: " << wordsConfig.size() << endl;
			break;
			}

			case 4: {
			system("clear");
			cout << "Printing charArray size [Total number of elements in our dynamic char array]..." << endl;
			sleep(2);
			system("clear");
			cout << "charArray Size: " << charArray.size() << endl;
			break;
			}

			case 5: {
			system("clear");
			cout << "Initialising convertToBlankPhrase function..." << endl;
			sleep(2);
			system("clear");
			cout << "We're going to need to you enter a string which we will pass to splitStringToChar and pass to our function, we need a char vector array to continue..." << endl;
			cout << "Entry: ";
			string stringInput;
			vector<char> output;
			getline(cin,stringInput);
			cin.ignore();
			cout << endl;
			splitStringToChar(enableDebug,stringInput,output);
			cout << "DEBUG: convertToBlankPhrase -- " << convertToBlankPhrase(enableDebug,output) << endl;
			break;
			}

			case 6:
			system("clear");

			break;

			case 7:
			system("clear");

			break;

			case 8:
			system("clear");
			cout << "Exiting debug menu..." << endl;
			sleep(1);
			exit(EXIT_SUCCESS);
			break;
		}
	}
}