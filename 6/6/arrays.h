#ifndef arrays
#define arrays

void raz(int* x);
void printArray(int* razmer, int* arr);
int** init_matrix(int x);
void print_matrix(int row, int col, int** arr);
int* rem_element_matrix(int* arr, int pos, int size);
int** init_matrix_NxM(int col, int row);
void paste_NxM(int** arr, int row, int col, int random);
int random();
void rand_elem(int* arr, int razmer);
int search_low_first(int* arr, int razmer);
int search_low_last(int* arr, int razmer, int low);
void elem_write(int element, int razmer, int* arr);
void print_low(int row, int** arr);
void insertionSort(int* arr, int min_l, int min_f);
void bubble(int* arr, int min_f, int min_l);
void quickSort(int* arr, int down, int up);
int* SumRes(int col, int row, int** array, int* sum_results);
int* sort_index(int col, int* sorted_sum_arr, int* sum_results, int* sorted_index);
int** resultMatrix(int col, int row, int** array, int** result, int* sorted_index);
#endif
