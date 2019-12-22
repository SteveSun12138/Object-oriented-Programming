#Guoqin Sun
#914785301

CC = g++

CFLAG = -c -Wall

all: makeSVG

makeSVG: makeSVG.o
	$(CC) makeSVG.o -o makeSVG

makeSVG.o: makeSVG.cpp
	$(CC) $(CFLAG) makeSVG.cpp

clean:
	rm -rf *.o makeSVG
