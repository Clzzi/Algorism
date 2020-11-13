#include<stdio.h>
int main() {
	int n = 0;
	int i,j=0;
	int cnt = 1;
	int arr[101][101];
	scanf("%d",&n);
	for(i = 0; i < n;i++) {
		for(j = n-1 ; j >= 0 ; j --) {
			arr[i][j] = cnt;
			cnt++;
		}
	}
//	2,0 1,0 0,0   2,1 1,1 0,1 
	for(i = 0; i < n;i++) {
		for(j = 0 ; j < n ; j ++) {
			printf("%d ",arr[i][j]);
		}
		printf("\n");
	}
	
}
