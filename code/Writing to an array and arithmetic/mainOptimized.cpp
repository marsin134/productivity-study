
#include <chrono>
#include <cstdint>
#include <iostream>
#include <vector>
#include <omp.h>

int main() {
    constexpr std::int64_t n = 100'000'000;
    std::vector<std::int64_t> a(n);

    const auto start = std::chrono::steady_clock::now();

    #pragma omp parallel for schedule(static)
    for (std::int64_t i = 0; i < n; ++i) {
        a[i] = (i * 31 + 7) % 1000;
    }

    const auto end = std::chrono::steady_clock::now();

    std::int64_t checksum = 0;
    for (const auto v : a) {
        checksum += v;
    }

    const auto elapsed =
        std::chrono::duration<double>(end - start).count();

    std::cout << "Threads: " << omp_get_max_threads() << '\n';
    std::cout << "Time: " << elapsed << " seconds\n";
    std::cout << "Checksum: " << checksum << '\n';
}
