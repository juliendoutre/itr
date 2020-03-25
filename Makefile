.PHONY: lib

all: clean build

clean:
	rm -rf build/*
	rm -rf bin/*
	rm -rf lib/*

build: lib td0 td1 td2 td3 td4

lib:
	g++ -I ./includes/ -o build/time.o -O3 -Wall -Wextra -c src/td1/a/time.cpp
	g++ -I ./includes/ -o build/Chrono.o -O3 -Wall -Wextra -c src/td3/a/Chrono.cpp
	g++ -I ./includes/ -o build/Timer.o -O3 -Wall -Wextra -c src/td3/b/Timer.cpp
	g++ -I ./includes/ -o build/PeriodicTimer.o -O3 -Wall -Wextra -c src/td3/b/PeriodicTimer.cpp
	g++ -I ./includes/ -o build/PosixThread.o -O3 -Wall -Wextra -c  src/td4/a/PosixThread.cpp
	g++ -I ./includes/ -o build/Thread.o -O3 -Wall -Wextra -c  src/td4/a/Thread.cpp
	g++ -I ./includes/ -o build/Mutex.o -O3 -Wall -Wextra -c src/td4/b/Mutex.cpp
	g++ -I ./includes/ -o build/Semaphore.o -O3 -Wall -Wextra -c src/td4/c/Semaphore.cpp
	ar rcs lib/itr.a build/time.o build/Chrono.o build/Timer.o build/PeriodicTimer.o build/PosixThread.o build/Thread.o build/Mutex.o

td0:
	gcc src/td0/a/main.c -o bin/td0_a -O3 -Wall -Wextra

td1: lib
	g++ src/td1/a/main.cpp lib/itr.a -I ./includes/ -o bin/td1_a -O3 -Wall -Wextra
	g++ src/td1/b/main.cpp -o bin/td1_b -lrt -O3 -Wall -Wextra
	g++ src/td1/c/main.cpp lib/itr.a -I ./includes/ -o bin/td1_c -O3 -Wall -Wextra
	g++ src/td1/d/main.cpp lib/itr.a -I ./includes/ -lrt -o bin/td1_d -O3 -Wall -Wextra
	g++ src/td1/e/main.cpp lib/itr.a -I ./includes/ -lrt -o bin/td1_e -O3 -Wall -Wextra

td2: lib
	g++ src/td2/a/main.cpp lib/itr.a -I ./includes/ -lrt -pthread -o bin/td2_a -O3 -Wall -Wextra
	g++ src/td2/b/main.cpp lib/itr.a -I ./includes/ -lrt -pthread -o bin/td2_b -O3 -Wall -Wextra
	g++ src/td2/c/main.cpp lib/itr.a -I ./includes/ -lrt -pthread -o bin/td2_c -O3 -Wall -Wextra

td3: lib
	g++ src/td3/a/main.cpp lib/itr.a -I ./includes/ -o bin/td3_a -O3 -Wall -Wextra
	g++ src/td3/b/main.cpp src/td3/b/CountDown.cpp lib/itr.a -I ./includes/ -lrt -pthread -o bin/td3_b -O3 -Wall -Wextra
	g++ src/td3/c/main.cpp src/td3/c/Looper.cpp src/td3/c/Calibrator.cpp src/td3/c/CpuLoop.cpp lib/itr.a -I ./includes/ -lrt -pthread -o bin/td3_c -O3 -Wall -Wextra

td4: lib
	g++ src/td4/a/main.cpp src/td4/a/Worker.cpp lib/itr.a -I ./includes/ -lrt -pthread -o bin/td4_a -O3 -Wall -Wextra
	g++ src/td4/b/main.cpp src/td4/b/Worker.cpp lib/itr.a -I ./includes/ -lrt -pthread -o bin/td4_b -O3 -Wall -Wextra
