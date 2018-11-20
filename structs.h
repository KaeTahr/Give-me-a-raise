#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
using namespace std;

struct oPickup
{ 
	string sNameP;
	string sDescription;
	bool bHidden;
	bool bPicked;
	int iID; //Pickups IDs start with 1
	
};

struct oInteractables
{ 
	string sNameI;
	bool bCanActivate, bCanExamine;
	string sExamination;
	string sActivated;
	int iID; //Interactables IDs start with 2
	
};

struct oStairs
{ 
	bool bCanGoUp, bCanGoDown;
};

struct oRoom
{ 
	string sName;
	string sDescription;
	bool bNorth, bSouth, bEast, bWest, bStairs;
	oStairs oStaircase;
	oPickup oArrPickups[10];
	int iHowManyPickups = 0;
	oInteractables oArrInteractables[10];
	int iHowManyInteractables = 0;
	short int iHowManyVisits = 0;
	string sVisit;
};

//NOT FINISHED
struct oInventory
{ 
	string sName;
	bool bCanUse;
	int iID; //Inventory items start with 3
};

struct oGamer
{ 
	int iInInventory;
	oInventory oArrInventory[10];
	int iLocation[3] = {0, 0, 0};

};
