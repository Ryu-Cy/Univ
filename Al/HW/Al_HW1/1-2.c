#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

// ===== 원형큐 코드 시작 ======
#define MAX_QUEUE_SIZE 7
typedef char element;
typedef struct { // 큐 타입
	element* data[MAX_QUEUE_SIZE];
	int  front, rear;
} QueueType;

// 오류 함수
//void error(char *message)
//{
//	fprintf(stderr, "%s\n", message);
//	exit(1);
//}

// 공백 상태 검출 함수
void init_queue(QueueType *q)
{
	q->front = q->rear = 0;
}

// 공백 상태 검출 함수
int is_empty(QueueType *q)
{
	return (q->front == q->rear);
}

// 포화 상태 검출 함수
int is_full(QueueType *q)
{
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

// 원형큐 출력 함수
void queue_print(QueueType *q)
{
	//printf("QUEUE(front=%s rear=%c) = ", q->front, q->rear);
	if (!is_empty(q)) {
			int i = q->front;
			do {
				i = (i + 1) % (MAX_QUEUE_SIZE);
				printf("%s | ", q->data[i]);
				if (i == q->rear)
					break;
			} while (i != q->front);
		}
	printf("\n");
}

// 삽입 함수
void enqueue(QueueType *q, element* item)
{
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}

// 삭제 함수
element* dequeue(QueueType *q)
{
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}

// 삭제 함수
element* peek(QueueType *q)
{
	return q->data[(q->front + 1) % MAX_QUEUE_SIZE];
}
// ===== 원형큐 코드 끝 ======

void hotPotato(QueueType* q, int num)
{
	QueueType tempQ;
	char* temp;
	int a = MAX_QUEUE_SIZE;
	for (int i = 0; i < num; i++)
	{
		temp = peek(q);
		dequeue(q);
		enqueue(q, temp);
		queue_print(q);
		if ((i == num - 1) && (a > 2))
		{
			enqueue(&tempQ, peek(q));
			dequeue(q);
			a--;
			i = 0;
		}
	}
	printf("\n아웃 된 플레이어 명단\n");
	queue_print(&tempQ);
	printf("\n마지막 남은 플레이어: ");
	queue_print(q);
}

int main(void)
{
	QueueType queue;
	int a = 0;

	printf("Num: ");
	scanf("%d", &a);

	init_queue(&queue);

	enqueue(&queue, "Brad");
	enqueue(&queue, "Kent");
	enqueue(&queue, "Jane");
	enqueue(&queue, "Susan");
	enqueue(&queue, "David");
	enqueue(&queue, "Bill");
	
	hotPotato(&queue, a);

	return 0;
}