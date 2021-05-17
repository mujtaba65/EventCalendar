#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "Date.h"
#include "Calendar.h"
#define MAX_SIZE 30

//Constructor
Calendar::Calendar(string calName)
{
  //cout<<"in default constructor"<<endl;
  name = calName;
  dateArr = new Date*[MAX_SIZE]();
  counter = 0;
}

//Destructor
Calendar::~Calendar()
{
	
	for(int i = 0; i < MAX_SIZE; i++)
	{
		//cout<<"in default DEstructor"<<endl;
		delete dateArr[i];
	} 
	delete [] dateArr;

}

//getter function to get name
string Calendar::getCalName()
{
	return name;
}
//its purpose is to check validity, if its valid then go through the dateArr and compare with each pointer date object. After comparison it must make space accordingly to fit the ascending order criteria. If it is to be added at end, it'll exit the nested for loop and add at end. After each addition it increments counter.
bool Calendar::add(Date* d)
{
	//cout <<"LOL"<< endl;
	if(d->getValid())
	{
		if(counter == 0)
		{
			dateArr[0] = d;
			counter++;
			return true;
		}	
		
		for(int i = 0; i < counter; i++)
		{
			if (d->lessThan(dateArr[i]) == true)
			{	
				
				for(int x = counter; x > i; x--)
				{
					dateArr[x] = dateArr[x-1];
				}
				counter++;
				dateArr[i] = d;
				return true;
			
			}	
			
		}
		dateArr[counter] = d;
		counter++;
		return true;
		
	}else
	{
		cout <<"Invalid Date" <<endl;
		delete d;
		return false;
	}
	//return true;	

}

//its purpose it to iterate over the date pointers in a calendar array, and then store them in a temp var, and then add them in 1 temporary array with all the events.
void Calendar::merge(Calendar* c)
{

	for (int x = 0; x < c->counter; x++)
	{
		Date* d =new Date(*(c->dateArr[x]));
		add(d);
	}	
}



//prints all the dates
void Calendar::printDates()
{
	for(int i = 0; i < counter; i++)
	{
		cout << "==" ;
		dateArr[i]->print();
		cout<< endl; 
	}
}

//prints calendar name, and then calls printDates.
void Calendar::print()
{
	cout<<"Calendar: "<< name <<endl;
	printDates();
  

}


