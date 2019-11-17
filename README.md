# DSA_Project

Project Topic:  Graph Coloring and its applications

This project, solves the graph coloring (m- coloring problem) problem. Some of the applications of the graph coloring are also implemented.

The first application is time table scheduling of an examination. For multiple courses available at an university, there might be same student appearing in multiple courses exam. These exam should not be at the same time slot. So, here these courses becomes the vertices of our graph and each edge between any to vertices (i.e. courses) represents there is(are) student(s) in common. By the help of graph coloring, we can come up with minimum number of colors required to color this graph. Here each color represents a time slot for a exam. Two courses sharing an edge can not have same time slot.

The second application is mobile tower frequency allocation. In a region, there are multiple connectivity towers are available. Our problem is to determine the minimum no of frequency required to allocate one to a tower. If two towers are in range of each other, they must have different frequencies. Here, towers are our vertices and there is edge between two vertices if they are in range of each other. After the solution each vertex has its own color. Different color represents a specific frequency allocated.

The third application is Sudoku solution. Here in this project we have printed all the 288 solution of 4*4 Sudoku. In a Sudoku, each box is considered as a vertex. There is a edge between two vertices if those boxes can't contain same number. And the solution is obtained by the graph coloring.
