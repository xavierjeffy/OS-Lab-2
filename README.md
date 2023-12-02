# OS-Lab-2
Xavier Jeffy

Banker's Algorithm

Explanation

My version of the banker's algorithm determines whether the system's state is in a safe 
sequence or not, based on the allocated, maximum, available, and needed resources for 
a set number of processes and resources with the values of each matrix being read in 
from a text file. The algorithm iterates through processes and avaiable resources to
determine if the sequence is safe. If all of the processes can complete execution without
causing deadlock, a safe sequence is identified.

The program is compiled using:

clang++ banker.cpp

The program is run using:

./a.out

Example output

Following is the SAFE Sequence
P1 -> P3 -> P4 -> P0 -> P2
