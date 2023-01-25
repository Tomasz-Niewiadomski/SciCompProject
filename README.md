# RegEx matching/searching algorithms

## The current plan:
Let's split the project into phases:

1. NFA engine - searches for pattern when given a graph
3. Parse regex into an AST (Abstract Syntax Tree) - breaks down a regular expression into categories
4. Build NFA from regex - "builds a graph" from a given regular expression
5. Tie it all together - given a regular expression, builds the graph and searches for pattern with the engine
6. Think of additional features
7. Benchmark time
8. Writing the report & preparing presentation

## What have we done:
### Paolo
Divided everything in .cpp and .h and created the makefile. 
I couldn't solve the isuue with the transition struct. maybe we can just switch back to a tuple?
We'll definitely need pointers for the map, but I'm convinced simply using smart/unique ptr will be fine.
### Tomasz

### Emre

### Basak

## What we are doing atm:
### Paolo 

### Tomasz
- Throughout this weekend, I will try to implement the state class; the matcher class; and the NFA engine class, without the search() function. 

The search() function inside the NFA engine class will probably be the hardest part of this phase.

### Emre

### Basak
