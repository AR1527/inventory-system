shop: main.o
	g++ main.o -o Shop

test.o: main.cpp
	g++ -c main.cpp
