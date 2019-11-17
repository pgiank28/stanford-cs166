CC = g++
CFLAGS = -c -Wall

binarySearchTrees.o: binarySearchTrees.cpp
	$(CC) $(CFLAGS) binarySearchTrees.cpp

binarySearchTreesTests.o: binarySearchTreesTests.cpp
	$(CC) $(CFLAGS) binarySearchTreesTests.cpp

all: binarySearchTrees.o binarySearchTreesTests.o
	$(CC) *.o -o all

clean:
	rm -rf *.o
