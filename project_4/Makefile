all :MAIN

MAIN :main.o bst.o
	g++ -Wall -o MAIN main.o bst.o

main.o 	:main.cpp bst.h
	g++ -Wall -c main.cpp

bst.o	:bst.cpp bst.h
	g++ -Wall -c bst.cpp

clean 	:
	rm *.o MAIN