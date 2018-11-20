#include <iostream>
#include "structs.h"
#include <string>
#include <fstream>
using namespace std;

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
				cout << "You can't leave without the subject as evidence!" << endl;
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

							
