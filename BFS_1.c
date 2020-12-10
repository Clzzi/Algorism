#include<stdio.h>
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
int front = 0, back = 0;
int queue[100] = { 0, };

int main() {
	visited[1] = 1; // 시작 노드에 방문했음을 적어줌
	queue[back++] = 1; // 큐의 0에 1넣고 back++
	int row;
	while (front != back) { // 큐의 앞과 뒤가 만날때 까지
		row = queue[front++]; // row에 큐의 0부터 넣어줌
		for (int i = 1; i <= SIZE; i++) { // size만큼 반복문
			if (map[row][i] == 1 && visited[i] == 0) { // 인접행렬의 [시작노드][i]가 1이면서 방문하지 않았다면 출력 및 큐의 1에 i를 넣고 ++ , 방문했음넣기
				printf("%d --> %d ", row, i);
				queue[back++] = i;
				visited[i] = 1;
			}
		}
	}
	printf("\n");
}

