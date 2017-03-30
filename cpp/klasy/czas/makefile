CC=g++
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=klasy1.cpp czas.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=klasy1

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@
