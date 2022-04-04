#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STACK_SIZE 100

typedef char element;
typedef struct {
	element *data;
	int capacity;
	int top;
}StackType;

void init_stack(StackType *s) {
	s->top = -1;
	s->capacity = 1;
	s->data = (element *)malloc(s->capacity * sizeof(element));
}

int check_matching(const char *in) {
	StackType s;
	char ch, open_ch;
	int i, n = strlen(in);
	init_stack(&s);
}