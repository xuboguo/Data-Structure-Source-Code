//  øÏÀŸ≈≈–Ú


# include <stdio.h>

void swap(int *a, int *b)    
{  
    int temp;  
    temp = *a;  
    *a = *b;  
    *b = temp;  
} 

void QuickSort(int *arr, int maxlen, int begin, int end)  
{  
    int i, j;  
    if (begin < end) {  
        i = begin + 1;  
        j = end;        
        while (i < j) {  
            if(arr[i] > arr[begin]) {  
                swap(&arr[i], &arr[j]); 
                j--;  
            } else {  
                i++; 
            }  
        }  
        if (arr[i] >= arr[begin]) {  
            i--;  
        }  
        swap(&arr[begin], &arr[i]);      
        QuickSort(arr, maxlen, begin, i);  
        QuickSort(arr, maxlen, j, end);  
    }  
}  
 




int main()
{
	int i;
	int a[6] = {5, 7, 4, 2, 8, 3};
	
	QuickSort(a, 6);
	for(i=0; i<6; i++)
		printf("%4d", a[i]);
	printf("\n");
	
	return 0;
}