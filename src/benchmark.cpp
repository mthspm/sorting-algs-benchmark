#include <benchmark/benchmark.h>

#include <random>
#include <vector>

#include "mergesort.hpp"
#include "utils.hpp"

using namespace benchmark_utils;

// Função genérica para fazer o benchmark de um algoritmo de ordenação qualquer
template <sort_algorithm sort_function> static void BM_random_sort(benchmark::State &state) {
    const int N = state.range(0);

    for (auto _ : state) {
        state.PauseTiming();
        auto v = generate_random_vector(N);
        state.ResumeTiming();

        sort_function(v);

        benchmark::DoNotOptimize(v.data());
    }
    state.SetComplexityN(N);
}

// Faz o benchmark do merge_sort para 1, 2, 3 e 4 milhões de elementos
BENCHMARK_TEMPLATE(BM_random_sort, merge_sort)
    ->Arg(1000000)
    ->Arg(2000000)
    ->Arg(3000000)
    ->Arg(4000000)
    ->Unit(benchmark::kMicrosecond);

BENCHMARK_MAIN();