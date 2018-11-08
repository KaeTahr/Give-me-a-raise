#include <string>
#include <iostream>
using namespace std;

//Global Variables
bool bGameRunning;

string getUserInput()
{ 
	string sInput;
	cout << "What will you do?" << endl;
	cin >> sInput;
	
	return sInput;
}

void parseInput(string sInput)
{ 
	if (sInput == "dab")
	{ 
		 cout << "You dab" << endl << "*dabs" << endl;
	}
	if ( sInput == "attack" || sInput == "hit" || sInput == "strike")
	{ 
		cout << "You the undesirables" << endl;
	}
	if ( sInput == "quit")
	{
		bGameRunning = 0;
	}
}

int main ()
{ 
	bGameRunning = 1;

	while ( bGameRunning == 1)
	{ 
	
		//Variables and Strings
		string sUserInput;
		oRoom oMatMap[50][50];

		//Input
		sUserInput = getUserInput();

		//Processing
		parseInput(sUserInput);

		//Ouput
		//printStory();
	}
	
	return 0;

}
