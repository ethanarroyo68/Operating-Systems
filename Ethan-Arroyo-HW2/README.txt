README
======

This package includes the following files.
**After completion message: these descriptions are adequate, and there is no other information I feel the grader needs.

|-- coordinator.c [The Coordinator program creates four child processes using fork(), 
replaces them with the Checker program using exec(), and waits for their completion.]
|-- checker.c [The Checker program determines if a given dividend is divisible by a 
divisor and prints the result with a prefixed identifier.]
|-- Makefile
|-- README.txt

To compile:
    make all

To run:
    ./coordinator <5 arguments>

For example;
    ./coordinator 1 2 3 4 5