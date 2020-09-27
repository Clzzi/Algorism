#include<stdio.h>                              
int main()
{
	int a,b=0;
	scanf("%d%d",&a,&b);
	int r=0;
	for(int i =a;i<=b;i++)
	{
		if(i%2==0)
		{
		printf("-%d",i);
		r = r-i;
		}
		else
		{
		printf("+%d",i);
		r = r+i;
		}
	}
	printf("=%d",r);
}

