# Berlin public transport simulation

### Current ideas:

The program will simulate the existant Berlin (and possibly other cities) public transport system, in order to determine the _best_ route
between two selected stations. 
The _best_ route is selected based on multiple criteria, for instance:
    - The shortest distance,
    - The shortest amount of time,
    - The least amount of energy used by the network.

### Factors accounted for in the model:
1. The optimal route is different based on the day of the week and the time of the day,
2. Waiting for the train to arrive during transit,

### Approximations assumed in the model:
1. Trains take no time between arriving and leaving the stations,
2. **Start** and **end** position must be train stations,

