#include <stdio.h>

int map[1001][1001], dfs[1001];

void init(int *, int size);

void DFS(int v, int N) {

	dfs[v] = 1;
	printf("%d ", v);

	for (int i = 1; i <= N; i++) {
		if (map[v][i] == 1 && dfs[i] == 0) {
			DFS(i, N);
		}
	}

}

int main(void) {

	init(map, sizeof(map) / 4);
	init(dfs, sizeof(dfs) / 4);

	int N, M, V;
	scanf("%d%d%d", &N, &M, &V);

	for (int i = 0; i < M; i++)
	{
		int start, end;
		scanf("%d%d", &start, &end);
		map[start][end] = 1;
		map[end][start] = 1;
	}

	DFS(V, N);

	return 0;
}

void init(int *arr, int size) {
	for (int i = 0; i < size; i++)
	{
		arr[i] = 0;
	}
}
