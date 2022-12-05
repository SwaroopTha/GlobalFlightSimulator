# WBLR

## Developers: Tyler Hecht, Will Otani, Swaroop Thammineni, Rohan Gudipaty

https://openflights.org/data.html

## Relevant Files/Folders

* Data : contains airport data and routes data necessary for processing

* Algorithms
    * bet_cent : ?
    * dijkstra : Dijkstra's Algorithm for shortest path
    * bfs : Breadth-First Search Algorithm
* readdat : reads the data from the data files and implements data into graph network
* Graph : class represents attributes of the graph data structure
* makeimage : Visualizer tool for all algorithms (map in Data)
* ProgressBar : For showing progress on the command line


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
make main
./main
```

Testing:
* For specic test follow ./test with specific test 

```
make test
./test
```
