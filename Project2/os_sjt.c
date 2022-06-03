#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>
#define MAX_QUEUE_SIZE 100
#define SIZE 5

typedef struct element {
    int process_id;
    int arrival_time;
    int service_time;
    int waiting_time;
    int turnaround_time;
}element;
typedef struct Node //노드 정의
{
    element data;
    struct Node* next;
}Node;
typedef struct Queue //Queue 구조체 정의
{
    Node* front; //맨 앞(꺼낼 위치)
    Node* rear; //맨 뒤(보관할 위치)
    int count;//보관 개수
}Queue;
void initQueue(Queue* queue)
{
    queue->front = queue->rear = NULL; //front와 rear를 NULL로 설정
    queue->count = 0;//보관 개수를 0으로 설정
}
void error(char* message)
{
    fprintf(stderr, "%s\n", message);
    exit(1);
}
int IsEmpty(Queue* queue)
{
    return queue->count == 0;    //보관 개수가 0이면 빈 상태
}
void enqueue(Queue* queue, element data)
{
    Node* now = (Node*)malloc(sizeof(Node)); //노드 생성
    now->data = data;//데이터 설정
    now->next = NULL;

    if (IsEmpty(queue))//큐가 비어있을 때
    {
        queue->front = now;//맨 앞을 now로 설정       
    }
    else//비어있지 않을 때
    {
        queue->rear->next = now;//맨 뒤의 다음을 now로 설정
    }
    queue->rear = now;//맨 뒤를 now로 설정   
    queue->count++;//보관 개수를 1 증가
}

element dequeue(Queue* queue)
{
    element re = {0};
    Node* now;
    if (IsEmpty(queue))//큐가 비었을 때
    {
        return re;
    }
    now = queue->front;//맨 앞의 노드를 now에 기억
    re = now->data;//반환할 값은 now의 data로 설정
    queue->front = now->next;//맨 앞은 now의 다음 노드로 설정
    free(now);//now 소멸
    queue->count--;//보관 개수를 1 감소
    return re;
}

int main() {
    element pid[SIZE] = { 0 };
    int i = 0;
    FILE* fp;
    fp = fopen("process_list_5.txt", "r");
    int size = 0;
    fflush(stdin);
    fscanf(fp, "%d", &size);
    printf("size = %d\n", size);
    while (!feof(fp)) {
        fscanf(fp, "%d", &pid[i].process_id);
        fscanf(fp, "%d", &pid[i].arrival_time);
        fscanf(fp, "%d", &pid[i].service_time);
        i++;
    }
    int time = 0;
    int wait_s = 0;
    int wait_e = 0;
    int end_t = 1;
    int c = 0;
    int cpu = 0;
    int cpu_idle = 0;
    int t_tur = 0;
    int t_wait = 0;
    int t_res = 0;
    Queue q;
    initQueue(&q);
    //enqueue(&q, pid[0]);
    element tmp = { 0 };
    fflush(stdout);
    for (int t = 0; t < 1000000; t++) {
        if (pid[c].arrival_time == t) {
            pid[c].waiting_time = t;
            enqueue(&q, pid[c]);

            printf("[%d]PID(%d):Not-Running\n", t, c);
            c++;
        }
        if (cpu == 0 && IsEmpty(&q) == true)
            cpu_idle++;

        if (cpu == 0 && IsEmpty(&q) == false) {
            tmp = dequeue(&q);
            end_t = t + tmp.service_time;
            cpu = 1;
            pid[c].turnaround_time = t;

            printf("[%d]PID(%d):Running\n", t, c);
        }
        if (end_t == t) {

            cpu = 0;
            pid[tmp.process_id].turnaround_time = t - pid[tmp.process_id].arrival_time;
            printf("[%d]PID(%d):Eixt\n", t, tmp.process_id);
        }
        if (cpu == 0 && IsEmpty(&q) == false) {
            tmp = dequeue(&q);
            end_t = t + tmp.service_time;
            pid[c].waiting_time = t - pid[c].waiting_time;
            cpu = 1;
            pid[c].turnaround_time = t;
            // W[tmp.process_id] = pid[c].turnaround_time - pid[c].arrival_time;
            printf("[%d]PID(%d):Running\n", t, c);
        }
    }
    printf("Log of Process Scheduling\n");
    int temp;
    int wait = 0;
    int j, k = 0;
    for (i = 0; i < size; i++) {
        temp = 0;
        for (j = k; j < i; j++) {
            temp = temp + pid[j].service_time;
        }
        wait = temp - pid[i].arrival_time + pid[k].arrival_time;

        if (wait <= 0) {
            k = i;
            pid[i].waiting_time = 0;
            pid[i].turnaround_time = pid[i].service_time + pid[i].waiting_time;
        }
        else {
            pid[i].waiting_time = wait;
            pid[i].turnaround_time = pid[i].service_time + pid[i].waiting_time;
        }
    }

    for (int i = 0; i < size; i++) {
        printf("PID(%d)	Turnaround Time: %d	Waiting Time : %d	Response Time : %d\n", pid[i].process_id, pid[i].turnaround_time, pid[i].waiting_time, pid[i].waiting_time);
        t_tur += pid[i].turnaround_time;
        t_res += pid[i].waiting_time;
        t_wait += pid[i].waiting_time;
    }

    printf("\nAverage Turnaround Time: %.2f\n", (double)t_tur / SIZE);
    printf("Average Waiting  Time: %.2f\n", (double)t_wait / SIZE);
    printf("Average Response  Time: %.2f\n", (double)t_res / SIZE);
    fclose(fp);

}