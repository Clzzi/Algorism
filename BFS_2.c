#pragma warning (disable:4996) 
#include <stdio.h>
#define SIZE 8
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
int visited[SIZE + 1];
int queue[10];
int front = 0, back = 0;

void BFS(int startV) {
	visited[startV] = 1;
	queue[back++] = 1;
	int row = 0;
	while (front != back) {
		row = queue[front++];
		for (int i = 1; i <= SIZE; i++) {
			if (map[row][i] == 1 && visited[i] == 0) {
				printf("%d --> %d ", row, i);
				queue[back++] = i;
				visited[i] = 1;
			}
		}
	}
}

int main() {
	int startV = 1;
	BFS(startV);
	printf("\n");
	return 0;
}
