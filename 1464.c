#include<stdio.h>
int main() {
	int n,m=0;
	int arr[1000][1000]={0,};
	int i,j=0;
	int k = 1;
	
	scanf("%d%d",&n,&m);
	for(i=n;i>0;i--) {
		for(j=m;j>0;j--) {
			arr[i][j] = k;
			k++;
		}
	}
	
	for(i = 1 ; i <= n ; i++) {
		for(j = 1 ; j <= m ; j++) {
			printf("%d ",arr[i][j]);
		}
		printf("\n");
	}
}
