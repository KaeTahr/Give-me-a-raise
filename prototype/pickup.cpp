#include <iostream>
#include <string>
#include "structs.h"
using namespace std;

void takePickup( oRoom oMatMap[3][10][10], oGamer &oPlayer, string sItem)
{ 
	for ( int iCounter = 0; iCounter < oMatMap[oPlayer.iLocation[0]][oPlayer.iLocation[1]][oPlayer.iLocation[2]].iHowManyPickups; iCounter ++)
	{ 
		if ( sItem == oMatMap[oPlayer.iLocation[0]][oPlayer.iLocation[1]][oPlayer.iLocation[2]].oArrPickups[iCounter].sNameP && oMatMap[oPlayer.iLocation[0]][oPlayer.iLocation[1]][oPlayer.iLocation[2]].oArrPickups[iCounter].bHidden == false)
		{ 
			if (oMatMap[oPlayer.iLocation[0]][oPlayer.iLocation[1]][oPlayer.iLocation[2]].oArrPickups[iCounter].bPicked == false)
			{ 
				oMatMap[oPlayer.iLocation[0]][oPlayer.iLocation[1]][oPlayer.iLocation[2]].oArrPickups[iCounter].bPicked = true;
				cout << "You picked up a " << sItem << endl;
				oPlayer.oArrInventory[oPlayer.iInInventory].sName = sItem;
				oPlayer.iInInventory++;
				break;

					
			}
			else
			{ 
				cout << "You already picked the " << sItem << " that was here" << endl;
			}
		}
		else 
		{ 
			cout << "There are no " << sItem << " here." << endl;
		}
	}
}

