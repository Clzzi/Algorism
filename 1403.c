#include<stdio.h>
int main() {
	int num = 0;
	int arr[101];
	int i,j=0;
	scanf("%d",&num);
	for(i=0;i<num;i++) {
		scanf("%d",&arr[i]);
	}

for(j=0;j<=1;j++) {
	for(i=0;i<num;i++) {
		printf("%d\n",arr[i]);
	}
}

}
