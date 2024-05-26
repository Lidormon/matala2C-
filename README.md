This project add the possibility to the  Graph class to support various arithmetic and comparison operations on graphs 

Files Included


Graph.hpp: this file  contains the declaration of the Graph class and it's  functions.

Graph.cpp: this file contains the Implementation of the function declared in  the file graph.pp

Algorithms.cpp: this  file contains algorithms on the  graph operations.


Arithmetic opération 

Addition (+) and Addition Assignment (+=)

 The addition operator is implemented to add two graphs .To implement this operator we  iterating on  each cell in the adjacency matrices of the graphs and adding their corresponding values.

Unary Plus Operator (+)

 The unary plus operator returns a copy of the graph. It does not modify the original graph.

Subtraction (-) and Subtraction Assignment (-=)

The Subtraction operators subtract one graph from another . To implement this function we iterating on  each cell in the adjacency matrices and do substraction 


Increment (++) and Decrement (--)

Those  operators increase or decrease all edge weights by 1. To implement this function we iterate ik each cell in the adjacency matrix and incrementing or decrementing its value.


Multiplication () and Multiplication Assignment (=)

 Multiplication operators multiply all edge weights by a scalar value. to implement this operator we pass on  each cell in the adjacency matrix and do the multiplication.


Division (/) and Division Assignment (/=)

 Division operators divide all edge weights by a scalar . 

Comparison Operators


Greater (>), Greater-than-equal (>=), Less (<), Less-than-equal (<=), Equal (==), and Not-equal (!=)

 Comparison operators compare two graphs based on their number of edges and vertices. The comparisons are performed by examining the adjacency matrices of the graphs and comparing their values.



Output Operator

 The output stream operator prints the graph in a particular format .
