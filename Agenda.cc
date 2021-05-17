#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "Date.h"
#include "Calendar.h"
#include "Agenda.h"
#define MAX_SIZE 30

//Constructor
Agenda::Agenda(string agName)
{
  //cout<<"in default constructor"<<endl;
  agendaName = agName;
  agCounter = 0;
}
//Destructor
Agenda::~Agenda()
{
	
	for(int i = 0; i < agCounter; i++)
	{
		delete calArr[i];
	}
}
//To add a calendar to the array
bool Agenda::add(Calendar* c)
{
 	//if all goes well,calendar is added
	if(agCounter >= 0)
	{
		calArr[agCounter] = c;
		agCounter++;
		return true;
	}else
	{
		return false;
	}		

}
//To find calendar array through the help of string
bool Agenda::find(string n, Calendar** c)
{
	for(int x = 0; x < agCounter; x++)
	{
		//if the name at the index matches n, store calendar pointer.
		if(calArr[x]->getCalName() == n)
		{
			*c = calArr[x];
			return true;
		}
	}
	cout << "Calender Not Found " << endl;
	return false;



}
//To add a date inside a calendar "n"
bool Agenda::add(Date* d, string n)
{
	Calendar* x; 
	bool finder = find(n, &x);
	if(finder == true)
	{	
		x->add(d);
		return true;
	}
	else if(finder == false)
	{
		delete d;
		return false;
	}	
	return false;
	

}
//To print the calendars in one go
void Agenda::print()
{
	cout<< "AGENDA NAME : " << agendaName << endl;
	Calendar tempo("Agenda");
	for (int i = 0; i < agCounter; i++)
	{
		tempo.merge(calArr[i]);
		
	}
	tempo.printDates();
}






















