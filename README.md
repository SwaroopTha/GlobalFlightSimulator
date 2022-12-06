# WBLR

## Developers: Tyler Hecht, Will Otani, Swaroop Thammineni, Rohan Gudipaty


## The WBLR Project Summary

In this project we designed multiple algorithms and visualization tools implemented on the network of world airports. Using a dataset retrieved from OpenFlights database, the airport network was constructed using all possible routes for the 10,000 airports across the world as of 2017. Furthermore, our algorithms will provide an in-depth exploration of optimal routes from sources and destinations as well as centrality of various airports. In addition, with visualization tools using cs225's PNG library, it allows for dynamic visualation of airport networks.  

## Code File Structure
* Build
* Data : contains airport data and routes data necessary for processing
    * airports.dat : airports info
    * map.png : world map basis
    * routes.dat : routes info
* entry
    * main.cpp
* lib : cs225 color space
* src
    * Algorithms
        * bet_cent : Determines which airports are "popular"
            * bet_cent.cpp
            * bet_cent.h
        * dijkstra : Dijkstra's Algorithm for shortest path between two airports
            * dijkstra.cpp
            * dijkstra.h
        * bfs : Breadth-First Search Algorithm traverses every single pathway from a given airport
            * bfs.cpp
            * bfs.h
    * CMakeLists.txt
    * Graph.cpp
    * Graph.h
    * makeimage.cpp
    * makeimage.h
    * ProgressBar.cpp
    * ProgressBar.h
    * readdat.cpp
    * readdat.h
        
* readdat : reads the data from the data files and implements data into graph network
* Graph : class represents attributes of the graph data structure
* makeimage : Visualizer tool for all algorithms (map in Data)
* ProgressBar : For showing progress on the command line
* tests : runs all test cases
* Dockerfile : cs225 Dockerfile is used
* README.md

## File Interaction

The `Graph` class and `readdat` files interact to construct a graph network of airports. The algorithm classes utilize instances of `Graph` to operate on with respective traversals.



## Set Up
Clone the repository:
```
git clone [REPOSITORY URL]
cd [REPOSITORY NAME]
````
Create a build directory and use cmake to create a makefile:
```
mkdir build
cd build
cmake ..
```

Create and run executable:
```
make
./main
```

Testing:
* For specic test follow ./test with specific test 
```
make test
./test
```

## How to Generate Visualization
1) Read in datasets to graph in `entry/main.cpp`
2) Use functions from `makeimage`to generate a plot of Dijkstra, Centrality or Betweenness. 
3) Call function in `entry/main.cpp` and write to a file.


## Bibliography
https://openflights.org/data.html#license

