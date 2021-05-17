#ifndef CALENDAR_H
#define CALENDAR_H
/*
This is the Calendar class. It stores a series of date in a particular calendar array through the help of a dynamic array of dates object pointers. It keeps a count of the pointers stored in the array. It uses add() to add dates in the array making use of getValid() and lessThan(). After adding has 2 print() functions, 1 is to print dates, other uses the print dates. The merge() function is used by the agenda class to merge all the calendars in the agenda class. 
*/

class Calendar
{
  public:

    Calendar(string);
    ~Calendar();
    bool add(Date*);
    string getCalName();
    void printDates();
    void print();
    void merge(Calendar* c);
    

  private:
    string name; //calendar name
    Date** dateArr;
    int counter; //keeps track of pointers
   
};

#endif
