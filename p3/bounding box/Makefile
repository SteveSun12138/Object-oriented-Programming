#Guoqin Sun
#914785301

CC = g++

CFLAG = -c -Wall

all: checkpack

checkpack: checkpack.o Domain.o Point.o Shape.o
	$(CC) checkpack.o Domain.o Point.o Shape.o -o checkpack

checkpack.o: checkpack.cpp
	$(CC) $(CFLAG) checkpack.cpp

Domain.o: Domain.cpp
	$(CC) $(CFLAG) Domain.cpp

Point.o: Point.cpp
	$(CC) $(CFLAG) Point.cpp

Shape.o: Shape.cpp
	$(CC) $(CFLAG) Shape.cpp

clean:
	rm -rf *o checkpack
