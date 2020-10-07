#include<stdio.h>
int main() {
 int i,j,k;
 float y;
 scanf("%d %d %d",&i,&j,&k);
 y = ((i*j*k)/8)/1024;
 printf("%.2f MB",y/1024);
}
