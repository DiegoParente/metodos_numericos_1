CC=g++
CFLAGS=-c -g -Wall
LDFLAGS=


SOURCES=solver.h solver.cpp main.cpp
OBJECTS=$(SOURCES:.cpp=.o)

EXECUTABLE=relatar


all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@
clean:
	rm -rf *o $(EXECUTABLE)
