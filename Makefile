all: clean fifo timer

clean:
	rm -rf bin/*

fifo:
	gcc src/fifo/main.c -o bin/fifo -O3 -Wall

timer:
	g++ src/timer/main.cpp -o bin/timer -O3 -Wall -lrt
