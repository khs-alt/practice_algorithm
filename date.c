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
		error("ť�� ��ȭ�����Դϴ�.\n");
		return;
	}
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}

element dequeue(Queuetype* q) {
	if (is_empty(q)) {
		error("ť�� ��������Դϴ�.\n");
	}
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}

element peek(Queuetype* q) {
	if (is_empty(q)) {
		error("ť�� ��������Դϴ�\n");
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
			printf("����%d ����", boy_id++);
		}
		else {
			enqueue(&g, girl_id++);
			printf("����%d ����", girl_id++);
		}

		if (is_empty(&b) || is_empty(&b)) {
			printf("-���");
		}
		else {
			printf("\n����%d ����%d ��Ī", b->data, g->data);
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
			printf("����%d ����", boy_id++);
		}
		else {
			enqueue(&g, girl_id);
			printf("����%d ����", girl_id++);
		}
		if (is_empty(&b) || is_empty(&b)) {
			printf("-���\n");
		}
		else {
			printf("\n����%d ����%d ��Ī\n", dequeue(&b), dequeue(&g));
		}
		printf("����ð� %d\n",minutes--);
	}

	printf("hello\n");
}