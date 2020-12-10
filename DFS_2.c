// 인접 행렬
#pragma warning (disable:4996)
#include <stdio.h>
int n;
int map[31][31];
int visited[31];

void DFS(int v) {
	visited[v] = 1;
	for (int i = 1; i <= n; i++) {
		if (map[v][i] == 1 && !visited[i]) {
			// 정점v와 i가 연결되어 있고 , i를 방문하지 않았다면
			printf("%d --> %d\n",v,i);
			DFS(i);
		}
	}
}

int main() {
	int startV = 0;
	int v1 = 0;
	int v2 = 0;
	printf("Vertex 개수 : ");
	scanf("%d", &n);
	printf("시작 노드 : ");
	scanf("%d", &startV);
	while (1) {
		scanf("%d%d", &v1, &v2);
		if (v1 == -1 && v2 == -1) // 탈출조건
			break;
		map[v1][v2] = map[v2][v1] = 1; // 대각선으로 잘랐을때 같은거
	}
	DFS(startV);
	return 0;
}
