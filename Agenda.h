#ifndef CALENDER_H
#define CALENDER_H
#define MAX_SIZE 30
/*
The main function of this class is, to take a set of calendars and store the pointers of those calendars in a static array. It has 2 adds; 1) first add just takes a pointer to calendar and then it adds that calendar in its array. 2) the second add takes a pointer to date and along with the calendar name in which it is to be added, it uses the find function to check if that calendar is in the array or not, if it's not present than it returns false. The print function uses the merge function to join calendars inside the array and then prints through the calendars print function.
*/
/*

Agenda(String) it is constructor, makes an Agenda object. Initialzing all the values
Parameter: String
Return: NONE (NOT VOID since constructor)

~Agenda() it is the destructor, for freeing up memory.
Parameter: NONE
Return: NONE (NOT VOID since destructor).

add(Date*, string) it takes in a pointer to a date object, and the name of a calendar. it uses the find() member function. To find the exact calendar. 
Parameter: Date*, string
Return: boolean

add(Calendar*) it takes in a pointer to a calendar object, and then adds this calendar pointer to its static array of calendar objects.
Parameter: Calendar*
Return: boolean

print() it basically prints the calendars inside it after merging them.
Parameter: NONE
Return: VOID
*/
class Agenda
{
  public:

    Agenda(string);
    ~Agenda();
    
    bool add(Date*, string);
    bool add(Calendar*);
    void print();
    bool find(string, Calendar**);
    
    

  private:
    string agendaName; 
    Calendar* calArr[MAX_SIZE]; // static array of pointer to calendar objects
    int agCounter; //keeps count of pointers in array
    
    
   
};

#endif
