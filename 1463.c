#include<stdio.h>
int main() {
	int n = 0;
	int i,j=0;
	int cnt = 1;
	int arr[101][101];
	scanf("%d",&n);
	
	for(i=1;i<=n;i++) {
		for(j=n;j>0;j--) {
			arr[j][i] = cnt;
			cnt++;
		}
	}

	for(i = 1; i <= n;i++) {
		for(j = 1 ; j <= n ; j ++) {
			printf("%d ",arr[i][j]);
		}
		printf("\n");
	}	
}
