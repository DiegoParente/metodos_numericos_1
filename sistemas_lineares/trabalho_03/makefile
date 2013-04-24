CC=g++
CFLAGS=-c -g -Wall
LDFLAGS=


SOURCES=report.h report.cpp seidel.h seidel.cpp main.cpp
OBJECTS=$(SOURCES:.cpp=.o)

EXECUTABLE=experimento


all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@
clean:
	rm -rf *o $(EXECUTABLE)
