#Guoqin Sun
#914785301
CC = g++

CFLAG = -c -Wall

all: useFraction calculator

useFraction: useFraction.o Fraction.o
	$(CC) useFraction.o Fraction.o -o usefraction

useFraction.o: useFraction.cpp
	$(CC) $(CFLAG) useFraction.cpp

Fraction.o: Fraction.cpp
	$(CC) $(CFLAG) Fraction.cpp

calculator: calculator.o Fraction.o
	$(CC) calculator.o Fraction.o -o calculator

calculator.o: calculator.cpp
	$(CC) $(CFLAG) calculator.cpp

Fraction.o: Fraction.cpp
	$(CC) $(CFLAG) Fraction.cpp

clean:
	rm -rf *o useFraction calculator

