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
	visited[1] = 1; // ���� ��忡 �湮������ ������
	queue[back++] = 1; // ť�� 0�� 1�ְ� back++
	int row;
	while (front != back) { // ť�� �հ� �ڰ� ������ ����
		row = queue[front++]; // row�� ť�� 0���� �־���
		for (int i = 1; i <= SIZE; i++) { // size��ŭ �ݺ���
			if (map[row][i] == 1 && visited[i] == 0) { // ��������� [���۳��][i]�� 1�̸鼭 �湮���� �ʾҴٸ� ��� �� ť�� 1�� i�� �ְ� ++ , �湮�����ֱ�
				printf("%d --> %d ", row, i);
				queue[back++] = i;
				visited[i] = 1;
			}
		}
	}
	printf("\n");
}

