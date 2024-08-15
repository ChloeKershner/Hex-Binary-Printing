CXX=g++
CXXFLAGS=-std=c++11 -Wall -g3 -c
OBJS = main.o binary_printing.o hex_printing.o
PROGRAM = xed

$(PROGRAM): $(OBJS)
	$(CXX) -o $(PROGRAM) $^

main.o: main.cpp include.h
	$(CXX) $(CXXFLAGS) main.cpp

binary_printing.o: binary_printing.cpp binary_printing.h
	$(CXX) $(CXXFLAGS) binary_printing.cpp

hex_printing.o: hex_printing.cpp hex_printing.h
	$(CXX) $(CXXFLAGS) hex_printing.cpp

clean:
	rm -f *.o $(PROGRAM)