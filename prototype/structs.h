#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct oPickup
{ 
	string sName;
	string sDescription;
	bool bHidden;
	int iID; //Pickups IDs start with 1
	
};

struct oInteractables
{ 
	string sName;
	string sDescription;
	bool bCanRead, bCanDestroy, bCanOpen, bCanClose, bCanPress, bCanPull, bCanPush, bHidden;
	string sRead;
	int iID; //Interactables IDs start with 2
	
};

struct oRoom
{ 
	string sName;
	string sDescription;
	bool bNorth, bSouth, bEast, bWest;
	oPickup oArrPickups[10];
	int iHowManyPickups;
	oInteractables oArrInteractables[10];
	int iHowManyInteractables;
};

//NOT FINISHED
struct oInventory
{ 
	string sName;
	bool bCanCombine, bCandrink, bCanEat,bCanEquip;
	int iID; //Inventory items start with 3
};

struct oGamer
{ 
	oInventory oArrInventory[10];
	int iLocation[2];
	int iHP = 100;


};
