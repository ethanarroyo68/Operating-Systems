# Compiler and flags
CC = gcc
CFLAGS = -Wall -O2

# Targets
all: Driver
Driver: Driver.o MemoryManager.o
	$(CC) $(CFLAGS) -o $@ $^

Driver.o: Driver.c MemoryManager.h
	$(CC) $(CFLAGS) -c $<

MemoryManager.o: MemoryManager.c MemoryManager.h
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f Driver *.o