// DS HW3 no.4
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_STACK_SIZE 100	        // 스택의 최대 크기
#define TRUE 1
#define FALSE 0

clock_t start, finish;
double duration;

typedef int element;		        // 데이터의 자료형
element  stack[MAX_STACK_SIZE];     // 1차원 배열


int  top = -1;                      // 전역변수 선언			

// 공백 상태 검출 
int is_empty()
{
	if (top == -1)
		return TRUE;
	else
		return FALSE;
}

// 포화 상태 검출 
int is_full()
{
	if (top == MAX_STACK_SIZE - 1)
		return TRUE;
	else
		return FALSE;
}

// 아이템 추가 
void push(element item)
{
	if (is_full()) {
		fprintf(stderr, "Stack is full!!\n");
		exit(1);
	}
	else {
		top++;
		stack[top] = item;
		//printf("Item %d is pushed.\n", item);
	}

	return;
}

// 아이템 삭제 
element pop()
{
	element temp;

	if (is_empty()) {
		fprintf(stderr, "Stack is empty!!\n");
		exit(1);
	}
	else {
		temp = stack[top];
		top--;
		//printf("Item %d is popped.\n", temp);
		return temp;
	}
}

int main(void)
{
	start = clock();
	for (int i = 0; i < 1000000; i++)
	{
		push(1);
		pop();
	}
	finish = clock();

	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	printf("%f sec \n", duration);

	return 0;
}