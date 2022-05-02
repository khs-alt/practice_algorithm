#include <stdio.h>
#include <stdlib.h>
#include<windows.h>

#define MAX_QUEUE_SIZE 5

typedef struct {
	int id;
	int arrival_time;
	int service_time;
}element;
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

int main(void)
{
	int minutes = 60;
	int total_wait = 0; 
	int total_customers = 0; 
	int service_time1 = 0;
	int service_time2 = 0;
	int service_customer1 = 0, service_customer2 = 0;
	int ser1_empty = 0, ser2_empty = 0;
	Queuetype q;
	init_queue(&q);

	srand(time(NULL));
	for (int clock = 0; clock < minutes; clock++) {
		Sleep(1500);
		printf("����ð� = %d\n", clock);
		if ((rand() % 10) < 3)
		{
			element customer;
			customer.id = total_customers++;
			customer.arrival_time = clock;
			customer.service_time = rand() % 5 + 1;  //�����ð��� ��������  ����
			enqueue(&q, customer);
			printf("�� %d�� %d�п� ���ɴϴ�. �� ����ó���ð�=%d\n", customer.id, customer.arrival_time, customer.service_time);
		}

		if (service_time1 > 0) {
			printf("�� %d�� 1â������ ����ó�����Դϴ�.\n", service_customer1);
			service_time1--;
		}
		else {
			//printf("* = %d\n", !is_empty(&q));
			if (!is_empty(&q)) {
				element customer = dequeue(&q);
				service_customer1 = customer.id;
				service_time1 = customer.service_time;
				printf("�� %d�� %d�п� ������ �����մϴ�. ���ð��� %d���̾����ϴ�/\n",
					customer.id, clock, clock - customer.arrival_time);
				total_wait += clock - customer.arrival_time;
			}
		}

		if (service_time2 > 0) {
			printf("�� %d�� 2â������ ����ó�����Դϴ�.\n", service_customer2);
			service_time2--;
		}
		else {
			if (!is_empty(&q)) {
				element customer = dequeue(&q);
				service_customer2 = customer.id;
				service_time2 = customer.service_time;
				printf("�� %d�� %d�п� ������ �����մϴ�. ���ð��� %d���̾����ϴ�/\n",
					customer.id, clock, clock - customer.arrival_time);
				total_wait += clock - customer.arrival_time;
			}
		}
	}
	printf("��ü ��� �ð�=%d�� \n", total_wait);
	return 0;
}

