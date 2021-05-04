#pragma warning(disable:4996)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUEUE_SIZE 100

typedef char element;
typedef struct {
	element data[MAX_QUEUE_SIZE];
	int front, rear;
} DequeType;
void init_deque(DequeType* q)
{
	q->front = q->rear = 0;
}
int is_empty(DequeType* q)
{
	return (q->front == q->rear);
}
int is_full(DequeType* q)
{
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}
void add_rear(DequeType* q, element item)
{
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}
element delete_front(DequeType* q)
{
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}
element get_front(DequeType* q)
{
	return q-> data[(q->front + 1) % MAX_QUEUE_SIZE];
}
void add_front(DequeType* q, element item)
{
	q->data[q->front] = item;
	q->front = (q->front - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
}
element delete_rear(DequeType* q)
{
	int prev = q->rear;
	q->rear = (q->rear - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
	return q->data[prev];
}
element get_rear(DequeType* q)
{
	return q->data[q->rear];
}
void palindrome(const char in[]) {
	DequeType q;

	char ch, ch_check;
	int n = strlen(in);

	init_deque(&q);

	for (int i = 0; i < n; i++) {
		ch = in[i];
		if (ch == ' ' || ch == ',' || ch == '.') {
			continue;
		}
		add_rear(&q, ch);
	}
	for (int i = 0; i < n; i++) {
		ch = in[i];
		if (ch == ' ' || ch == ',' || ch == '.') {
			continue;
		}
		ch_check = get_rear(&q);
		delete_rear(&q);
		if (ch != ch_check) {
			printf("회문이 아닙니다.\n");	
			return;
		}
	}
	if (!is_empty(&q)) {
		return;
	}
	printf("회문입니다. \n");
	return;
}

int main()
{
	printf("Al_HW1_1\n");
	char c[MAX_QUEUE_SIZE];

	scanf("%[^\n]", c);
	for (int i = 0; i < strlen(c); i++)
	{
		if ((c[i] >= 'a') && (c[i] <= 'z'))
		{
			c[i] = c[i] - 'a' + 'A';
		}
	}
	palindrome(c);

	return 0;
}