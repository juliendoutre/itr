all: clean build

clean:
	rm -rf build/*

build: fifo timer build_lib

fifo:
	gcc src/fifo/main.c -o bin/fifo -O3 -Wall

timer:
	g++ src/timer/main.cpp -o bin/timer -O3 -Wall -lrt

build_lib:
	g++ -c -o build/itr.o src/time.cpp -I .
	ar rcs lib/itr.a build/itr.o

tests: test_time

test_time: build_lib
	g++ -o bin/test_time tests/time.cpp lib/itr.a -I .
