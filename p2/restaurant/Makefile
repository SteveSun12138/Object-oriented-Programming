#Guoqin Sun
#914785301

CC = g++

CFLAG = -c -Wall

all: assigntables

assigntables: assigntables.o Restaurant.o Table.o
	$(CC) assigntables.o Restaurant.o Table.o -o assigntables

assigntables.o: assigntables.cpp
	$(CC) $(CFLAG) assigntables.cpp

Restaurant.o: Restaurant.cpp
	$(CC) $(CFLAG) Restaurant.cpp

Table.o: Table.cpp
	$(CC) $(CFLAG) Table.cpp

clean:
	rm -rf *o assigntables
