#include<stdio.h>
int main()
{
 	int b,f,g = 0;
 	float a,d,c,e=0;
 	fflush(stdin);
	scanf("%f %d %f %d %f %d",&a,&b,&c,&f,&e,&g);
	printf("%.1f",a * b +c * f + e * g);
}
