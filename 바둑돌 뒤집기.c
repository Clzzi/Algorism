/*
0 0 0 1 0 1 0 0 0 0
0 0 0 1 0 1 0 0 0 0
0 0 0 1 0 1 0 0 0 0
1 1 1 1 1 1 1 1 1 1
0 0 0 1 1 1 0 0 0 0
1 1 1 1 1 1 1 1 1 1
0 0 0 1 0 1 0 0 0 0
0 0 0 1 0 1 0 0 0 0
0 0 0 1 0 1 0 0 0 0
0 0 0 1 0 1 0 0 0 0
2
( 4 , 4 )
( 6 , 6 )	*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define Y 10 // vertical, Y
#define X 10 // horizontal, X

int main() {
	int a[Y + 1][X + 1], i, x, y, j, n;
	for (i = 1; i <= Y; i++)
		for (j = 1; j <= X; j++)
			scanf("%d", &a[i][j]);
	printf("\n");
	// 바둑판 0과1 받기

	scanf("%d", &n); // 몇쌍을 입력받을지 입력받는것

	for (i = 1; i <= n; i++) {
		scanf("%d%d", &x, &y); // 뒤집을 바둑판 좌표 입력받기

		// Y축 고정 코드
		for (j = 1; j <= X; j++)
			if (a[y][j] == 0) // y축 고정
				a[y][j] = 1; // 흑돌을 휜돌로
			else
				a[y][j] = 0; // 휜돌을 흑돌로

		// X축 고정 코드
		for (j = 1; j <= Y; j++)
			if (a[j][x] == 0) // x축 고정
				a[j][x] = 1; // 흑돌을 휜돌로
			else
				a[j][x] = 0; // 휜돌을 흑돌로

	}

	// 바둑판 출력
	printf("\n");
	for (i = 1; i <= Y; i++)
	{
		for (j = 1; j <= X; j++) {
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
	return 0;
}
