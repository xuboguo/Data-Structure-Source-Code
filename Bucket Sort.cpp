# include <stdio.h>





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