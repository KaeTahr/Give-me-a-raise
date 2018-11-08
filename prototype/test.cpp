#include <iostream>
#include <fstream>
#include <string>
#include "structs.h"
using namespace std;

void getMap( oRoom oMatMap[50][50], int &iMapRows, int &iMapColumns)
{ 
	ifstream fMap;
	fMap.open( "Test.map");
	string sBuffer;//Needed to use this because reading from a file doesn't play nice when mixing strings and other datatypes
	string sTest; //DELETE
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
				bPickups = strtol( sBuffer.c_str(), NULL, 10);
				
				if ( bPickups == true)
				{ 
					int iHowManyPickups;
					getline( fMap, sBuffer );
					iHowManyPickups = strtol( sBuffer.c_str(), NULL, 10);

					//Get Info on items, if there are items
					int iCounterPickups = 0;
					while ( iCounterPickups < iHowManyPickups)
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

				bool bInteractables;
				//Are there any interactables?
				getline( fMap, sBuffer );
				bInteractables = strtol( sBuffer.c_str(), NULL, 10);
				
				if ( bInteractables == true)
				{ 
					int iHowManyInteractables;
					getline( fMap, sBuffer );
					iHowManyInteractables = strtol( sBuffer.c_str(), NULL, 10);

					//Get Info on items, if there are items
					int iCounterInteractables = 0;
					while ( iCounterInteractables < iHowManyInteractables)
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

int main ()
{ 
	//Variables
	oRoom oMatMap[50][50];
	int iMapRows, iMapColumns;

	
	getMap(oMatMap, iMapRows, iMapColumns); //Get the map from external file

	/*while ( bGameRunning == 1) // Game loop start
	{ 

	

	}
	*/

}
