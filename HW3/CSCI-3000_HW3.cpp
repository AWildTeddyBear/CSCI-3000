/*
Developed by NotADeveloper
C++ Hangman Game
---------------------------
XXXXXXXXXXXXXXXXX - XXXXXX
CSCI 3000, HW3
September 25, 2017 -- WAYYY past due. -- Uploaded 10-4-2017
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
		=+=+=+= g++ -std=c++17 CSCI-3000_HW3.cpp -o out =+=+=+=
=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=

=================================================================================================
-------------------------------------------------------------------------------------------------
----------------------------------------ATTENTION------------------------------------------------
-------------------------------------------------------------------------------------------------
=================================================================================================
*/

#include "allTheAscii.hpp" //This has all our includes we need along with a lot more
//#include "debug.hpp" -- I was going to make this to debug for me mainly, but I never finished it and I'm pretty sure it doesn't even work right now. Don't really include this file unless you want to re-write it.

using namespace std; //Moving away from this soon


//Let's define our function prototypes
bool guessLetter(vector<char> charArray,char guess),isGameOver(vector<char> charArray,string blankPhrase);
void splitStringToChar(string input,vector<char> &charArray),startGame(vector<string> wordsConfig),appendModifiedWord(vector<char> charArray,string &blankPhrase,char guess);
string convertToBlankPhrase(vector<char> charArray);

main(){
	vector<string> wordsConfig = { //Define our words our player has to guess, our game will randomly select one of these to use.
		"Back to Square One", //Homework pre-defined strings
		"Easy as Pie", //Homework pre-defined strings
		"Elepant in the Room", //Homework pre-defined strings
		"Fish Out of Water", //Homework pre-defined strings
		"Needle in a Haystack", //Homework pre-defined strings
		"Hello World",
		"AWildTeddyBear",
		"Why do I Make This so Complicated" //Exactly my thoughts on this whole thing...
	};
	intro(); //Call the intro function -- Hey, it's changed finally. (A will be next time as well)
	startGame(wordsConfig); //Start our game by passing our config over
	exit(EXIT_SUCCESS); //Exit the program once functions are done
}

void splitStringToChar(string input,vector<char> &charArray){
	for(int i = 0;i < input.size();charArray.push_back(tolower(input[i])),i++); //Reference our new char array back to where it was called
}

string convertToBlankPhrase(vector<char> charArray){
    string blankPhrase; //Create a string variable to be used
	for(auto c : charArray) //For every element in charArray, make charArray[i] = c. This is simpler than for(int i ...) loops
         blankPhrase.append((c ==  ' ') ? " " : "_"); //Decide if we want to append a space or a underscore to our new string. This is actually what makes the ____ __ _____ part [Example]
    return blankPhrase; //Return our string back to the function who called it
}

void appendModifiedWord(vector<char> charArray,string &blankPhrase,char guess){
	for(int i = 0;i < charArray.size();i++){ //Do a traditional for loop -- could have used the new one, but not that super familiar with it yet
		if(charArray[i]==guess) //Check to see if our user actually guessed a correct letter
			blankPhrase[i] = tolower(guess); //If our user guessed correctly, then change it in blankPhrase -- this is what changes ____ ___ _____ to _o___ o_ _____ [Example]
	}
}

bool isGameOver(vector<char> charArray,string blankPhrase){
	int counter = 0; //Create a counter int variable and default the value to 0
	bool gameResult; //Create a bool variable to be used below
	for(int i = 0;i < charArray.size();i++){ //Traditional for loop for all elements in charArray
		if(charArray[i]==blankPhrase[i]) //Check to see if the letters within charArray are equal to blankPhrase (In other words, check to see if the user guessed the whole word)
			counter++; //Add our counter up one for the check below
	}
	(counter==charArray.size() ? gameResult = true : gameResult = false); //Do a check to see if our counter variable equals the total number of letters in charArray (This actually checks to see if the word is guessed or not)
	return gameResult; //Return our bool value back to the function that called it
}

bool guessLetter(vector<char> charArray,char guess){
    return find(charArray.begin(),charArray.end(),tolower(guess)) != charArray.end(); //Return a BOOL that checks to see if the user has guessed a correct letter -- this could have been done better
}

void startGame(vector<string> wordsConfig){
	int maxPlayerGuesses = 10,incorrectGuesses = 0; // Define our maxGuesses and our variable to be used to track incorrectGuesses
	srand((unsigned)time(0)); //Seed our random time to be used later
	vector<char> charArray,guesses; //Define our charArray to be filled in splitStringToChar -- Also define our guesses array to be used
	splitStringToChar(wordsConfig[rand()%wordsConfig.size()],charArray); //Call our function to convert a randomly picked string from config into a charArray
	string blankPhrase = convertToBlankPhrase(charArray); //Define our ____ ____ phrase to be shown to the user to guess
	char guess; //Define our char variable to be used for our user to guess
	bool hasGuessedAlready,gameInProgress = true; //Setup our bools to be used later -- also default gameInProgress to true so our loop below can run

	while(gameInProgress){ //Always loop this while our user is still playing
		if(isGameOver(charArray,blankPhrase)){ //Check to see if the user has guessed all the letters
			asciiYouWin(); //Laser beams are the way to go
			gameInProgress = false; //Make sure our loop can't run anymore
			break; //Break out of while() prison
		}
		if(incorrectGuesses == maxPlayerGuesses){ //Check if our user has guessed incorrectly too many times
			asciiYouLose(); //Call our little WW-I airplane to break the news
			gameInProgress = false; //Make sure our loop can't run anymore
			break; //Break out of while() prison		
		}

		printHangman(incorrectGuesses,blankPhrase); //Print our hangman back to the user showing how many incorrect guesses they have
		cin >> guess; //Get our user to input a guess

		for(int i = 0;i < guesses.size();(guesses[i]==guess ? hasGuessedAlready = true : hasGuessedAlready = false),i++); //Set a variable to check to see if out user already guessed a letter to be used later
		if(guessLetter(charArray,guess) && !hasGuessedAlready) //Check if the letter guessed is correct and also check to see if the user already has guessed that letter
			appendModifiedWord(charArray,blankPhrase,guess); //If the letter is correct, then we want to put it into our blankPhrase --AW__dTeddy_Bear
		else
			incorrectGuesses++; //Welp you dun diddly guessed wrong, +1 to gryphonWrong
		
		cin.clear(); //Clear our our cin so it's not cluttered
		guesses.push_back(guess); //Put our guess into our vector array so we can check against it
		hasGuessedAlready = false; //Reset our bool so the check can do its thing again
		system("clear"); //Clear our screen
	}
}
