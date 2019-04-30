# -*- Makefile -*-

cc=g++
flags=-Wall -pedantic -std=c++11 -g
src=main.cpp avl.cpp
obj=main.o avl.o
header=avl.hpp
exe=avl.out

.PHONY: default clean test

default :$(exe)

$(exe): $(obj)
	@$(cc) -o $(exe) $(obj) $(flags)

main.o: main.cpp
	@$(cc) -c $^ $(flags)

avl.o: avl.cpp
	@$(cc) -c $^ $(flags)

test:

clean:
	rm -rf $(exe) $(obj)
