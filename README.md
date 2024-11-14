# DNA Graph Search Project

This project implements a system to read a list of people from a text file, create a graph based on DNA similarity using the Hamming distance, and perform searches using Breadth-First Search (BFS) and Depth-First Search (DFS) algorithms to find a person with a target DNA sequence.

## Project Overview

- **Read Data**: Reads person information (name, surname, address, DNA, city, and phone number) from a text file and stores it in a `Persona` structure.
- **Graph Construction**: Creates an adjacency matrix to represent the graph connections based on DNA similarity measured by the Hamming distance.
- **Search Algorithms**: Implements BFS and DFS to traverse the graph and find a person with a specified DNA sequence, while measuring the search time.

## Prerequisites

- A C++ compiler supporting C++11 or later.
- Input data file `people.txt` with each line formatted as:

FirstName,LastName,Address,DNA,City,Phone

Example:
John,Wilson,819 Main St,YNFBMJWGFD,New York,555-1074-1504


## Files

- `main.cpp`: Main source code file containing the implementation of reading data, creating the graph, and running BFS/DFS searches.
- `README.md`: Project documentation.

## How It Works

### Data Structure

- **`Persona` Struct**: Represents an individual person with fields for name, surname, address, DNA sequence, city, and phone.
- **`vector<Persona>`**: Stores the list of people read from the input file.
- **Adjacency Matrix**: A 2D vector representing the connections between people based on DNA similarity using the Hamming distance.

### Graph Construction

The graph is constructed using an adjacency matrix where each node represents a person, and an edge is created between two nodes if their DNA sequences have a Hamming distance less than or equal to a specified threshold.

- **Hamming Distance Calculation**: The number of differing characters between two strings of equal length.
- **Adjacency Matrix Creation**:
- For each pair of people, the Hamming distance between their DNA sequences is calculated.
- An edge is created (value `1` in the matrix) if the distance is within the threshold; otherwise, the value is `0`.

### Graph Search Algorithms

#### Breadth-First Search (BFS)
- Traverses the graph level by level, starting from the first node.
- Stops when the target DNA sequence is found.
- Uses a queue to explore neighbors.

#### Depth-First Search (DFS)
- Traverses as far as possible along a branch before backtracking.
- Stops when the target DNA sequence is found.
- Uses a stack for traversal.

### Code Explanation

## Video Demostrativo salida consola
https://drive.google.com/file/d/1cZDst7noOnwqXakuu6uzhabYpF86Hz2i/view?usp=sharing