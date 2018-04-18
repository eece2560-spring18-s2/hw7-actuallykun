# HW7 Kenneth Leombruno

## Building the Graph Solution

My solution for building the graph involved going through each group and
then going through each member of that group. For each member, go through
the rest of the members in the group adding each other to their
connecting_members field. This ensures no duplicate links. Due to the nested
loops big O would be N^3 or G * K * K.

## BFS and IDDFS benchmarks
p2 time: 0.117263 sec
p2 memory: 126,988 kbytes
p3 time: 0.00836852 sec
p3 memory: 126,844 kbytes

BFS took longer than IDDFS and they each had about the same memory usage
however this may be do to how the code was written.

