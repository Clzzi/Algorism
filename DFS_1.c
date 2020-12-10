#pragma warning (disable:4996)
#include<stdio.h>
#define SIZE 8 // �ִ� ������ 8,

int map[SIZE + 1][SIZE + 1] = { // [9][9]�� 2���� �迭 ����
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

int visited[SIZE + 1]; //�湮������ �ǹ��ϴ� visited �迭�� [9]���� ����

void DFS(int v) { // DFS�Լ� v�� ���۳��, visited[v] = 1�� visited�迭�� v��° �ε����� �湮������ �ǹ���
	visited[v] = 1;

	for (int j = 1; j <= SIZE; j++) { // 1 ���� size���� for������
		if (map[v][j] == 1 && !visited[j]) { // map[���۳��][j] �� 1�̸鼭 visited[j]�� 0�̶�� ��� ���ְ� DFS�Լ� ���� - ���
			printf("%d --> %d�� �̵�\n", v, j);
			DFS(j);
		}
	}
}

int main() {
	DFS(1); // ���۳��� 1���� ����
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