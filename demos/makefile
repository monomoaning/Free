objects=hashtable.o main.o
CCFLAGS=-std=c++11
CC=g++
hashtable:$(objects)
	$(CC)   $^ -o $@
main.o:main.cpp hashtable.h
	$(CC) $(CCFLAGS)  -o $@  -c $<
hashtable.o:hashtable.cpp hashtable.h
	$(CC) $(CCFLAGS)  -o $@  -c $<
.PHONY:clean
clean:
	rm $(objects) hashtable