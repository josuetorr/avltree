# -*- Makefile -*-

cc=g++
flags=-Wall -pedantic -std=c++11 -g
src=main.cpp
obj=main.o
header=avl.h avl.hpp
exe=avl.out

.PHONY: default clean test

default :$(exe)

$(exe): $(obj)
	@$(cc) -o $(exe) $(obj) $(flags)

main.o: main.cpp $(header)
	@$(cc) -c main.cpp $(flags)

test:
 
clean:
	@rm -rf $(exe) $(obj)
