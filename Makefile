dependencies:
	mkdir -p libs
	wget -O libs/assert.h https://raw.githubusercontent.com/stanley-c-cpp-projects/assert/master/src/assert.h
	wget -O libs/assert.c https://raw.githubusercontent.com/stanley-c-cpp-projects/assert/master/src/assert.c

compile:
	mkdir -p lib
	gcc -c -o src/stack.o src/stack.c
	ar -cvq lib/libstack.a src/stack.o

test: test/stack-test.o libs/assert.o src/stack.o
	mkdir -p bin
	gcc -o bin/test.bin test/stack-test.o libs/assert.o src/stack.o
	./bin/test.bin
