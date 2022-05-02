#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAZE_SIZE 10
#define max_stack_size 100
int i = 0;
short a, b;

typedef struct {
	short r;
	short c;
	int s;//방문여부 했으면 1 안했으면 0
} element;

typedef struct {
	element data[max_stack_size];
	int top;
}stacktype;

void init_stack(stacktype* s) {
	s->top = -1;
	s->data->s = 0;
	//s->capacity = 1;
	//s->data = (element*)malloc(s->capacity * sizeof(element));
}

int is_empty(stacktype* s) {
	return (s->top == -1);
}

int is_full(stacktype* s) {
	return (s->top == (max_stack_size - 1));
}

void push(stacktype* s, element item) {
	if (is_full(s)) {
		fprintf(stderr, "stack overflow error\n");
		return;
	}
	else s->data[++(s->top)] = item;
}

element pop(stacktype* s) {
	if (is_empty(s)) {
		fprintf(stderr, "stack blank error\n");
		exit(1);
	}
	else return s->data[(s->top)--];
}

element peek(stacktype* s) {
	if (is_empty(s)) {
		fprintf(stderr, "stack blank error\n");
		exit(1);
	}
	else return s->data[s->top];
}

element here = { 1,0,1 }, entry = { 1,0,1 };

char maze[MAZE_SIZE][MAZE_SIZE] = {
{'1','1','1','1','1','1','1','1','1','1'},
{'e','0','1','0','0','1','1','1','1','1'},
{'1','0','1','0','1','1','1','1','1','1'},
{'1','0','1','0','1','1','1','1','1','1'},
{'1','0','0','0','0','0','1','1','1','1'},
{'1','0','1','1','1','1','1','0','0','x'},
{'1','0','1','0','1','1','1','0','1','1'},
{'1','0','1','0','1','1','1','0','1','1'},
{'1','0','0','0','0','0','0','0','1','1'},
{'1','1','1','1','1','1','1','1','1','1'},
};

void push_loc(stacktype* s, int r, int c) {

	if (r < 0 || c < 0)return;
	if (maze[r][c] != '1' && maze[r][c] != '.') {
		element tmp;
		tmp.r = r;
		tmp.c = c;
		tmp.s = 0;
		push(s, tmp);
		//printf("%d번이동", ++i);
	}
}

void maze_print(char maze[MAZE_SIZE][MAZE_SIZE]) {
	printf("\n");
	for (int r = 0; r < MAZE_SIZE; r++) {
		for (int c = 0; c < MAZE_SIZE; c++) {

			switch (maze[r][c]) {
			case '0': {
				printf("□");
				break;
			}
			case '1': {
				printf("■");
				break;
			}
			case 'e': {
				printf("※");
				break;
			}
			case 'x': {
				printf("☆");
				break;
			}
			case '.': {
				printf("＠");
				break;

			}
			default:
				break;
			}
		}
		printf("\n");
	}
}

void clear_map() {
	for (int r = 0; r < MAZE_SIZE; r++) {
		for (int c = 0; c < MAZE_SIZE; c++) {
			if (maze[r][c] == '.')
				maze[r][c] = '0';
		}
	}
}

int main(void) {
	int tmp1[100] = { 0 };
	int tmp2[100] = { 0 };
	int i = 0;
	int r, c;
	int is_success = 0;
	stacktype s;
	element tmp;
	init_stack(&s);
	here = entry;

	while (maze[here.r][here.c] != 'x') {
		r = here.r;
		c = here.c;
		maze[r][c] = '.';
		maze_print(maze);
		push_loc(&s, r - 1, c);//왼쪽
		push_loc(&s, r + 1, c);//오른쪽
		push_loc(&s, r, c - 1);//아래
		push_loc(&s, r, c + 1);//위

		if (is_empty(&s)) {
			printf("실패\n");
			return 0;
		}
		else if (peek(&s).s == 0) {
			tmp.c = peek(&s).c;
			tmp.r = peek(&s).r;
			here = pop(&s);
			tmp.s = 1;
			push(&s, tmp);
		}
		else if (peek(&s).s == 1) {
			while (peek(&s).s == 1) {
				here = pop(&s);
			}
		}
		else {
			printf("심각한 오류 발생\n");
			return 0;
		}
	}
	if (is_empty(&s)) {
		printf("실패\n");
		return 0;
	}
	printf("성공\n");
	is_success = 1;
	while (!is_empty(&s)) {
		here = pop(&s);
		if (here.s == 1) {
			a = here.c;
			b = here.r;
			tmp1[i] = here.c;
			tmp2[i] = here.r;
			i++;
			//printf("%d %d\n", here.c + 1, here.r + 1);
		}
	}
			while (i != 0) {
		printf("(%d, %d)\n", tmp1[i] + 1, tmp2[i] + 1);
			i--;
		}
}