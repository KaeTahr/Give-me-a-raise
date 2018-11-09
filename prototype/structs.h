#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct oPickup
{ 
	string sDescription;
	bool bHidden;
	
};

struct oInteractables
{ 
	string sDescription;
	bool bCanRead, bCanDestroy, bCanOpen, bCanClose, bCanPress, bCanPull, bCanPush, bHidden;
	string sRead;
	
};

struct oRoom
{ 
	string sDescription;
	bool bNorth, bSouth, bEast, bWest;
	oPickup oArrPickups[10];
	int iHowManyPickups = 0;
	oInteractables oArrInteractables[10];
	int iHowManyInteractables = 0;
};

//NOT FINISHED
struct oInventory
{ 
	bool bCanCombine, bCandrink, bCanEat,bCanEquip;
};

struct oGamer
{ 
	oInventory oArrInventory[10];
	int iLocation[2] = {0, 0};
	int iHP = 100;


};
