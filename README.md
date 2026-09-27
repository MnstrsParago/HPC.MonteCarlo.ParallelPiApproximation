# HPC.MonteCarlo.ParallelPiApproximation
 
Monte Carlo simulation in C++ to approximate π, with parallel design analysis using the PCAM methodology.
 
## What I Did
 
- Implemented a Monte Carlo method to approximate π by randomly generating points inside a 2×2 square and checking if they fall within a unit circle
- Tested different values of N (10³ to 10⁶) to observe convergence behavior
- Simulated 4 parallel processors by dividing N points equally and tracking local counts
- Applied a reduction operation to combine local results into a final approximation
- Analyzed the problem using the PCAM framework: Partitioning, Communication, Agglomeration, and Mapping
## Results
 
| N | Approximated π |
|---|---|
| 1,000 | 3.152000 |
| 10,000 | 3.170800 |
| 100,000 | 3.146680 |
| 1,000,000 | 3.142430 |
 
## Simulated Processor Output
 
Processor 0: 196427  
Processor 1: 196282  
Processor 2: 196271  
Processor 3: 196627  
Total inside: 785607  
Final pi: 3.14243
 
## Key Takeaways
 
- The problem is embarrassingly parallel — each point is fully independent
- Accuracy improves as O(1/√N), so 100× more points gives ~10× better precision
- Only one integer per processor needs to be communicated at the end (sum reduction)
- Agglomeration is critical — one task per point would create 1M tasks with near-zero computation each
## Tools
 
- C++
- Compiler Explorer (godbolt.org)
