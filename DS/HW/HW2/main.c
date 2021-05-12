#pragma warning(disable:4996)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 100
#define TRUE 1
#define FALSE 0

// 1st
int recursive(int n) {
	printf("%d\n", n);
	if (n < 1)
		return 2;
	else
		return(2 * recursive(n - 1) + 1);
}
// 2st
void asterisk(int i) {
	if (i > 1) {
		asterisk(i / 2);
		asterisk(i / 2);
	}
	printf("*");
}
// 3st
unkown() {
	int ch;
	if ((ch = getchar()) != '\n')
		unkown();
	putchar(ch);
}
// 4st
int a(float x, float y) {
	if (x > 0) {
		y += (1 / x);
		return a(x - 1, y);
	}
	printf("%.2f", y);
}
// 5st
void sum(int n) {
	int a = 0;
	for (int i = n; i > 0; i--) {
		a += i;
	}
	printf("%d", a);
}
// 7 - 8st
// 아직 스택을 사용하는게 서툴러 교수님이 올려주셨던 코드를 참고하였습니다.
typedef char element;
typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
} StackType;
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
		//printf("Item %c is pushed\n", item);
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
		// printf("Item %c is popped\n", temp);        
		return temp;
	}
}
element peek(StackType *s)
{
	if (is_empty(s)) {
		fprintf(stderr, "Stack is empty!!\n");
		exit(1);
	}
	else return s->data[s->top];
}
// 7st
int check(const char *in) {
	StackType s;
	char ch, open_ch;
	int n = strlen(in);
	
	int a = 0, b = 0;
	int num[MAX_STACK_SIZE] = { 0 };

	int x = 0, y = 0;

	init_stack(&s);

	for (int i = 0; i < n; i++) {
		ch = in[i];
		switch (ch) {
		case '(':
			x += 1;
			push(&s, x);
			/*b += 1;
			num[a] = b;
			printf("%d", num[a]);
			a += 1;*/
			
			printf("%d", x);
			break;

		case ')':
			if (is_empty(&s)) {
				return FALSE;
			}
			else {
				y = pop(&s);
				printf("%d", y);
				/*a -= 1;
				printf("%d", num[a]);*/
				
				/*if (open_ch == '(' && ch != ')') {
					return FALSE;
				}*/
				break;
			}
		}
	}
	if (!is_empty(&s)) {
		return FALSE;
	}
	return TRUE;
}
// 8st ' 도 해보려 했으나 '를 입력받지 못하고 ''형식으로 변환되어 '''가 되지 않습니다
void palindrome(const char in[]) {
	StackType s;

	char ch, ch_check;
	int n = strlen(in);

	init_stack(&s);
	
	for (int i = 0; i < n; i++) {
		ch = in[i];
		if (ch == ' ' || ch == ',' || ch == '.') {
			continue;
		}
		push(&s, ch);
	}
	for (int i = 0; i < n; i++) {
		ch = in[i];
		if (ch == ' ' || ch == ',' || ch == '.') {
			continue;
		}
		ch_check = pop(&s);
		if (ch != ch_check) {
			printf("회문이 아닙니다.\n");
			return;
		}
	}
	if (!is_empty(&s)) {
		return;
	}
	printf("회문입니다. \n");
	return;
}


int main() {

	// 1st
	printf("1번 문제\n");
	recursive(5);
	printf("\n\n");

	// 2st
	printf("2번 문제\n");
	asterisk(5);
	printf("\n\n");

	// 3st
	printf("3번 문제\n");
	unkown();
	printf("\n\n");

	// 4st
	printf("4번 문제\n");
	a(10, 0);
	printf("\n\n");

	// 5st
	printf("5번 문제\n");
	sum(10);
	printf("\n\n");

	// 7st
	printf("7번 문제\n");
	char *p = "((())(()))";
	char *t = "((((()";

	printf("%s\n", p);
	check(p);
	printf("\n");

	printf("%s\n", t);
	check(t);
	printf("\n\n");

	// 8st
	printf("8번 문제\n");
	char c[MAX_STACK_SIZE];

	scanf("%[^\n]", c);
	palindrome(c);

	return 0;
}