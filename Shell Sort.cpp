// Ï£¶ûÅÅĞò

# include <stdio.h>

void ShellSort(int * arr, int size)  
{  
    int i, j, tmp, increment;  
    for (increment = size/ 2; increment > 0; increment /= 2) 
	{    
        for (i = increment; i < size; i++) 
		{  
            tmp = arr[i];  
            for (j = i - increment; j >= 0 && tmp < arr[j]; j -= increment) 
			{  
                arr[j + increment] = arr[j];  
            }  
            arr[j + increment] = tmp;
        }  
    }  
}


int main()
{
	int i;
	int a[6] = {5, 7, 4, 2, 8, 3};
	
	ShellSort(a, 6);
	for(i=0; i<6; i++)
		printf("%4d", a[i]);
	printf("\n");
	
	return 0;
}