#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 50
typedef struct GraphType {
	int n;	// 정점의 개수
	int adj_mat[MAX_VERTICES][MAX_VERTICES];
} GraphType;

// 그래프 초기화 
void init(GraphType* g)
{
	int r, c;
	g->n = 0;
	for (r = 0; r < MAX_VERTICES; r++)
		for (c = 0; c < MAX_VERTICES; c++)
			g->adj_mat[r][c] = 0;
}
// 정점 삽입 연산
void insert_vertex(GraphType* g, int v)
{
	if (((g->n) + 1) > MAX_VERTICES) {
		fprintf(stderr, "그래프: 정점의 개수 초과");
		return;
	}
	g->n++;
}
// 간선 삽입 연산
void insert_edge(GraphType* g, int start, int end)
{
	if (start >= g->n || end >= g->n) {
		fprintf(stderr, "그래프: 정점 번호 오류");
		return;
	}
	g->adj_mat[start][end] = 1;
	//g->adj_mat[end][start] = 1;
}
// 인접 행렬 출력 함수
void print_adj_mat(GraphType* g)
{
	int in[MAX_VERTICES] = { 0 };
	int out[MAX_VERTICES] = { 0 };

	int inLow = 3;
	int inHigh = 0;
	int outLow = 3;
	int outHigh = 0;

	int inL = 0;
	int inH = 0;
	int outL = 0;
	int outH = 0;

	for (int i = 0; i < g->n; i++)
	{
		for (int j = 0; j < g->n; j++)
		{
			in[i] += g->adj_mat[i][j];
			out[i] += g->adj_mat[j][i];
		}
		if (in[i] <= inLow)
		{
			inL = i;
			inLow = in[i];
		}
		if (in[i] > inHigh)
		{
			inH = i;
			inHigh = in[i];
		}
		if (out[i] <= outLow)
		{
			outL = i;
			outLow = out[i];
		}
		if (out[i] > outHigh)
		{
			outH = i;
			outHigh = out[i];
		}
		printf("%d번째 정점\n진입차수: %d\n진출차수: %d\n",
			i, in[i], out[i]);
	}
	printf("진입차수가 가장 낮은 정점: %d,  차수: %d\n", inL, inLow);
	printf("진입차수가 가장 높은 정점: %d,  차수: %d\n", inH, inHigh);
	printf("진출차수가 가장 낮은 정점: %d, 차수: %d\n", outL, outLow);
	printf("진출차수가 가장 높은 정점: %d, 차수: %d\n", outH, outHigh);
}

void print_adj_inMin(GraphType* g)
{
	int in[MAX_VERTICES];

	int count = 0;
	int inMin = 0;

	for (int i = 0; i < g->n; i++)
	{
		for (int j = 0; j < g->n; j++)
		{

		}
	}
}

void main()
{
	GraphType* g;
	g = (GraphType*)malloc(sizeof(GraphType));
	init(g);

	for (int i = 0; i < 6; i++)
		insert_vertex(g, i);

	insert_edge(g, 0, 1);
	insert_edge(g, 0, 2);
	insert_edge(g, 0, 3);
	insert_edge(g, 1, 2);
	insert_edge(g, 1, 3);
	insert_edge(g, 2, 4);
	insert_edge(g, 3, 0);
	insert_edge(g, 3, 4);
	insert_edge(g, 4, 1);
	insert_edge(g, 4, 2);
	insert_edge(g, 5, 4);
	print_adj_mat(g);

	printf("\n");


	free(g);
}