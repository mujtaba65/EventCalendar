agenda:	main.o Date.o Calendar.o Agenda.o 
	g++ -o agenda main.o Date.o Calendar.o Agenda.o

main.o:	main.cc Date.h Calendar.h Agenda.h 
	g++ -c main.cc

Date.o:	Date.cc Date.h
	g++ -c Date.cc
	
Calendar.o:	Calendar.cc Calendar.h
	g++ -c Calendar.cc
	
Agenda.o:	Agenda.cc Agenda.h
	g++ -c Agenda.cc	

clean:
	rm -f *.o agenda
