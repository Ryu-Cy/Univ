// 자료구조 HW3 no.1
#include<stdio.h>
#include<stdlib.h>

#define MAX_STACK_SIZE 100
#define TRUE 1
#define FALSE 0

typedef char element;
typedef struct stacktype {
	element data[MAX_STACK_SIZE];
	int top;
}StackType;

void init_stack(StackType *s)
{
	s->top = -1;
}

int is_empty(StackType *s)
{
	if (s->top == -1)
		return TRUE;
	else
		return FALSE;
}

int is_full(StackType *s)
{
	if (s->top == (MAX_STACK_SIZE - 1))
		return TRUE;
	else
		return FALSE;
}

void push(StackType *s, element item)
{
	if (is_full(s)) {
		fprintf(stderr, "Stack is full!\n");
		return;
	}
	else {
		(s->top)++;
		s->data[s->top] = item;
		//printf("%c", item);
	}
}

element pop(StackType *s)
{
	element temp;

	if (is_empty(s)) {
		fprintf(stderr, "Stack is empty!\n");
		exit(1);
	}

	else {
		temp = s->data[s->top];
		(s->top)--;
		//printf("Item %c is popped\n", temp);
		return temp;
	}
}

int main(void)
{
	StackType s;

	init_stack(&s);

	int set;
	int len;
	int len2 = 0;
	char strInput[50];
	char strOutput[50] = { 0 };
	
	scanf("%d", &set);

	for (int i = 0;  i < set;  i++)
	{
		scanf("%s", strInput);

		for (int j = 0; strInput[j] != NULL; j++)
		{
			push(&s, strInput[j]);
		}
		len = strlen(strInput);
		for (int k = len2; k < len + len2; k++)
		{
			strOutput[k] = pop(&s);
		}
		strOutput[len + len2] = '\n';
		len2 = (len * (i + 1)) + 1 + i;
	}
	printf("------------------------------\n");
	printf("%d\n", set);
	printf("%s", strOutput);

	return 0;
}

