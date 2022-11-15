#ifndef arrays
#define arrays

void raz(int* x);
void printArray(int* x, int* y);
int* rem_element(int* arr, int pos, int size);
int** init_matrix(int x);
void print_matrix(int row, int col, int **arr);
int* rem_element_matrix(int* arr, int pos, int size);
int* write_num(int number, int* size);
int** init_matrix_2x2(int x);
void paste_2x2(int** arr, int razmer, int random);
int** down(int** arr, int razmer);
int** up(int** arr, int razmer);
int** right(int** arr, int razmer);
int** left(int** arr, int razmer);
int random();
void rand_elem(int* arr, int razmer);
void rand_gen_raz(int* razmer);
int** search_low(int** arr, int razmer, int low, int num);
void write_side(int* pos);
void elem_write(int element, int razmer, int* arr);
void print_low(int row, int** arr);
#endif
