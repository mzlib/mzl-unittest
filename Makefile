SOURCES=$(wildcard src/*.cpp) unittest.cpp

install:
	mkdir -p bin
	g++ -std=c++1z $(SOURCES) -o bin/unittest
	./bin/unittest
	rm -rf bin