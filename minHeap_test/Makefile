all	:minHeapTest

minHeapTest	:main.o min_heap.o
	 g++ -Wall -o minHeapTest main.o min_heap.o

main.o	:main.cpp min_heap.h
	 g++ -Wall -c main.cpp

min_heap.o	:min_heap.cpp min_heap.h
	g++ -Wall -c min_heap.cpp

clean	:
	rm *.o minHeapTest
