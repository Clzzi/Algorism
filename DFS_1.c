#pragma warning (disable:4996)
#include<stdio.h>
#define SIZE 8 // 최대 사이즈 8,

int map[SIZE + 1][SIZE + 1] = { // [9][9]인 2차원 배열 생성
	{0,0,0,0,0,0,0,0,0},
	{0,0,1,0,0,0,0,0,0},
	{0,1,0,1,1,0,0,0,0},
	{0,0,1,0,0,0,0,1,0},
	{0,0,1,0,0,1,0,0,0},
	{0,0,0,0,1,0,1,0,0},
	{0,0,0,0,0,1,0,1,1},
	{0,0,0,1,0,0,1,0,1},
	{0,0,0,0,0,0,1,1,0}
};

int visited[SIZE + 1]; //방문했음을 의미하는 visited 배열을 [9]까지 생성

void DFS(int v) { // DFS함수 v는 시작노드, visited[v] = 1은 visited배열의 v번째 인덱스에 방문했음을 의미함
	visited[v] = 1;

	for (int j = 1; j <= SIZE; j++) { // 1 부터 size까지 for문돌림
		if (map[v][j] == 1 && !visited[j]) { // map[시작노드][j] 가 1이면서 visited[j]가 0이라면 출력 해주고 DFS함수 실행 - 재귀
			printf("%d --> %d로 이동\n", v, j);
			DFS(j);
		}
	}
}

int main() {
	DFS(1); // 시작노드는 1부터 했음
	printf("\n");
	return 0;
}















#pragma warning (disable:4996)
#include <stdio.h>
#define SIZE 30

int map[SIZE + 1][SIZE + 1] = {
	{0,0,0,0,0,0,0,0,0},
	{0,0,1,0,0,0,0,0,0},
	{0,1,0,1,1,0,0,0,0},
	{0,0,1,0,0,0,0,1,0},
	{0,0,1,0,0,1,0,0,0},
	{0,0,0,0,1,0,1,0,0},
	{0,0,0,0,0,1,0,1,1},
	{0,0,0,1,0,0,1,0,1},
	{0,0,0,0,0,0,1,1,0}
};

int visited[SIZE + 1] = { 0, };
int v = 1;

void DFS(int v) {
	visited[v] = 1;
	for (int i = 1; i <= SIZE; i++) {
		if (map[v][i] == 1 && visited[i] == 0) {
			printf("%d --> %d", v, i);
			DFS(i);
		}
	}
}

int main() {
	int v = 0;
	scanf("%d", &v);
	BFS(v);
	printf("\n");
	return 0;
}