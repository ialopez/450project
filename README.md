# 450project

#description
This program applies the a graph coloring algorithm to the problem of register allocation. A register interference graph is a representation of variables in a compiled program. This graph represents when variables are live at some time during a programs execution. This graph is colored with registers so that no two live variables share the same register at some point.

#implementation
A greedy approach to graph coloring is implemented in this project. The first fit algorithm is used to color variables with register numbers. The algorithm attemps to color a graph using k colors and if it fails it will spill a variable by removing it from the graph and try again.

#how to compile
call make to compile, will compile to an executable called regalloc

#input
for the time being input is taken of in the form of

```
number of nodes
node1-node3
node2-node1
node3-node2
```

where nodes are labeled by their appearance on the lefthand side of an edge. So node1 would be 0, node 2 would be 1 and node 3 would be 2. Number of distinct nodes must be specified at the top, in this case it would be 3. Some test cases are contained in the test case folder. These were generated from a python script that was found from here https://gist.github.com/bwbaugh/4602818

