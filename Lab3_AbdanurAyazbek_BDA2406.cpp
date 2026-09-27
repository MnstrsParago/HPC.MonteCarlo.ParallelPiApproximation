#include <iostream>
#include <random>

int main() {
    const int P = 4;
    const long long N = 1000000;

    std::mt19937 generator(42);
    std::uniform_real_distribution<double> distribution(-1.0, 1.0);

    // Part 1: Basic Monte Carlo
    long long inside = 0;
    for (long long i = 0; i < N; ++i) {
        double x = distribution(generator);
        double y = distribution(generator);
        if (x * x + y * y <= 1.0) {
            inside++;
        }
    }
    std::cout << "=== Part 1 ===" << std::endl;
    std::cout << "Total points: " << N << std::endl;
    std::cout << "Points inside circle: " << inside << std::endl;
    std::cout << "Approximated pi: " << 4.0 * inside / N << std::endl;
    std::cout << std::endl;

    // Part 4: Simulate 4 processors
    std::mt19937 generator2(42);
    long long local_inside[P] = {0};
    for (int p = 0; p < P; ++p) {
        for (long long i = 0; i < N / P; ++i) {
            double x = distribution(generator2);
            double y = distribution(generator2);
            if (x * x + y * y <= 1.0) {
                local_inside[p]++;
            }
        }
    }

    std::cout << "=== Part 4 ===" << std::endl;
    for (int p = 0; p < P; ++p) {
        std::cout << "Processor " << p << ": " << local_inside[p] << std::endl;
    }
    std::cout << std::endl;

    // Part 5: Reduction
    long long total_inside = 0;
    for (int p = 0; p < P; ++p) {
        total_inside += local_inside[p];
    }
    std::cout << "=== Part 5 ===" << std::endl;
    std::cout << "Total inside: " << total_inside << std::endl;
    std::cout << "Final pi: " << 4.0 * total_inside / N << std::endl;

    return 0;
}