#include <iostream>
#include <string>
#include "structs.h"

void teleport ( oRoom oMatMap[3][10][10], oGamer &oPlayer)
{
	if ( oPlayer.iLocation[0] == 0 && oPlayer.iLocation[1] == 3 && oPlayer.iLocation[2] == 0 && oMatMap[0][3][0].iHowManyVisits == 1)
	{
		oPlayer.iLocation[0] = 2;
		oPlayer.iLocation[1] = 1;
		oPlayer.iLocation[2] = 3;
		oPlayer.iInInventory = 0;
		oMatMap[0][3][0].iHowManyVisits = 0;
	}
}
