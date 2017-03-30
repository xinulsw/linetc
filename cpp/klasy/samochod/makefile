CXX=g++
CXXFLAGS=-Wall -I.
OBJS=samochod.o car.o osoba.o

quiz: samochod.o car.o osoba.o
	$(CXX) $(CXXFLAGS) $(OBJS) -o samochod

.PHONY: clean

clean:
	rm -f *.o *~ core *~
