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

I also have added some printing "myState()" functions to check whether the result is correct (they somehow don't work now, maybe you can try to fix them Tomasz)

Other problems:

- I think there is some problem in the EngineNFA(EngineNFA, EngineNFA) constructor (the one representing alternative)

- Also I think we need to fix a thing about concatenation, but nothing really urgent (I'll explain it when we meet)



### Tomasz 🇵🇱

- Ok, after spending multiple hours staring at the code, I noticed that there's A LOT of tiny problems in the code. I definitely haven't caught all of them though.

```EpsTransition``` results in a segmentation fault.

if we simply do:

```
EpsilonCharacter eps;
OneStepNFA(eps);
```
It works. However, if we put this in a function:
```
EngineNFA EpsTransition()
{
  EpsilonCharacter eps;
  return oneStepNFA(eps);
}
```
<img width="1124" alt="Screenshot 2023-02-03 at 00 13 33" src="https://user-images.githubusercontent.com/74839077/216472239-a2b9a9d0-6bae-41d6-956d-e1524ee14221.png">
This results in a segmentation fault. I don't know why, but this has a lot of implications:

- ```plus``` works, as it doesn't use the ```EpsTransition``` stuff 
- I fixed ```EpsTransition``` by removing it 💀
- I fixed ```questionMark```
- ```star``` works, as the questionMark that it depends on has been fixed
- In the ```EngineNFA.cpp``` at line 19, we had ```states.push_back(State(state))``` - why? if ```state``` is already of type ```State```
- I don't know if there should be references in places like ```EngineNFA::concatenateNFA(EngineNFA& nfaToConcat)```. I tried adding it, but it didn't seem to change anything. I.e. it still gave a segmentation fault, but since there are so many issues that conicide, we should look closer at it. This also regards the constructor ```EngineNFA::EngineNFA(EngineNFA nfa1, EngineNFA nfa2)``` where we don't use the references either, or ```void EngineNFA::addState(State state)```

- Apart from that, I only made some syntax changes that don't change the meaning 




### Emre 👨🏻‍🇹🇷

### Basak 👩🏻‍🇹🇷

## What we are doing atm:
### Paolo 🇮🇹

segmentation fault in the solving (hopefully)

### Tomasz 🇵🇱

- Fighting with segmentation faults 🥊


### Emre 👨🏻‍🇹🇷

### Basak 👩🏻‍🇹🇷
