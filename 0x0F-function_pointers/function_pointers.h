#ifndef _FUNCTION_POINTERS_
#define _FUNCTION_POINTERS_

void print_name(char *, void(*)(char *));
void array_iterator(int *, size_t, void(*)(int));
int int_index(int *, int, int(*)(int));

#endif
