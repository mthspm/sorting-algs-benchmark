#pragma once
#include <algorithm>
#include <random>
#include <vector>

namespace benchmark_utils {
// Define sort_algorithm como uma função void que recebe um vetor de inteiros
// Isso é usado para criar funções genéricas para cada tipo de algoritmo
using sort_algorithm = void (*)(std::vector<int> &);

// Gera um vetor com dados aleatórios
std::vector<int> generate_random_vector(size_t n) {
    std::vector<int> v(n);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 1000000);
    for (int &i : v)
        i = dis(gen);
    return v;
}

bool is_sorted(std::vector<int> &v) {
    int last = v.at(0);
    for (int n : v) {
        if (n < last)
            return false;
        last = n;
    }
    return true;
}

} // namespace benchmark_utils