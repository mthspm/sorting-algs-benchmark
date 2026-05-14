#pragma once
#include <cstdlib>
#include <ctime>
#include <vector> 
#include <iostream>


void bubble_sort(int *numeros, int tamanho){
   
    // logica do BubbleSort
    for (int i = 0; i < tamanho - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < tamanho - 1 - i; j++) {
            
            if (numeros[j] > numeros[j + 1]) {
                int temporario = numeros[j];
                numeros[j] = numeros[j + 1];
                numeros[j + 1] = temporario;
                swapped = true;
            }
        }
        
        if (!swapped)
            return;
    }
    
}

void bubble_sort(std::vector<int> &numeros){

    int tamanho = numeros.size();
    bubble_sort(numeros.data(), tamanho);
}