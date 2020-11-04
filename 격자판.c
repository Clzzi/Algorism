#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main() {
	int a[101][101] = { 0, };
	int h, w, n; // 높이 너비 갯수
	int x, y, d, l; // x좌표 y좌표 가로세로여부 길이
	int i, j; // 반복문 카운트 변수
	scanf("%d%d",&h,&w); // 배열의 높이와 너비 입력받기
	scanf("%d", &n); // 막대 개수 입력받기
	
	for (i = 0; i < n; i++) { 
		scanf("%d%d%d%d", &l, &d, &x, &y); // 길이 가로세로여부 x좌표 y좌표 입력받기
		if (l == 1) { // 길이가 1 이면 가로세로상관없이 a[x][y]에 1넣어주면됨
			a[x][y] = 1;
		}
		else { // 길이가 2이상 이라면 가로 세로 에 따라 나뉨
			if (d == 0) { // 가로
				for (j = 0; j < l; j++) {
					a[x][y + j] = 1;
				}
			}
			else { // 세로
				for (j = 0; j < l; j++) {
					a[y + j][x] = 1;
				}
			}
		}
	}
	// 출력
	for (i = 1; i <= h; i++) {
		for (j = 1; j <= w; j++) {
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
}

