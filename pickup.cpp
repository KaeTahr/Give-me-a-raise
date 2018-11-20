#include <iostream>
#include <string>
#include "structs.h"
using namespace std;

/* takePickup
 * Checks whether the pickup the user is trying to take exists, and if it does, it adds it to the inventory
 * Inputs: The map matrix, the player, the name of the item the player wants to pick
 * Output: Writes to the player inventory
 */
void takePickup( oRoom oMatMap[3][10][10], oGamer &oPlayer, string sItem)
{ 
	bool bTaken = false;
	for ( int iCounter = 0; iCounter < oMatMap[oPlayer.iLocation[0]][oPlayer.iLocation[1]][oPlayer.iLocation[2]].iHowManyPickups; iCounter ++)
	{ 
		if ( sItem == oMatMap[oPlayer.iLocation[0]][oPlayer.iLocation[1]][oPlayer.iLocation[2]].oArrPickups[iCounter].sNameP && oMatMap[oPlayer.iLocation[0]][oPlayer.iLocation[1]][oPlayer.iLocation[2]].oArrPickups[iCounter].bHidden == false)
		{ 
			if (oMatMap[oPlayer.iLocation[0]][oPlayer.iLocation[1]][oPlayer.iLocation[2]].oArrPickups[iCounter].bPicked == false)
			{ 
				oMatMap[oPlayer.iLocation[0]][oPlayer.iLocation[1]][oPlayer.iLocation[2]].oArrPickups[iCounter].bPicked = true;
				cout << "You picked up a " << sItem << endl;
				oPlayer.oArrInventory[oPlayer.iInInventory].sName = sItem;
				bTaken = true;
				oPlayer.iInInventory++;
				break;

					
			}
			else
			{ 
				cout << "You already picked the " << sItem << " that was here" << endl;

			}
		}
		if ( bTaken == false)
		{ 
			cout << "You can't take the " << sItem <<  endl;
		}
	}
	
	if ( bTaken == false)
	{ 
		cout << "You can't take the " << sItem <<  endl;
	}
}

