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
