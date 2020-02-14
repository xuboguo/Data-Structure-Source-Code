//  —°‘Ò≈≈–Ú

# include <stdio.h>

void Sort(int * a, int len)
{
    int i, j, t;
    for (i=0; i<len-1; i++) // Ω¯––n-1¬÷≈≈–Ú
	{
        int min = i;
        for (j=i+1; j<len; j++) 
		{
            if (a[j]<a[min]) // …˝–Ú≈≈¡–
                min = j;
        }
        t = a[min];
        a[min] = a[i];
        a[i] = t;
    }
}

int main()
{
	int i;
	int a[6] = {5, 7, 4, 2, 8, 3};
	
	Sort(a, 6);
	for(i=0; i<6; i++)
		printf("%d\n", a[i]);
	
	return 0;
}

