// DS HW3 no.4-2
#include<stdio.h>
#include<stdlib.h>
#include <time.h>


clock_t start, finish;
double duration;


typedef int element;
typedef struct node{
    element data;
    struct node *link;
}Node;

Node *top;

// 메모리 동적 할당을 이용해서 새로운 노드 생성
Node *create_node(element value){

    Node *p = NULL;

    p = (Node *)malloc(sizeof(Node));

    // Error check
    if (p == NULL){
        printf("Memory Allocation Failed!\n");
        exit(1);
    }

    p->data = value;
    p->link = NULL;

    return p;
}

// 리스트의 맨 앞에 value 값의 노드를 생성 후 추가
Node *insert_first(Node *head, element value){
    
    Node *p = create_node(value);

    // 새로 생성된 노드의 링크 값을 리스트 첫번째 노드 주소 값으로 할당
    p->link = head;

    // 새로 생성된 노드의 주소 값으로 head 값을 변경
    head = p;

    return head;
}
Node *insert_last(Node *head, element value)
{
	Node *p = create_node(value);

	if (head == NULL)
	{
		head = p;
		top = p;
	}
	else
	{
		top->link = p;
		top = p;
	}
	return head;
}

// 리스트의 첫번째 노드 삭제
Node *delete_first(Node *head){

    Node *temp = NULL;

    // Check if list is empty
    if (head == NULL){
        printf("List is empty!\n");
        exit(1);
    }

    // 첫번째 노드(즉, 삭제할 노드)의 주소 값을 temp에 저장
    temp = head;

    // head 포인터의 값을 두 번째 노드의 주소값으로 변경
    head = head->link;

    free(temp);

    return head;
}

Node *delete_last(Node * head)
{
	Node *temp = head;

	// Check if list is empty
	if (head == NULL) {
		printf("List is empty!\n");
		exit(1);
	}
	if (temp == top)
	{
		temp = NULL;
	}
	else
	{
		while (temp->link != top)
		{
			temp = temp->link;
		}

		temp->link = NULL;
		top = temp;
	}
	

	return head;
}

void print_list(Node *head){

    Node *temp = head;

    while (temp!=NULL){
        printf("%d -> ", temp->data);
        temp = temp->link;
    }
    printf("NULL\n");

    return;
}

int main(void){

    Node *head = NULL;

	start = clock();
	for (int i = 0; i < 1000000; i++)
	{
		head = insert_last(head, 10);
		//print_list(head);
		head = delete_last(head);
	}
	finish = clock();

	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	printf("%f sec \n", duration);

    return 0;
}