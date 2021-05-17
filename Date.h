#ifndef DATE_H
#define DATE_H

/*
This is the Date class, it takes in a event date from the user and then checks if it is valid or not. The event date's name and recurrence is set at first. If it's valid all the corresponding data members are then initialized accordingly. After that it has a lessThan() member function which compares this date with a given date. The print() prints details about the event.
*/

class Date
{
  public:
    Date(string = " " , int = 0, int = 0, int = 2000, int = 0, int = 0, int = 0, bool = false, int = 10);
    //add a copy constructor.
    Date(Date&);
    
    void setDate(int,int,int);
    void print();
    bool getRecur();
    bool getValid();
    bool lessThan(Date* d);

  private:
    string eventName; 
    int startTime; //starting time of event
    int duration; 
    bool recurEvent; 
    int numWeeksRecur;
    bool valid; 
    int endTime;
    int day;
    int month;
    int year;
    int  lastDayInMonth();
    bool leapYear();
    string getMonthStr();
    bool validate(int, int, int, int, int, int);

};

#endif
