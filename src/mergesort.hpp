#pragma once
#include <cstring>
#include <vector>

inline void merge(int *array, int *aux, int start, int middle, int end) {
    int a = 0, b = start, c = middle + 1;

    while (b <= middle && c <= end) {
        if (array[b] > array[c]) {
            aux[a++] = array[c++];
        } else {
            aux[a++] = array[b++];
        }
    }

    while (b <= middle)
        aux[a++] = array[b++];
    while (c <= end)
        aux[a++] = array[c++];

    // copia a memória de aux (0 até size) para array (start até  start + size)
    int size = (end - start) + 1;
    std::memcpy(&array[start], aux, size * sizeof(int));
}

void merge_sort(int *array, int *aux, int start, int end) {
    if (start < end) {
        int middle = start + (end - start) / 2;
        merge_sort(array, aux, start, middle);
        merge_sort(array, aux, middle + 1, end);
        merge(array, aux, start, middle, end);
    }
}

void merge_sort(std::vector<int> &array) {
    int size = array.size();
    std::vector<int> aux(size);
    merge_sort(array.data(), aux.data(), 0, size - 1);
}