dependencies:
	mkdir -p lib
	wget -O lib/assert.h https://raw.githubusercontent.com/stanley-c-cpp-projects/assert/master/src/assert.h
	wget -O lib/assert.c https://raw.githubusercontent.com/stanley-c-cpp-projects/assert/master/src/assert.c

test: test/stack-test.o lib/assert.o src/stack.o
	mkdir -p bin
	gcc -o bin/test.bin test/stack-test.o lib/assert.o src/stack.o
	./bin/test.bin
