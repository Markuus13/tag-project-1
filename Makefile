all:
	g++ -std=c++11 -Wall -pedantic Vertex.cpp Graph.cpp main.cpp -o main
	./main
