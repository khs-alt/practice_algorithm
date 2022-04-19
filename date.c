#include <stdio.h>
#include <stdlib.h>
//#include <windows.h>

#define MAX_QUEUE_SIZE 100

typedef int element;

typedef struct {
	int front;
	int rear;
	element data[MAX_QUEUE_SIZE];
}Queuetype;

void error(char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}

void init_queue(Queuetype* q) {
	q->front = 0;
	q->rear = 0;
}
is_full(Queuetype* q) {
	return((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}
is_empty(Queuetype* q) {
	return(q->front == q->rear);
}

void enqueue(Queuetype* q, element item) {
	if (is_full(q)) {
		error("큐가 포화상태입니다.\n");
		return;
	}
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}

element dequeue(Queuetype* q) {
	if (is_empty(q)) {
		error("큐가 공백상태입니다.\n");
	}
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}

element peek(Queuetype* q) {
	if (is_empty(q)) {
		error("큐가 공백상태입니다\n");
	}
	else return q->data[(q->front + 1) % MAX_QUEUE_SIZE];
}

void print_queue(Queuetype* q) {
	printf("QUEUE(front=%d rear=%d) = ", q->front, q->rear);
	if (!is_empty(q)) {
		int i = q->front;
		do {
			i = (i + 1) % MAX_QUEUE_SIZE;
			printf("%d | ", q->data[i]);
			if (i == q->rear)
				break;
		} while (i != q->front);
	}
	printf("\n");
}

void date(Queuetype* b, Queuetype* g) {
	element boy_id = 0, girl_id = 0;
	srand(time(NULL));
	int minutes = 60;
	while (minutes != 0) {
		if (rand() % 2 == 0) {
			enqueue(&b, boy_id);
			printf("남자%d 입장", boy_id++);
		}
		else {
			enqueue(&g, girl_id++);
			printf("여자%d 입장", girl_id++);
		}

		if (is_empty(&b) || is_empty(&b)) {
			printf("-대기");
		}
		else {
			printf("\n남자%d 여자%d 매칭", b->data, g->data);
			dequeue(&b);
			dequeue(&g);
		}
		minutes--;
	}
}

int main() {
	Queuetype b;
	Queuetype g;
	init_queue(&b);
	init_queue(&g);
	element boy_id = 0, girl_id = 0;
	srand(time(NULL));
	int minutes = 60;
	while (minutes != 0) {

		if (rand() % 2 == 0) {
			enqueue(&b, boy_id);
			printf("남자%d 입장", boy_id++);
		}
		else {
			enqueue(&g, girl_id);
			printf("여자%d 입장", girl_id++);
		}
		if (is_empty(&b) || is_empty(&b)) {
			printf("-대기\n");
		}
		else {
			printf("\n남자%d 여자%d 매칭\n", dequeue(&b), dequeue(&g));
		}
		printf("현재시각 %d\n",minutes--);
	}

	printf("hello\n");
}