#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TRUE 1
#define FALSE 0
#define MAX_STACK_SIZE 100

typedef char element;
typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
} StackType;



// ���� �ʱ�ȭ �Լ�
void init_stack(StackType *s)
{
	s->top = -1;
}

// ���� ���� ���� �Լ�
int is_empty(StackType *s)
{
	return (s->top == -1);
}

// ��ȭ ���� ���� �Լ�
int is_full(StackType *s)
{
	return (s->top == (MAX_STACK_SIZE - 1));
}

// �����Լ�
void push(StackType *s, element item)
{
	if (is_full(s)) {
		fprintf(stderr, "���� ��ȭ ����\n");
		return;
	}
	else s->data[++(s->top)] = item;
}

// �����Լ�
element pop(StackType *s)
{
	if (is_empty(s)) {
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else return s->data[(s->top)--];
}

// ��ũ�Լ�
element peek(StackType *s)
{
	if (is_empty(s)) {
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else return s->data[s->top];
}

// ===== ���� �ڵ��� �� =====


int check_matching(const char *in)
{
	StackType s;
	char ch, open_ch;
	int i, n = strlen(in);
	int num1 = 0, num2 = 0;
	int *tmp;// n= ���ڿ��� ����
	tmp = (int *)malloc(sizeof(int) * n);

	for (i = 0; i < n; i++) {
		if (in[i] == '(') {
			tmp[i] = ++num1;
			num2 = num1;
		}
		else if (in[i] == ')') {
			tmp[i] = num2--;
		}
	}
}


void string_compression(const char *in) {
	StackType s;
	char ch;
	int i, n = strlen(in);
	init_stack(&s);
	for (i = 0; i < n; i++) {
		ch = in[i];
		push(&s, ch);
		if (peek(&s) != in[i+1] && is_empty != TRUE) {
			printf("%d%c",s.top+1, peek(&s));
			init_stack(&s);
		}
	}
}

void chack_letter(const char *in) {
	StackType s;
	char ch, open_ch;
	int i, n = strlen(in);
	init_stack(&s);
	for (i = 0; i < n; i++) {
			ch = in[i];
			if (ch >= 'a' && ch <= 'z') {
				push(&s, ch);

			}
		}
}

char tmp(char *input, int count) {
	while (input[count]) {
		if (isupper(input[count])) {
			input[count] = tolower(input[count]);
		}
		count++;
	}
}

int main() {
	char *p = "aaaabbbc";
	tmp(p, strlen(p));
	string_compression(p);

	return 0;
}