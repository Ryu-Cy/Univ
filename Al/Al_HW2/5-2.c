#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 50

typedef struct graphType {
    int n;
    int adj_mat[MAX_VERTICES][MAX_VERTICES];
}GraphType;

int visited[MAX_VERTICES];      // 방문한 정점 표시
int count;

void init(GraphType* g)
{
    int r, c;
    g->n = 0;
    for (r = 0; r < MAX_VERTICES; r++)
        for (c = 0; c < MAX_VERTICES; c++)
            g->adj_mat[r][c] = 0;

    return;
}

void insert_vertex(GraphType* g, int v)
{
    if (((g->n) + 1) > MAX_VERTICES) {
        fprintf(stderr, "Graph: Too many vertices!");
        return;
    }
    g->n++;

    return;
}

void insert_edge(GraphType* g, int start, int end)
{
    if (start >= g->n || end >= g->n) {
        fprintf(stderr, "Graph: Vertex number error!");
        return;
    }
    g->adj_mat[start][end] = 1;
    g->adj_mat[end][start] = 1;

    return;
}

void delete_edge(GraphType* g, int start, int end)
{
    if (start >= g->n || end >= g->n) {
        fprintf(stderr, "Graph: Vertex number error!");
        return;
    }
    //g->adj_mat[start][end] = 0;
    g->adj_mat[end][start] = 0;

    return;
}

// Depth-first search with adjacency matrix (Using Recursion)
void dfs_mat(GraphType* g, int v)
{
    int w;
    visited[v] = TRUE;
    count++;

    //printf("Vertex %d -> ", v);
    for (w = 0; w < g->n; w++)
        if (g->adj_mat[v][w] && !visited[w])  // 간선이 존재하고 방문하지 않았으면
            dfs_mat(g, w);   // 재귀 호출

    return;
}

void find_bridge(GraphType* g, int u, int v)
{
    int w;
    int r;
    int num = 0;
    int num1 = 0, num2 = 0;

    for (int i = 0; i < MAX_VERTICES; i++)
    {
        visited[i] = FALSE;
        count = 0;
    }

    dfs_mat(g, u);
    
    if (!g->adj_mat[u][v])
    {
        printf("간선아님\n");
        return;
    }

    for (int i = 0; i < MAX_VERTICES; i++)
        num1 = count;
    for (int i = 0; i < MAX_VERTICES; i++)
    {
        visited[i] = FALSE;
        count = 0;
    }
    //printf("\n");

    delete_edge(g, u, v);
    dfs_mat(g, v);

    for (int i = 0; i < MAX_VERTICES; i++)
        num2 = count;

    insert_edge(g, u, v);

    if (num2  == num1)
    {
        printf("브리지아님\n");
        return;
    }
    printf("브리지\n");
    return;
}

int main(void)
{
    GraphType* g;
    g = (GraphType*)malloc(sizeof(GraphType));

    int u, v;

    // 그래프 초기화
    init(g);

    // 정점 삽입
    for (int i = 0; i < 10; i++)
        insert_vertex(g, i);

    // 간선 삽입
    insert_edge(g, 0, 1);
    insert_edge(g, 1, 2);
    insert_edge(g, 1, 3);
    insert_edge(g, 2, 4);
    insert_edge(g, 3, 4);
    insert_edge(g, 3, 5);
    insert_edge(g, 5, 6);
    insert_edge(g, 5, 7);
    insert_edge(g, 6, 7);
    insert_edge(g, 7, 8);
    insert_edge(g, 7, 9);

    //printf("DFS: \n");
    //dfs_mat(g, 0);
    printf("간선(u, v) 입력:\n");

    while (1)
    {
        scanf_s("%d %d", &u, &v);
        find_bridge(g, u, v);
    }

    free(g);

    return 0;
}