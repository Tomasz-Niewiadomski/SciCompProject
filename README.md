# RegEx matching/searching algorithms

## The current plan:
Let's split the project into phases:

1. NFA engine - searches for pattern when given a graph ✅
3. Parse regex into an AST (Abstract Syntax Tree) - breaks down a regular expression into categories ✅
4. Build NFA from regex - "builds a graph" from a given regular expression 🇵🇱🇮🇹
5. Tie it all together - given a regular expression, builds the graph and searches for pattern with the engine
6. Think of additional features 👨🏻‍🇹🇷
7. Benchmark time 👨🏻‍🇹🇷
8. Writing the report & preparing presentation 👩🏻‍🇹🇷

## What have we done:
### Paolo 🇮🇹

main.cpp was an absolute mess: I created external files for parsing and engine creation functions. the Makefile has been modified too.


### Tomasz 🇵🇱

- Maybe we nedd to add support for the ```.``` character, so that we could use ```.*anything.*``` which would search through all the text?

### Emre 👨🏻‍🇹🇷

### Basak 👩🏻‍🇹🇷

## What we are doing atm:
### Paolo 🇮🇹

segmentation fault in the solving (hopefully)

### Tomasz 🇵🇱

- Fighting with segmentation faults 🥊


### Emre 👨🏻‍🇹🇷

### Basak 👩🏻‍🇹🇷
