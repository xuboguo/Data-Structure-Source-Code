# include <stdio.h>

void InsertionSort(int *arr, int size)    
{    
    int i, j, tmp;    
    for (i = 1; i < size; i++) 
	{    
        if (arr[i] < arr[i-1]) 
		{    
            tmp = arr[i];    
            for (j = i - 1; j >= 0 && arr[j] > tmp; j--) 
			{  
                arr[j+1] = arr[j];    
            }  
            arr[j+1] = tmp;    
        }          
    }    
} 


int main()
{
	int i;
	int a[6] = {5, 7, 4, 2, 8, 3};
	
	InsertionSort(a, 6);
	for(i=0; i<6; i++)
		printf("%4d", a[i]);
	printf("\n");
	
	return 0;
}