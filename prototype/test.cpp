#include <iostream>
#include <fstream>
#include <string>
#include "structs.h"
using namespace std;

//Global Variables
bool bGameRunning; //For game loop

/* getMap
 * Functions reads the map from an external file in the following order:
 * #Rows
 * #Columns
 *  (Enters Loop) Room Description
 *  Possible Routes of movement ( N S E W)
 *  Pickups ( Descriptions and whether they are hidden)
 *  Interactables ( Descriptions and all other attributes)
 *  Inputs: Functions Reads from a file
 *  Outputs: Functiion Writes to an Array containing all the information on the map of the game, as well as it dimensions for further operations with the map
 */
void getMap( oRoom oMatMap[50][50], int &iMapRows, int &iMapColumns)
{ 
	ifstream fMap;
	fMap.open( "Test.map");
	string sBuffer;//Needed to use this because reading from a file doesn't play nice when mixing strings and other datatypes
	if ( fMap.is_open())
	{ 
	
		//Get Map Dimensions	

		//REMEMBER: this process for reading a whole line, then converting it to a number
		//and never again mix datatypes when reading from a file this way
		getline( fMap, sBuffer);
		iMapRows = strtol( sBuffer.c_str(), NULL, 10);
		//cout << iMapRows << "is columns" << endl;

		getline( fMap, sBuffer);
		iMapColumns = strtol( sBuffer.c_str(), NULL, 10);
		//cout << iMapColumns << "is columns" << endl;
		
		//Get Map Information
		for ( int iIndexRows = 0; iIndexRows < iMapRows; iIndexRows++)
		{ 
			for (int iIndexColumns = 0; iIndexColumns < iMapColumns; iIndexColumns++)
			{ 
				getline( fMap, oMatMap[iIndexRows][iIndexColumns].sDescription); //Save Description
				
				
				//Where can you go?
				getline( fMap, sBuffer);
				oMatMap[iIndexRows][iIndexColumns].bNorth = strtol( sBuffer.c_str(), NULL, 10);
			
				getline( fMap, sBuffer);
				oMatMap[iIndexRows][iIndexColumns].bSouth = strtol( sBuffer.c_str(), NULL, 10);

				getline( fMap, sBuffer);
				oMatMap[iIndexRows][iIndexColumns].bEast = strtol( sBuffer.c_str(), NULL, 10);

				getline( fMap, sBuffer);
				oMatMap[iIndexRows][iIndexColumns].bWest = strtol( sBuffer.c_str(), NULL, 10);
				//Pickups
				bool bPickups;
				//Are there any pickups?
				getline( fMap, sBuffer );
				oMatMap[iIndexRows][iIndexColumns].iHowManyPickups = strtol( sBuffer.c_str(), NULL, 10);
				
				if ( oMatMap[iIndexRows][iIndexColumns].iHowManyPickups > 0)
				{ 

					//Get Info on items, if there are items
					int iCounterPickups = 0;
					while ( iCounterPickups < oMatMap[iIndexRows][iIndexColumns].iHowManyPickups)
					{ 
						//Get Description
						getline( fMap, oMatMap[iIndexRows][iIndexColumns].oArrPickups[iCounterPickups].sDescription);
						//Hidden?
						getline( fMap, sBuffer);
						oMatMap[iIndexRows][iIndexColumns].oArrPickups[iCounterPickups].bHidden = strtol( sBuffer.c_str(), NULL, 10);
						iCounterPickups++;

					}
				}
				//End of Pickups stuff

				//Interactables

				//Are there any interactables? How Many?
				getline( fMap, sBuffer );
				oMatMap[iIndexRows][iIndexColumns].iHowManyInteractables = strtol( sBuffer.c_str(), NULL, 10);
				
				if ( oMatMap[iIndexRows][iIndexColumns].iHowManyInteractables > 0)
				{ 

					//Get Info on items, if there are items
					int iCounterInteractables = 0;
					while ( iCounterInteractables < oMatMap[iIndexRows][iIndexColumns].iHowManyInteractables)
					{ 
						//Get Description
						getline( fMap, oMatMap[iIndexRows][iIndexColumns].oArrInteractables[iCounterInteractables].sDescription);
						//Hidden?
						getline( fMap, sBuffer);
						oMatMap[iIndexRows][iIndexColumns].oArrInteractables[iCounterInteractables].bHidden = strtol( sBuffer.c_str(), NULL, 10);
						//Readable
						getline( fMap, sBuffer);
						oMatMap[iIndexRows][iIndexColumns].oArrInteractables[iCounterInteractables].bCanRead = strtol( sBuffer.c_str(), NULL, 10);
						if ( oMatMap[iIndexRows][iIndexColumns].oArrInteractables[iCounterInteractables].bCanRead = true )
						{ 
							getline( fMap, oMatMap[iIndexRows][iIndexColumns].oArrInteractables[iCounterInteractables].sRead);
						}
						
						//Destroyable?
						getline( fMap, sBuffer);
						oMatMap[iIndexRows][iIndexColumns].oArrInteractables[iCounterInteractables].bCanDestroy = strtol( sBuffer.c_str(), NULL, 10);
						//Can you Open it?	
						getline( fMap, sBuffer);
						oMatMap[iIndexRows][iIndexColumns].oArrInteractables[iCounterInteractables].bCanOpen = strtol( sBuffer.c_str(), NULL, 10);
						//Can you close it?	
						getline( fMap, sBuffer);
						oMatMap[iIndexRows][iIndexColumns].oArrInteractables[iCounterInteractables].bCanClose = strtol( sBuffer.c_str(), NULL, 10);
						//Can you press it?
						getline( fMap, sBuffer);
						oMatMap[iIndexRows][iIndexColumns].oArrInteractables[iCounterInteractables].bCanPress = strtol( sBuffer.c_str(), NULL, 10);
						//Can you push it?
						getline( fMap, sBuffer);
						oMatMap[iIndexRows][iIndexColumns].oArrInteractables[iCounterInteractables].bCanPull = strtol( sBuffer.c_str(), NULL, 10);
						iCounterInteractables++;
					}
				}
				//End of Interactables stuff
			}
		}
	}
	else
	{
		cout << "Error opening map file" << endl;
	}
	fMap.close();

	/*
	//Debugging
	cout <<  oMatMap[0][0].sDescription << " <- Is the description" << endl; 
	if ( oMatMap[0][0].bEast == false)
	{ 
		cout << "Can't move east" << endl;
	}
	if (oMatMap[0][0].bEast == true)
	{ 
		cout << "Can move east" << endl;
	}
	*/
}

/* printInit
 * prints the first line of the story, WHICH WON'T BE REPEATED
 * Input: a string from a file
 * Output: NONE
 */
void printInit( )
{ 
	ifstream fDescription;
	fDescription.open( "game_info.txt");
	string sLaunch;
	if ( fDescription.is_open())
	{ 
		cout << "Game Launched" << endl;
		int iCounter = 0;
		while ( iCounter < 10) // Will print up to 10 lines
		{

			getline( fDescription, sLaunch); 
			cout <<  sLaunch << endl;;
			iCounter++;
		}
	}
	else
	{ 
		cout << "No game description found, skipping" << endl;
	}

}

/* printStatus
 * prints out all the current valid descriptions
 * Inputs: The player's information stored in a struct, the map;
 * Outputs: NONE
 */
void printStatus( oGamer oPlayer, oRoom oMatMap[50][50])
{ 
	//First print general room information
	cout << oMatMap[oPlayer.iLocation[0]][oPlayer.iLocation[1]].sDescription << endl;

	//Then print information on visible interactables
	if ( oMatMap[oPlayer.iLocation[0]][oPlayer.iLocation[1]].iHowManyInteractables > 0)
	{ 
		for ( int iCounter = 0; iCounter < oMatMap[oPlayer.iLocation[0]][oPlayer.iLocation[1]].iHowManyInteractables; iCounter++ )
		{ 
			if ( oMatMap[oPlayer.iLocation[0]][oPlayer.iLocation[1]].oArrInteractables[iCounter].bHidden = false)
			{ 
				cout << oMatMap[oPlayer.iLocation[0]][oPlayer.iLocation[1]].oArrInteractables[iCounter].sDescription << endl;
			}
		}
	}
	//Lastly print out Pickups information
	if ( oMatMap[oPlayer.iLocation[0]][oPlayer.iLocation[1]].iHowManyPickups > 0)
	{ 
		for ( int iCounter = 0; iCounter < oMatMap[oPlayer.iLocation[0]][oPlayer.iLocation[1]].iHowManyPickups; iCounter++ )
		{ 
			if ( oMatMap[oPlayer.iLocation[0]][oPlayer.iLocation[1]].oArrPickups[iCounter].bHidden = false)
			{ 
				cout << oMatMap[oPlayer.iLocation[0]][oPlayer.iLocation[1]].oArrPickups[iCounter].sDescription << endl;
			}
		}
	}
}

/* main
 * calls all other functions. Contains the game loop
 * Inputs: NONE
 * Outputs: VOID
 */
int main ()
{ 
	//Variables
	oRoom oMatMap[50][50];
	int iMapRows, iMapColumns;
	int iPlayerLocation[2] = {0, 0};

	
	getMap(oMatMap, iMapRows, iMapColumns); //Get the map from external file
	printInit();
	bGameRunning = 1;
	oGamer oPlayer;
	while ( bGameRunning == 1) // Game loop start
	{
		//Print current status
		printStatus(oPlayer, oMatMap);

		//Get and parse user input

	

	}
	

}
