//  ¼ÆÊýÅÅÐò


# include <stdio.h>


void CountingSort(int *A, int *B, int n, int k)  
{  
    int *C = (int *)malloc(sizeof(int) * (k + 1));  
    int i;  
    for (i = 0; i <= k; i++) {  
        C[i] = 0;  
    }  
    for (i = 0; i < n; i++) {  
        C[A[i]]++;  
    }  
    for (i = 1; i <= k; i++) {  
        C[i] = C[i] + C[i - 1];  
    }  
    for (i = n - 1; i >= 0; i--) {  
        B[C[A[i]] - 1] = A[i];  
        C[A[i]]--;  
    }  
} 



int main()
{
	int i;
	int a[6] = {5, 7, 4, 2, 8, 3};
	
	CountingSort(a, 6);
	for(i=0; i<6; i++)
		printf("%4d", a[i]);
	printf("\n");
	
	return 0;
}