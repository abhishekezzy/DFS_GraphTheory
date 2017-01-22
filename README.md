#Depth Fisrt Search for Graphs

In depth-first search the idea is to travel as deep as possible from neighbour to neighbour before backtracking. What determines how deep is possible is that you must follow edges, and you don't visit any vertex twice.
To do this properly we need to keep track of which vertices have already been visited, plus how we got to (the path to) where we currently are, so that we can backtrack. We could keep track of which nodes were visited in a boolean array, and a stack to push nodes onto that we mean to visit.
To visualize check out this link : https://www.cs.usfca.edu/~galles/visualization/DFS.html

##DFS can be used to solve a lot of problems such as:
###Finding Connected Components in a Graph
###Detect Cycle in a Graph
###Topological Sorting of a Graph
###Solving Puzzles and Mazes

