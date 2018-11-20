#include <iostream>
#include <string>
#include "structs.h"

/* riddle
 * a minigame the player needs to complete
 * Inputs: The map matrix and the player
 * Outputs: when solved, writes to the map matrix
 */
 
 
void riddle ( oRoom oMatMap[3][10][10], oGamer oPlayer, bool &bGameRunning)
{
	bool bCorrect = false;
	string sAnswer;
	cout << "The computer reads the following: 'Answer the following to open an exit: \"Pepe's father has three children: Jesus, Maria, and ____ .\" '" << endl;
	while ( bCorrect == false)
	{
		cin >> sAnswer;
		if ( sAnswer == "Pepe" || sAnswer == "pepe")
		{
			bCorrect = true;
		}
		else if (sAnswer == "exit")
		{
			cout << "Shutting down..." << endl;
			return;
		}
		else if (sAnswer == "lowphonecalls")
		{
			cout << endl;
			ifstream fSecretEnd;
			fSecretEnd.open("SecretEnding.txt");
			string sBuffer;
			int iEnd = 0;
			while ( iEnd < 10)
			{ 
				getline (fSecretEnd, sBuffer );
				cout << sBuffer << endl;
				iEnd++;
			}
			fSecretEnd.close();
			bGameRunning = false;
			return;
		}
		
		else 
		{
			cout << "Incorrect, try again" << endl;
		}
	}
	
	if ( bCorrect == true) 
	{
		oMatMap[2][3][1].oStaircase.bCanGoDown = true;
		cout << "A passageway has been revealed in the novel sections of the bookshelf" << endl << "For smart guys: lqsxw ilqg forwkhv rq urrp Ehg 4 wr ilqg dq hdvwhu hjj"<< endl;
		oMatMap[2][3][1].sDescription = "The bookshelf has moved revealing a staircase heading down.";
	}
	
}
