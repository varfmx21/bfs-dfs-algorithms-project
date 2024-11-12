DNA Graph Search Project
This project implements a system to read a list of people from a text file, create a graph based on DNA similarity using the Hamming distance, and perform searches using Breadth-First Search (BFS) and Depth-First Search (DFS) algorithms to find a person with a target DNA sequence.

Project Overview
Read Data: Reads person information (name, surname, address, DNA, city, and phone number) from a text file and stores it in a Persona structure.
Graph Construction: Creates an adjacency matrix to represent the graph connections based on DNA similarity measured by the Hamming distance.
Search Algorithms: Implements BFS and DFS to traverse the graph and find a person with a specified DNA sequence, while measuring the search time.
Prerequisites
A C++ compiler supporting C++11 or later.
Input data file people.txt with each line formatted as:
css
Copiar código
FirstName,LastName,Address,DNA,City,Phone
Example:
css
Copiar código
John,Wilson,819 Main St,YNFBMJWGFD,New York,555-1074-1504
Files
main.cpp: Main source code file containing the implementation of reading data, creating the graph, and running BFS/DFS searches.
README.md: Project documentation.
How It Works
Data Structure
Persona Struct: Represents an individual person with fields for name, surname, address, DNA sequence, city, and phone.
vector<Persona>: Stores the list of people read from the input file.
Adjacency Matrix: A 2D vector representing the connections between people based on DNA similarity using the Hamming distance.
Graph Construction
The graph is constructed using an adjacency matrix where each node represents a person, and an edge is created between two nodes if their DNA sequences have a Hamming distance less than or equal to a specified threshold.

Hamming Distance Calculation: The number of differing characters between two strings of equal length.
Adjacency Matrix Creation:
For each pair of people, the Hamming distance between their DNA sequences is calculated.
An edge is created (value 1 in the matrix) if the distance is within the threshold; otherwise, the value is 0.
Graph Search Algorithms
Breadth-First Search (BFS)
Traverses the graph level by level, starting from the first node.
Stops when the target DNA sequence is found.
Uses a queue to explore neighbors.
Depth-First Search (DFS)
Traverses as far as possible along a branch before backtracking.
Stops when the target DNA sequence is found.
Uses a stack for traversal.
Code Explanation
Reading Data
cpp
Copiar código
void leerPersonas(const string filename, vector<Persona> &personas);
Reads person data from a text file and stores it in a vector of Persona.
Hamming Distance
cpp
Copiar código
int hammingDistance(const string &s1, const string &s2);
Calculates the Hamming distance between two DNA sequences.
Creating the Adjacency Matrix
cpp
Copiar código
vector<vector<int>> crearMatriz(const vector<Persona> &personas, int max);
Creates a graph representation based on DNA similarity.
BFS and DFS
cpp
Copiar código
int BFS(const vector<vector<int>> &matriz, const vector<Persona> &personas, const string &adnObjetivo);
int DFS(const vector<vector<int>> &matriz, const vector<Persona> &personas, const string &adnObjetivo);
Perform graph search to find a person with the target DNA.
Example Usage
Place your data in people.txt.

Compile and run the code:

bash
Copiar código
g++ main.cpp -o dna_search
./dna_search
The program reads the input data, constructs the graph, and runs BFS and DFS to find a person with the specified DNA.

Measuring Search Time
The time taken by BFS and DFS to find the target DNA is measured using the <chrono> library and displayed in seconds.

Future Improvements
Support for more complex graph structures or weighted graphs.
Additional search algorithms for comparison.
Optimized graph traversal for larger datasets.