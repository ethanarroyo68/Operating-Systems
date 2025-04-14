# Makefile for Producer-Consumer Project

# Define the Java compiler and flags
JAVAC = javac
JAVA = java
RM = rm -f

# Define source files
SOURCES = ProducerConsumer.java CircularBuffer.java Producer.java Consumer.java

# Define output class files
CLASSES = $(SOURCES:.java=.class)

# Default target to build everything
all: $(CLASSES)

# Rule to compile .java files to .class files
%.class: %.java
	$(JAVAC) $<

# Clean up compiled files
clean:
	$(RM) *.class

# Run the program
run: all
	$(JAVA) ProducerConsumer
