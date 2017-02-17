# 450project
This program applies the a graph coloring algorithmn to the problem of register allocation. A register interference graph is a representation of variables in a compiled program. This graph represents when variables are live at some time during a programs execution. This graph is colored with registers so that no two live variables share the same register at some point.

#running
call make to compile, will compile to executable called regalloc

This program takes in undirected edges as input, some test cases are located in test_cases

#progress so far
the register interference graph is built and printed out to console. a simple heurestic to reduce the graph size has been applied. A greedy approach to approximate graph coloring is currently being worked on.
