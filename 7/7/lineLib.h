#ifndef lineLib
#define lineLib

void getInt(int* x);
void menu();
void getIntfortask(int* task);
int getSize(char* string);
char* getString();
char* newString(int N1, int N2, char* string, char* string1);
void quickSort(int*& arr, char**& sort, int start, int end);
void copyString(char* argv, char*& string);
void getSizeString(int argc, int*& sizestring, char** strings);
int getSizeword(char* str, char letter);
char* downFirst(char* string);
void printStrings(int argc, char** strings);
void free_strings(char** strings, int argc);


#endif
