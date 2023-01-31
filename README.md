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
engineCreator is almost done: I just need to fix quantifier a bit, but the main part is already there.

### Tomasz

- I managed to find stupid workaroudns so that the class part now works!
- Wrote the compute() function. It compiles, but always returns 'false'. I uploaded it only under core.cpp as it's in development.
- Update: Now compute() works! Will work on the 'memory' feature, so that it doesn't get stuck in epsilon loops.
- Update: I added the memory functionality to compute() & updated the individual files


### Emre

### Basak

## What we are doing atm:
### Paolo 
(Wednesday) I will finish the job on the engine creation.

### Tomasz

- Need to make the code a bit clearer and comment over it

### Emre

### Basak
