all: clean build tests

clean:
	rm -rf build/*
	rm -rf bin/*

build: build_td_0 build_td_1 build_td_2 build_td_3 build_td_4

build_td_0:
	gcc src/td0/a/main.c -o bin/td0_a -O3 -Wall -Wextra

build_td_1:
	g++ -c src/td1/a/time.cpp -I . -o build/time.o -O3 -Wall -Wextra
	ar rcs lib/time.a build/time.o
	g++ src/td1/b/main.cpp -o bin/td1_b -lrt -O3 -Wall -Wextra
	g++ src/td1/c/main.cpp lib/time.a -I . -o bin/td1_c -O3 -Wall -Wextra
	g++ src/td1/d/main.cpp lib/time.a -I . -lrt -o bin/td1_d -O3 -Wall -Wextra

build_td_2:
	g++ src/td2/a/main.cpp lib/time.a -I . -lrt -pthread -o bin/td2_a -O3 -Wall -Wextra
	g++ src/td2/b/main.cpp lib/time.a -I . -lrt -pthread -o bin/td2_b -O3 -Wall -Wextra
	g++ src/td2/c/main.cpp lib/time.a -I . -lrt -pthread -o bin/td2_c -O3 -Wall -Wextra

build_td_3:
	g++ -c src/td3/a/chrono.cpp -I . -o build/chrono.o -O3 -Wall -Wextra
	ar rcs lib/chrono.a build/chrono.o
	g++ -c src/td3/b/timer.cpp -I . -o build/timer.o -O3 -Wall -Wextra
	ar rcs lib/timer.a build/timer.o
	g++ src/td3/b/main.cpp src/td3/b/countDown.cpp lib/timer.a lib/time.a -I . -lrt -pthread -o bin/td3_b -O3 -Wall -Wextra
	g++ src/td3/c/main.cpp lib/timer.a lib/time.a -I . -lrt -pthread -o bin/td3_c -O3 -Wall -Wextra

build_td_4:
	g++ -c src/td4/a/posixThread.cpp -I . -o build/posixThread.o -O3 -Wall -Wextra
	ar rcs lib/posixThread.a build/posixThread.o

tests: build_td_1 build_td_3
	g++ tests/time.cpp lib/time.a -I . -o bin/test_time -O3 -Wall -Wextra
	./bin/test_time
	g++ tests/chrono.cpp lib/chrono.a lib/time.a -I . -o bin/test_chrono -O3 -Wall -Wextra
	./bin/test_chrono
