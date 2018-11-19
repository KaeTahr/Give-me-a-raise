#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
using namespace std;

void createMap()
{ 
	ofstream fMap;
	string sBuffer;//Needed to use this because reading from a file doesn't play nice when mixing strings and other datatypes
	cout << "How would you like to call your map file?" << endl;
	getline( cin, sBuffer);
	cout << "Opening/ Creating map file" << endl;
	fMap.open( sBuffer.c_str());
	if ( fMap.is_open())
	{ 
		//Get Map Dimensions	
		cout << "How many floors does you map have?" << endl;
		getline( cin, sBuffer);
		fMap << sBuffer << endl;
		int iFloors = strtol( sBuffer.c_str(), NULL, 10);

		cout << "What are the X-dimensions of your map" << endl;
		getline( cin, sBuffer);
		fMap << sBuffer << endl;
		int iRows = strtol( sBuffer.c_str(), NULL, 10);

		cout << "What are the Y-dimensions of your map" << endl;
		getline( cin, sBuffer);
		fMap << sBuffer << endl;
		int iColumns =  strtol( sBuffer.c_str(), NULL, 10);
		

		//Get Map Information
		for ( int iIndexFloors = 0; iIndexFloors < iFloors; iIndexFloors++)
		{ 
	
			for ( int iIndexColumns = 0; iIndexColumns < iColumns; iIndexColumns++)
			{ 
				for (int iIndexRows = 0; iIndexRows < iRows; iIndexRows++)
				{ 
					cout << "What is the name of room " << iIndexRows << "," << iIndexColumns << " Floor " << iIndexFloors << endl;
					getline (cin, sBuffer);
					fMap << sBuffer << endl;

					cout << "What is the Description of room " << iIndexRows << "," << iIndexColumns << " Floor " << iIndexFloors << endl;
				
					getline (cin, sBuffer);
					fMap << sBuffer << endl;

					//Where can you go?
					cout << "Can you go North initially at room (Enter 0 or 1) " << iIndexRows << "," << iIndexColumns << " Floor " << iIndexFloors << endl;
					getline( cin, sBuffer);
					fMap << sBuffer << endl;

					cout << "Can you go South initially at room " << iIndexRows << "," << iIndexColumns << " Floor " << iIndexFloors << endl;
					getline( cin, sBuffer);
					fMap << sBuffer << endl;

					cout << "Can you go East initially at room " << iIndexRows << "," << iIndexColumns <<  " Floor " << iIndexFloors << endl;
					getline( cin, sBuffer);
					fMap << sBuffer << endl;

					cout << "Can you go West initially at room " << iIndexRows << "," << iIndexColumns << endl;
					getline( cin, sBuffer);
					fMap << sBuffer << endl;
				
				//Stairs
					cout << "Are there any stairs? (just 0 or 1)" << endl;
					getline( cin, sBuffer );
					fMap << sBuffer << endl;
					bool bStairs = strtol( sBuffer.c_str(), NULL, 10);
					
					if ( bStairs == true)
					{
						cout << "Can you go up from these stairs" << endl;
						getline( cin, sBuffer );
						fMap << sBuffer << endl;
						
						cout << "Can you go down from these stairs?" << endl;
						getline( cin, sBuffer );
						fMap << sBuffer << endl;
					}
				//End of stairs
				
				//Pickups
				//Are there any pickups?
					cout << "How many pickups are there in room " << iIndexRows << "," << iIndexColumns <<  " Floor " << iIndexFloors << endl;
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
							cout << "What is the name of item " << iCounterPickups << " at room " << iIndexRows << "," << iIndexColumns << " Floor " << iIndexFloors << endl;
							getline (cin, sBuffer);
							fMap << sBuffer << endl;

							//Get Description
							cout << "What is the description of item " << iCounterPickups << " at room " << iIndexRows << "," << iIndexColumns << " Floor " << iIndexFloors << endl;
							getline (cin, sBuffer);
							fMap << sBuffer << endl;
							//Hidden?
							cout << "Is it hidden? " << endl;
							getline (cin, sBuffer);
							fMap << sBuffer << endl;

							iCounterPickups++;
						}
					}
					//End of Pickups stuff

					//Interactables
					//Are there any interactables? 
					cout << "How many interactables are there in room " << iIndexRows << "," << iIndexColumns << " Floor " << iIndexFloors <<  endl;
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
							cout << "What is the name of the interactable? " << iCounterInteractables << " at room " << iIndexRows << "," << iIndexColumns << " Floor " << iIndexFloors <<  endl;
							getline (cin, sBuffer);
							fMap << sBuffer << endl;

							//Examinable
							cout << "Is the following item examinable? (0 or 1): " << iCounterInteractables << " at room " << iIndexRows << "," << iIndexColumns << " Floor " << iIndexFloors <<  endl;
							getline (cin, sBuffer);
							fMap << sBuffer << endl;
							
							bool bExaminable;
							bExaminable = strtol( sBuffer.c_str(), NULL, 10);

							if ( bExaminable == true )
							{ 
								cout << "What does this interactable examines?" << endl;
								getline (cin, sBuffer);
								fMap << sBuffer << endl;
							}
						
							//Activable/Available for actions
							cout << "Is this interactable activable?" << iCounterInteractables << " at room " << iIndexRows << "," << iIndexColumns << " Floor " << iIndexFloors <<  endl;
							getline (cin, sBuffer);
							fMap << sBuffer << endl;
							
							bool bActivable;
							bActivable= strtol( sBuffer.c_str(), NULL, 10);

							if ( bActivable == true )
							{ 
								cout << "What does this interactable actives? (text of what it says if activated)" << endl;
								getline (cin, sBuffer);
								fMap << sBuffer << endl;
							}

							iCounterInteractables++;
						}
					}
					//End of Interactables stuff
					
					//First visit
					cout << "Does something happen on the first visit?(0 or 1)" << endl;
					getline( cin, sBuffer );
					fMap << sBuffer << endl;
					int iHowManyVisits = strtol( sBuffer.c_str(), NULL, 10);
					
					if ( iHowManyVisits > 0 )
					{
					int iCounterVisits = 0;
					while ( iCounterVisits < iHowManyVisits )
						{
						cout << "What does it say on the first visit?" << endl;
						getline (cin, sBuffer);
						fMap << sBuffer << endl;
						iCounterVisits++;
						}
					}
				}
			}
		}
	}
		else
		{
			cout << "Error opening map file" << endl;
		}
		fMap.close();
}

int main ()
{ 
	createMap();

	return 0;
}
