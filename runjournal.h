/*******************************************************************************
		Declaration of the Runjournal class, which has functions
		to engage with an array with elements of the class Runtime.

		Liam Hendrickson, CS2401 - John Dolan, Ohio University

******************************************************************************/

#include "runtime.h"
#include "mytime.h"
#include <iostream>
#include <cstdlib>
#include <fstream>
#ifndef RUNJOURNAL_H
#define RUNJOURNAL_H

class Runjournal{


	public:
		//Constructor
		Runjournal();

		//Adds a new run
		void add ( Runtime& r);

		//Displays the entire array that contains data
		void display ()const;

		//Searches the array for a particular time, displays 1st result's data, and offers to remove it
		void time_search (const Runtime& r);


		//Search and display  all runs of a certain distance
		void distance_search (const double dist)const;

		//Sorts the journal by time
		void time_sort ();

		//Sorts the journal by distance
		void distance_sort ();

		//Reports total time amongst all runs
		void total_time ()const;

		//Reports total distance amongst all runs
		void total_distance ()const;

		//Reports the average pace for all runs
		void average_pace()const;

		//Saves the information to the runlog.txt
		void save(std::ofstream& ofs)const;

		//Loads the data from the file onto the array of the new session
		void load(Runtime& tmp);


	private:

		static const int CAPACITY = 200; //The size of the array for runjournal to hold

		Runtime journal[CAPACITY];


};




#endif
