#include <iostream>
#include <string>
#include "structs.h"

void riddle ( oRoom oMatMap[3][10][10], oGamer oPlayer)
{
	bool bCorrect = false;
	string sAnswer;
	cout << "The computer reads the following: 'Write the shortest palindrome existant to find an exit'. A Mental Challenge" << endl;
	while ( bCorrect == false)
	{
		cin >> sAnswer;
		if ( sAnswer.size() == 1)
		{
			bCorrect = true;
		}
		else {
			cout << "Incorrect, try again" << endl;
		}
	}
	
	if ( bCorrect == true) 
	{
		oMatMap[2][3][1].oStaircase.bCanGoDown = true;
		cout << "A passageway has been revealed in the novel sections of the bookshelf" << endl << "For smart guys: lqsxw ilqg forwkhv rq urrp Ehg 4 wr ilqg dq hdvwhu hjj"<< endl;
	}
	
}
