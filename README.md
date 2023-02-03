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

- the matcher problems fixed by adding pointers, now it's fine

- concatenateNFA previously removed any transition from endState, now they are preserved

- EngineNFA(nfa1,nfa2) which represented Alternatives now works. it almost was fine, I just had to add a couple thing + fixing a stupid error on Endstate which left the program in an inconsistent state


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
