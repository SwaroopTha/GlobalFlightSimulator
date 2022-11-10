EXENAME = graph
OBJS = main.o graph.o

INCLUDES=-Iincludes/
CXX_FLAGS=-std=c++20 -g -fstandalone-debug -Wall -Wextra -Werror -pedantic $(INCLUDES)

CXX = clang++
CXXFLAGS = $(CS225) -std=c++1y -stdlib=libc++ -c -g -O0 -Wall -Wextra -pedantic
LD = clang++
LDFLAGS = -std=c++1y -stdlib=libc++ -lc++abi -lm

all : $(EXENAME)

exec: bin/exec

bin/exec: Graph.cpp Graph.h main.cpp readdat.cpp readdat.h Algorithms/bet_cent.cpp Algorithms/bet_cent.h Algorithms/bfs.cpp Algorithms/bfs.h Algorithms/dijkstra.cpp Algorithms/dijkstra.h
	${CXX} ${CXX_FLAGS} main.cpp Graph.cpp readdat.cpp Algorithms/bfs.cpp Algorithms/dijkstra.cpp Algorithms/bet_cent.cpp -o bin/exec

$(EXENAME) : $(OBJS)
	$(LD) $(OBJS) $(LDFLAGS) -o $(EXENAME)

main.o : Graph.cpp Graph.h main.cpp readdat.cpp readdat.h Algorithms/bet_cent.cpp Algorithms/bet_cent.h Algorithms/bfs.cpp Algorithms/bfs.h Algorithms/dijkstra.cpp Algorithms/dijkstra.h
	$(CXX) $(CXXFLAGS) Graph.cpp Graph.h main.cpp readdat.cpp readdat.h Algorithms/bet_cent.cpp Algorithms/bet_cent.h Algorithms/bfs.cpp Algorithms/bfs.h Algorithms/dijkstra.cpp Algorithms/dijkstra.h

graph.o : Graph.cpp Graph.h 
	$(CXX) $(CXXFLAGS) Graph.cpp

test: tests.o Graph.o
	$(LD) tests.o Graph.o $(LDFLAGS) -o test

tests.o : tests/test-graph.cpp tests/test-readdat.cpp Graph.cpp Graph.h
	$(CXX) $(CXXFLAGS) test-graph.cpp

clean :
	-rm -f *.o $(EXENAME) test
