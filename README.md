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

I have written multiple functions in the main file + added the new constructor in EngineNFA + slightly modified the concatenateNFA method.

I also have added some printing "myState()" functions to check whether the result is correct

### Tomasz 🇵🇱

- Wrote the concatenateNFA() function; it seems to work, but I've only done a little bit of testing


### Emre 👨🏻‍🇹🇷

### Basak 👩🏻‍🇹🇷

## What we are doing atm:
### Paolo 🇮🇹

### Tomasz 🇵🇱

- Writing the EngineNFA constructor that creates an AstAlternative NFA out of two NFAs.


### Emre 👨🏻‍🇹🇷

### Basak 👩🏻‍🇹🇷
