#include<stdio.h>
int main(){
	int a,b;
	printf("두수를 차례로 입력하세요 : ");
	scanf("%d %d",&a,&b);
	if(a > b)
	{
		printf(">");
	}
	else if(a < b){
		printf("<");
	}
	else
	{
		printf("=");
	}
}
