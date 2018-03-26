#ifndef HELPER_H
#define HELPER_H

//funções necessárias para o funcionamento do quicksort
void swap(long long* a, long long* b, char** c, char ** d, long long* e, long long* f);
int partition (long long arr[], char** arr2, long long arr3[], int low, int high);
void quickSort(long long arr[], char** arr2, long long arr3[], int low, int high);

//retorna o identificador das datas mínimas e máximas. arg == -1 retorna data mínima e arg == 1 retorna data máxima
int modBinarySearch(long long v[], int min, int max, long long x, int arg);

#endif