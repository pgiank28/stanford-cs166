CC = g++
CFLAGS = -c -Wall

skyline.o: skyline.cpp
	$(CC) $(CFLAGS) skyline.cpp

skylineTests.o: skylineTests.cpp
	$(CC) $(CFLAGS) skylineTests.cpp

all: skyline.o skylineTests.o
	$(CC) *.o -o all

clean:
	rm -rf *.o all
