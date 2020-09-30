#include <stdio.h>
int main()
{
	int a, d, n, i, cnt = 0;;
	scanf("%d %d %d", &a, &d, &n);
	for (i = a;cnt < n;i += d, cnt++);
	printf("%d\n", i-d);
}
