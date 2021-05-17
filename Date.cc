#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "Date.h"

//Constructor
Date::Date(string name, int d, int m, int y, int startHour, int startMin, int dur, bool recur, int numRecur)
{
	//cout<<"in DATE default constructor"<<endl;
	eventName = name;
	recurEvent = recur;

	if(recurEvent == true)
	{
		numWeeksRecur = numRecur;
	}else
	{
		recur = 0;
	} 

	valid = validate(d, m, y, startHour, startMin, dur);
	//cout << valid << endl;
	setDate(d, m, y);
	if(valid == true){
		setDate(d, m, y);
		startTime = (startHour * 60) + startMin;
		duration = dur;
		endTime = startTime + duration;
	}
	else
	{
		startTime = 0;
		endTime = 0;
	}
}

//Destructor
Date::Date(Date& oldDate)
{
  //cout << "IN COPPY CTOR" << endl;
  eventName = oldDate.eventName;
  day = oldDate.day;
  month = oldDate.month;
  year = oldDate.year;
  valid = oldDate.valid;
  startTime = oldDate.startTime;
  endTime = oldDate.endTime;
  duration = oldDate.duration;
  recurEvent = oldDate.recurEvent;
  numWeeksRecur = oldDate.numWeeksRecur;
}

//its purpose is to verify all the parameters sent in by the user, if its wrong valid flag is set to false.
bool Date::validate(int d, int m, int y, int startingHour, int startingMin, int dur)
{
	valid = true;
	( ( y > 0) ? y : valid = false);
	( ( m > 0 && m <=12) ? m: valid = false);
	( ( d > 0 && d <=31) ? d : valid = false);
	( (startingHour >=0 && startingHour < 24) ? startingHour : valid = false);
	( (startingMin >=0 && startingMin < 60) ? startingMin : valid = false);
	( (dur >= 0) ? dur: valid = false);
	return valid;
}

//sets the variable for year, month and day.
void Date::setDate(int d,int m,int y)
{
  year  = ( ( y > 0) ? y :0);
  month = ( ( m > 0 && m <=12) ? m : 0 );
  day   = ( ( d > 0 && d <=31) ? d : 0 );
}

//its purpose is to compare 2 dates, this date with the one in the parameter. It compares the years first, then months, then day and lastly time. The exact moment it gets 2 different results it stops.
bool Date::lessThan(Date* d)
{
  if(year < d->year)
  {
	return true;
  }else if(year  > d->year)
  {
  	return false;
  }else if(year == d->year)
  {
  	if(month < d->month)
  	{
  		return true;
  	}else if(month > d->month)
  	{
    		return false;
    	}else if(month == d->month){
  		if(day < d->day)
  		{
  			return true;
  		}else if(day > d->day)
  		{
  			return false;
  		}else if(day == d->day)
  		{
  			if(startTime < d->startTime)
  			{
				return true;
			}else if(startTime > d->startTime)
			{
				return false;
			}
  		}		
  	}
  }
  return true;				
  			
}

//getter function for recurEvent data member
bool Date::getRecur()
{
	return recurEvent;
}
//getter function for valid data member
bool Date::getValid()
{
	return valid;
}
//purpose is to print the event date with a neat and descriptive manner
void Date::print()
{
	//prints all data members except duration instead..
	//must compute end time from start time and duration.
	int min = startTime % 60;
	int hour = (startTime - min) / 60;
	int endMin = endTime % 60;
	int endHour = (endTime -endMin) / 60;
	

	cout<< setfill(' ') << setw(35) <<eventName <<":" <<  setw(10) <<getMonthStr() << " " << setw(2) <<day << ", " <<year << " @ " <<setfill('0')<<setw(2) << hour << ":" <<setfill('0')<<setw(2) << min << " - " <<setfill('0')<<setw(2) << endHour << ":"<<setfill('0')<<setw(2) << endMin;
	if(recurEvent == true)
	{
		cout << ", recurs for " << numWeeksRecur << " weeks";
	}	

}


//purpose is to verify the days in a month
int Date::lastDayInMonth()
{
  switch(month)
  {
    case 2:
      if (leapYear())
        return 29;
      else
        return 28;
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
      return 31;
    default:
      return 30;
  }
}

bool Date::leapYear()
{
  if ( year%400 == 0 ||
       (year%4 == 0 && year%100 != 0) )
    return true;
  else
    return false;
}
//its purpose is to get the months name
string Date::getMonthStr()
{
  string monthStrings[] = { 
    "January", "February", "March", "April", "May", "June",
    "July", "August", "September", "October", "November", "December" };

  if ( month >= 1 && month <= 12 )
    return monthStrings[month-1];
  else
    return "Unknown";
}

