#ifndef arrays
#define arrays

void raz(int* x);
void element(int* x);
void PrintArray(int* x, int* y);
int* rem_element(int* arr, int pos, int size);
int** init_matrix(int x);
void print_matrix(int row, int col, int **arr);
int* rem_element_matrix(int* arr, int pos, int size);
int* write_until_number(int number, int* size);
int** init_matrix_2x2(int x);
void paste_2x2(int** arr, int razmer, int random);
int** down(int** arr, int razmer);
int** up(int** arr, int razmer);
int** right(int** arr, int razmer);
int** left(int** arr, int razmer);

#endif