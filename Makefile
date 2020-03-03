all: clean build tests

clean:
	rm -rf build/*

build: build_lib fifo timer looper looper2 looper3

build_lib:
	g++ -c src/time.cpp -I . -o build/itr.o -O3 -Wall -Wextra
	ar rcs lib/itr.a build/itr.o

fifo:
	gcc src/fifo/main.c -o bin/fifo -O3 -Wall -Wextra

timer:
	g++ src/timer/main.cpp -o bin/timer -lrt -O3 -Wall -Wextra

looper:
	g++ src/looper/main.cpp lib/itr.a -I . -o bin/looper -O3 -Wall -Wextra

looper2:
	g++ src/looper2/main.cpp lib/itr.a -I . -lrt -o bin/looper2 -O3 -Wall -Wextra

looper3:
	g++ src/looper3/main.cpp lib/itr.a -I . -lrt -pthread -o bin/looper3 -O3 -Wall -Wextra

tests: test_time

test_time: build_lib
	g++ tests/time.cpp lib/itr.a -I . -o bin/test_time -O3 -Wall -Wextra
	./bin/test_time
