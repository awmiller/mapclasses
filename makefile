# Makefile entries are arranged as sets of targets to build, dependencies
# required to build that target, and the system command to build the target:
#
# target: dependencies
# [tab] system_command
#
# We can also use variables in our makefile, to make it easier to change
# compilers, or compilation flags.  The variable values are substituted
# wherever you see the $(VARIABLE) in the makefile
CC=g++ -std=c++11
CFLAGS=-c -g -Wall

all: driver

driver: main.o map_item.o factory.o inheritance_test.o node.o no_op_item.o queue.o residential.o
	$(CC) main.o map_item.o factory.o inheritance_test.o node.o no_op_item.o queue.o residential.o -g -o driver

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

#map.o: map.cpp map.h
#	$(CC) $(CFLAGS) map.cpp

map_item.o: map_item.cpp map_item.h
	$(CC) $(CFLAGS) map_item.cpp

factory.o: factory.cpp factory.h
	$(CC) $(CFLAGS) factory.cpp

inheritance_test.o: inheritance_test.cpp inheritance_test.h
	$(CC) $(CFLAGS) inheritance_test.cpp

node.o: node.cpp node.h
	$(CC) $(CFLAGS) node.cpp

no_op_item.o: no_op_item.cpp no_op_item.h
	$(CC) $(CFLAGS) no_op_item.cpp

queue.o: queue.cpp queue.h
	$(CC) $(CFLAGS) queue.cpp 

residential.o: residential.cpp residential.h
	$(CC) $(CFLAGS) residential.cpp

clean:
	rm -f *.o driver


