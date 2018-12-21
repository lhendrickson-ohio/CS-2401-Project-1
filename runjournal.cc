/*********************************************************
	Implementation file for functions
	for the Runjournal class

	Liam Hendrickson, CS2401 - John Dolan
	Ohio University - Athens, Ohio
*********************************************************/


#include "runjournal.h"
#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;


//Constructor
Runjournal :: Runjournal()
{
	Runtime x;
	for( int i=0; i<=CAPACITY; i++)
		journal[i] = x;
}

//Add a new run
void  Runjournal::add( Runtime& r)
{
	Runtime base;



	for(int i=0; i<CAPACITY; i++) //searches for the first element not equivelent to the default constructor of class Runtime
	{
		if(journal[i] == base)
		{
			journal[i] = r;  //sets the first default element found to the entered value
			break; //exits the for loop
		}
	}
}

//Displays all runs
void Runjournal::display()const
{
	Runtime base;

	for(int i=0; i<CAPACITY; i++) //searches the entire array and displays all elements not equal to a default case
        {
                if(journal[i] != base)
			cout<<journal[i]<<endl;
	}
}

//Searches for a specific time  and offers option to delete it
void Runjournal::time_search(const Runtime& r)
{

	char answer = 'n';//lets the user decide to delete an entry
	Runtime base;

	for(int i=0; i<CAPACITY; i++) //searches for the first element equivilient to the one entered
        {
                if(journal[i] == r)
                {
			cout<<"Would you like to delete the entry:  "<< journal[i]<<"? y/n  ";
			cin >> answer;
			if (answer == 'y')
			{
				journal[i] = base;  //sets the entry equal to a default case
				break;
			}

			else
				break;

                }
        }
}

//Searches the array for all runs of a certain distance
void Runjournal::distance_search (const double dist)const
{
	for(int i=0; i<CAPACITY; i++)
	{
		if(journal[i].get_distance() == dist)
			cout<<journal[i]<<endl;
	}
}


//Sorts the array from highest to lowest time and displays is
void Runjournal::time_sort()
{
	Runtime tmp;

	for(int i=0; i<CAPACITY; i++) //the starting point for a search increases after the greates value left is found
	{
		for(int j=i+1; j<CAPACITY; j++) //searches for the gretest value from elements beyond the starting point
		{
			if( journal[i].get_time() < journal[j].get_time() )//if a greater value is found, they are switched
			{
				tmp = journal[i];
				journal[i] = journal[j];
				journal[j] = tmp;
			}
		}
	}
}


//Sorts the array from highest to lowest distance and displays is
void Runjournal::distance_sort()
{
        Runtime tmp;

        for(int i=0; i<CAPACITY; i++) //the starting point for a search increases after the greates value left is found
        {
                for(int j=i+1; j<CAPACITY; j++) //searches for the gretest value from elements beyond the starting point
                {
                        if( journal[i].get_distance() < journal[j].get_distance() )//if a greater value is found, they are switched
                        {
                                tmp = journal[i];
                                journal[i] = journal[j];
                                journal[j] = tmp;
                        }
                }
        }
}

//Reports the total time ran
void Runjournal::total_time()const
{
	MyTime t;
	for(int i=0; i<CAPACITY; i++)
	{
		t = t + journal[i].get_time();
	}
	cout<<"Total time ran is:  "<< t <<endl;
}

//Reports the total distance ran
void Runjournal::total_distance()const
{
        double d=0;
        for(int i=0; i<CAPACITY; i++)
        {
                d += journal[i].get_distance();
        }
        cout<<"Total distance ran is:  "<< d <<" miles"<<endl;
}

//Calculates and reports the average pace of all runs
void Runjournal::average_pace()const
{
	int count=0;
	MyTime sum;
	Runtime base;

	for(int i=0; i<CAPACITY; i++)  //adds the average pace of each non-base run to a sum and keeps count of how many averages are represented
	{
		if( journal[i] !=base) //only includes the run if it is not identical to the base case
		{
			count += 1;
			sum = sum + journal[i].pace();
		}
	}

	cout<<"Your average pace is  "<<(sum/count)<<"  per mile"<< endl;
}


//Saves the array to an output file
void Runjournal::save(ofstream& ofs)const
{
	Runtime base;

	for(int i=0; i<CAPACITY; i++)
	{
		if(journal[i] != base)
			ofs<<journal[i]<<endl;
	}

}

//Loads the values of the file onto the array of the new session
void Runjournal::load(Runtime& tmp)
{
	Runtime base;

	for(int i=0; i<CAPACITY; i++)
	{
		if(journal[i] == base)
			journal[i] = tmp;
	}
}
