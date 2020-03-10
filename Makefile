all: clean build tests

clean:
	rm -rf build/*
	rm -rf bin/*

build: build_lib build_td_0 build_td_1 build_td_2 build_td_3

build_lib:
	g++ -I . -o build/time.o -O3 -Wall -Wextra -c src/td1/a/time.cpp
	g++ -I . -o build/chrono.o -O3 -Wall -Wextra -c src/td3/a/Chrono.cpp
	g++ -I . -o build/timer.o -O3 -Wall -Wextra -c src/td3/b/Timer.cpp
	g++ -I . -o build/periodicTimer.o -O3 -Wall -Wextra -c src/td3/b/PeriodicTimer.cpp
	g++ -I . -o build/posixThread.o -O3 -Wall -Wextra -c  src/td4/a/PosixThread.cpp
	g++ -I . -o build/thread.o -O3 -Wall -Wextra -c  src/td4/a/Thread.cpp
	ar rcs lib/itr.a build/time.o build/chrono.o build/timer.o build/periodicTimer.o build/posixThread.o build/thread.o

build_td_0:
	gcc src/td0/a/main.c -o bin/td0_a -O3 -Wall -Wextra

build_td_1:
	g++ src/td1/b/main.cpp -o bin/td1_b -lrt -O3 -Wall -Wextra
	g++ src/td1/c/main.cpp lib/itr.a -I . -o bin/td1_c -O3 -Wall -Wextra
	g++ src/td1/d/main.cpp lib/itr.a -I . -lrt -o bin/td1_d -O3 -Wall -Wextra

build_td_2:
	g++ src/td2/a/main.cpp lib/itr.a -I . -lrt -pthread -o bin/td2_a -O3 -Wall -Wextra
	g++ src/td2/b/main.cpp lib/itr.a -I . -lrt -pthread -o bin/td2_b -O3 -Wall -Wextra
	g++ src/td2/c/main.cpp lib/itr.a -I . -lrt -pthread -o bin/td2_c -O3 -Wall -Wextra

build_td_3:
	g++ src/td3/b/main.cpp src/td3/b/CountDown.cpp lib/itr.a -I . -lrt -pthread -o bin/td3_b -O3 -Wall -Wextra
	g++ src/td3/c/main.cpp lib/itr.a -I . -lrt -pthread -o bin/td3_c -O3 -Wall -Wextra

tests: build_lib
	g++ tests/time.cpp lib/itr.a -I . -o bin/test_time -O3 -Wall -Wextra
	./bin/test_time
	g++ tests/chrono.cpp lib/itr.a -I . -o bin/test_chrono -O3 -Wall -Wextra
	./bin/test_chrono
