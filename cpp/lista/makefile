CXX=g++
CXXFLAGS=-Wall -I.
OBJS=lista.o main_lista.o

pong: lista.o main_lista.o
	$(CXX) $(CXXFLAGS) $(OBJS) -o main_lista

.PHONY: clean

clean:
	rm -f *.o *~ core *~
