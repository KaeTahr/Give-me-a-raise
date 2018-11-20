#include <iostream>
#include "structs.h"
#include <string>
#include <fstream>
using namespace std;

/* leave
 * processes the player attempt to leave, checking if he can leave from the position he is in, if he has the requried items, and lastly it processes whether the player will get the good ending or the bad ending based on his progress
 * Input: Map matrix, the player, and the game loop bool
 * Outputs: May change the game loop bool
 */
void leave ( oRoom oMatMap[3][10][10], oGamer oPlayer, bool &bGameRunning)
{ 
	bool bKey = false;
	bool bSubject = false;
	bool bCure = false;
	if ( oPlayer.iLocation[0] == 1 && oPlayer.iLocation[1]  == 1 && 1 && oPlayer.iLocation[2] == 1)
	{ 
		//check keycard
		for ( int iCounter = 0; iCounter < oPlayer.iInInventory; iCounter++)
		{ 
			if ( oPlayer.oArrInventory[iCounter].sName == "keycard")
			{ 
				bKey = true;
			}
		}
		if ( bKey == true)
		{ 
			for ( int iCounter = 0; iCounter < oPlayer.iInInventory; iCounter++)
			{ 
				if ( oPlayer.oArrInventory[iCounter].sName == "subject")
				{ 
					bSubject = true;
					break;
				}
			}
			if (bSubject == true)
			{ 
				
				for ( int iCounter = 0; iCounter < oPlayer.iInInventory; iCounter++)
				{ 
					if ( oPlayer.oArrInventory[iCounter].sName == "cure")
					{ 
						bCure = true;
						break;
					}
				}
				if ( bCure == true)
				{ 
				
					ifstream fGoodEnd;
					fGoodEnd.open("GoodEnding.txt");
					string sBuffer;
					int iEnd = 0;
					while ( iEnd < 10)
					{ 
						getline (fGoodEnd, sBuffer );
						cout << sBuffer << endl;
						iEnd++;
					}
					fGoodEnd.close();
					bGameRunning = false;
				}
				else
				{
					ifstream fBadEnd;
					fBadEnd.open("BadEnding.txt");
					string sBuffer;
					int iEnd = 0;
					while ( iEnd < 13)
					{ 
						getline (fBadEnd, sBuffer );
						cout << sBuffer << endl;
						iEnd++;
					}
					fBadEnd.close();
					bGameRunning = false;

 
	
				}
			}
			else 
			{ 
				cout << "You can't leave without evidence! Maybe you can find a subject the Doctor was experminenting on" << endl;
			}
		}
		else 
		{ 
			cout << "You don't have the key!" << endl;
		}
	}
	else 
	{
		cout << "You can't leave from here!" << endl;
	}
}

							
