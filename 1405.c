#include<stdio.h>
int main() {
	int j,i,n = 0;
	int temp = 0;
	int arr[1001] = {0,};

	scanf("%d",&n);

	for(i = 0; i<n;i++) {
		scanf("%d",&arr[i]);
	}

	for(i = 0; i < n;i++) {
		for (j = i; j < n + i; j++) {
        	if (j >= n)
                printf("%d ", arr[j - n]);
            else
                printf("%d ", arr[j]);
        }
        printf("\n");
	}		
}

/*
#include <stdio.h>
int main()
{
    int a[1001];
    int n, i, j, g;
    scanf("%d",&n);

    for (i=0; i<n; i++) 
    	scanf("%d",&a[i]);
    
    for (i=0; i<n; i++)
    {
        for (j=i , g=1 ; g<=n; j++,g++) 
        {
            
            if(j==n) j=0;
            
            printf("%d ",a[j]);
        }
        printf("\n");
    }
}
*/
