CC=g++
CFLAGS=-c -g -Wall
LDFLAGS=


SOURCES=linear_system.h linear_system.cpp main.cpp
OBJECTS=$(SOURCES:.cpp=.o)

EXECUTABLE=me_rode


all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@
clean:
	rm -rf *o $(EXECUTABLE)
