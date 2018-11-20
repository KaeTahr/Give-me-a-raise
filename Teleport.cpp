#include <iostream>
#include <string>
#include "structs.h"

/* teleport
 * Triggered events that move the player
 * Inputs: the map matrix, the player
 * Outputs: may change the player location
 */
void teleport ( oRoom oMatMap[3][10][10], oGamer &oPlayer)
{
	if ( oPlayer.iLocation[0] == 0 && oPlayer.iLocation[1] == 3 && oPlayer.iLocation[2] == 0 && oMatMap[0][3][0].iHowManyVisits == 1)
	{
		oPlayer.iLocation[0] = 2;
		oPlayer.iLocation[1] = 1;
		oPlayer.iLocation[2] = 3;
		oPlayer.iInInventory = 0;
		oMatMap[0][3][0].iHowManyVisits = 0;
		oMatMap[0][1][2].bSouth = 1;
		oMatMap[0][2][2].bSouth = 1;
	}
}
