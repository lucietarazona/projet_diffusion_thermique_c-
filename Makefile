compile:
	g++ -o main -Iincludes/ *.cpp

exec:
	./main

test:
	g++ -o test -Iincludes/ tests.cpp CMatrix.cpp && ./test

all: compile exec

.PHONY: compile exec all
