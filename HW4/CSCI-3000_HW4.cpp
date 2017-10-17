/*
Developed by NotADeveloper
C++ Palindrome With Pointers
---------------------------
XXXXXXXXXXXXXXXXX - XXXXXX
CSCI 3000, HW4
October 15, 2017 -- WAYYY past due. -- Uploaded 10-4-2017
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
				  =+=+=+= g++ -std=c++17 CSCI-3000_HW4.cpp -o out =+=+=+=
=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=

=================================================================================================
-------------------------------------------------------------------------------------------------
----------------------------------------ATTENTION------------------------------------------------
-------------------------------------------------------------------------------------------------
=================================================================================================
*/

#include <iostream>
#include <cstring>
#include <cstdlib>

bool isPalindrome(char* cstr);

main(){
	char s1[50] = "neveroddoreven";
	char s2[50] = "not a palindrome";

	if(isPalindrome(s1))
		std::cout << s1 << " is a palindrome." << std::endl;
	else
		std::cout << s1 << " is not a palindrome." << std::endl;

	if(isPalindrome(s2))
		std::cout << s2 << " is a palindrome." << std::endl;
	else
		std::cout << s2 << " is not a palindrome." << std::endl;

	exit(EXIT_SUCCESS);
}

bool isPalindrome(char* cstr){
	char* front = cstr;
	char* back = cstr + strlen(cstr)-1;

	while(front < back){
		if(*front != *back){
			return false;
		}
		front++;
		back--;
	}
	return true;
}
