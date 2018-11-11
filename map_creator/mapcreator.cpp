#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void createMap()
{ 
	ofstream fMap;
	cout << "Opening/ Creating Test.map file" << endl;
	fMap.open( "Test.map");
	string sBuffer;//Needed to use this because reading from a file doesn't play nice when mixing strings and other datatypes
	if ( fMap.is_open())
	{ 
		//Get Map Dimensions	
		cout << "What are the X-dimensions of your map" << endl;
		getline( cin, sBuffer);
		fMap << sBuffer << endl;
		int iRows = strtol( sBuffer.c_str(), NULL, 10);

		cout << "What are the Y-dimensions of your map" << endl;
		getline( cin, sBuffer);
		fMap << sBuffer << endl;
		int iColumns =  strtol( sBuffer.c_str(), NULL, 10);

		//Get Map Information
		for ( int iIndexRows = 0; iIndexRows < iRows; iIndexRows++)
		{ 
			for (int iIndexColumns = 0; iIndexColumns < iColumns; iIndexColumns++)
			{ 
				cout << "What is the name of room " << iIndexRows << "," << iIndexColumns << endl;
				getline (cin, sBuffer);
				fMap << sBuffer << endl;

				cout << "What is the Description of room " << iIndexRows << "," << iIndexColumns << endl;
				
				getline (cin, sBuffer);
				fMap << sBuffer << endl;

				//Where can you go?
				cout << "Can you go North initially at room (Enter 0 or 1) " << iIndexRows << "," << iIndexColumns << endl;
				getline( cin, sBuffer);
				fMap << sBuffer << endl;

				cout << "Can you go South initially at room " << iIndexRows << "," << iIndexColumns << endl;
				getline( cin, sBuffer);
				fMap << sBuffer << endl;

				cout << "Can you go East initially at room " << iIndexRows << "," << iIndexColumns << endl;
				getline( cin, sBuffer);
				fMap << sBuffer << endl;

				cout << "Can you go West initially at room " << iIndexRows << "," << iIndexColumns << endl;
				getline( cin, sBuffer);
				fMap << sBuffer << endl;
				
				//Pickups
				//Are there any pickups?
				cout << "How many pickups are there in room " << iIndexRows << "," << iIndexColumns << endl;
				getline( cin, sBuffer );
				fMap << sBuffer << endl;
				int iPickups = strtol( sBuffer.c_str(), NULL, 10);

				
				if ( iPickups > 0)
				{ 

					//Get Info on items, if there are items
					int iCounterPickups = 0;
					while ( iCounterPickups < iPickups)
					{ 
						//Get Name
						cout << "What is the name of item " << iCounterPickups << " at room " << iIndexRows << "," << iIndexColumns << endl;
						getline (cin, sBuffer);
						fMap << sBuffer << endl;

						//Get Description
						cout << "What is the description of item " << iCounterPickups << " at room " << iIndexRows << "," << iIndexColumns << endl;
						getline (cin, sBuffer);
						fMap << sBuffer << endl;

						//Hidden?
						cout << "Is the following item hidden? 0 or 1): " << iCounterPickups << " at room " << iIndexRows << "," << iIndexColumns << endl;
						getline (cin, sBuffer);
						fMap << sBuffer << endl;

						iCounterPickups++;

					}
				}
				//End of Pickups stuff

				//Interactables
				//Are there any interactables? 
				cout << "How many interactables are there in room " << iIndexRows << "," << iIndexColumns << endl;
				getline( cin, sBuffer );
				fMap << sBuffer << endl;
				int iInteractables = strtol( sBuffer.c_str(), NULL, 10);
				
				if ( iInteractables > 0)
				{ 

					//Get Info on Interactables
					int iCounterInteractables = 0;
					while ( iCounterInteractables < iInteractables)
					{ 
						//Get Name
						cout << "What is the name of the interactable? " << iCounterInteractables << " at room " << iIndexRows << "," << iIndexColumns << endl;
						getline (cin, sBuffer);
						fMap << sBuffer << endl;

						//Get Description
						cout << "What is the description of the interactable " << iCounterInteractables << " at room " << iIndexRows << "," << iIndexColumns << endl;
						getline (cin, sBuffer);
						fMap << sBuffer << endl;

						//Hidden?
						cout << "Is the following item hidden? (0 or 1): " << iCounterInteractables << " at room " << iIndexRows << "," << iIndexColumns << endl;
						getline (cin, sBuffer);
						fMap << sBuffer << endl;

						//Readable
						cout << "Is the following item readable? (0 or 1): " << iCounterInteractables << " at room " << iIndexRows << "," << iIndexColumns << endl;
						getline (cin, sBuffer);
						fMap << sBuffer << endl;
						bool bReadable;
						bReadable = strtol( sBuffer.c_str(), NULL, 10);

						if ( bReadable == true )
						{ 
							cout << "What does this interactable read?" << endl;
							getline (cin, sBuffer);
							fMap << sBuffer << endl;
						}
						
						//Destroyable?
						cout << "Is this interactable destroyable?" << iCounterInteractables << " at room " << iIndexRows << "," << iIndexColumns << endl;
						getline (cin, sBuffer);
						fMap << sBuffer << endl;

						//Can you Open it?	
						cout << "Can you open this interactable? (if it's a door, is it closed?)" << iCounterInteractables << " at room " << iIndexRows << "," << iIndexColumns << endl;
						getline (cin, sBuffer);
						fMap << sBuffer << endl;
						
						//Can you close it?	
						cout << "Can you close this interactable? ( if it's a door, is it open?)" << iCounterInteractables << " at room " << iIndexRows << "," << iIndexColumns << endl;
						getline (cin, sBuffer);
						fMap << sBuffer << endl;

						//Can you press it?
						cout << "Can you press this interactable?" << iCounterInteractables << " at room " << iIndexRows << "," << iIndexColumns << endl;
						getline (cin, sBuffer);
						fMap << sBuffer << endl;

						//Can you push it?
						cout << "Can you push this interactable?" << iCounterInteractables << " at room " << iIndexRows << "," << iIndexColumns << endl;
						getline (cin, sBuffer);
						fMap << sBuffer << endl;

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
	createMap();

	return 0;
}
