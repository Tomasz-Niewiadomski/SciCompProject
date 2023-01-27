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

- I managed to find stupid workaroudns so that the class part now works!
- Wrote the compute() function. It compiles, but always returns 'false'. I uploaded it only under core.cpp as it's in development.
- Update: Now compute() works! Will work on the 'memory' feature, so that it doesn't get stuck in epsilon loops.
- Update: I added the memory functionality to compute() & updated the individual files

(comment by Paolo) yoooo this is great!!! 

### Emre

### Basak

## What we are doing atm:
### Paolo 

### Tomasz

- Need to make the code a bit clearer and comment over it

### Emre

### Basak
