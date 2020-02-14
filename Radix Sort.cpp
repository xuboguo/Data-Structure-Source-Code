# include <stdio.h>

int get_index(int num, int dec, int order)
{
    int i, j, n;
    int index;
    int div;
    for (i = dec; i > order; i--) {
        n = 1;
        for (j = 0; j < dec - 1; j++)
            n *= 10;
        div = num / n;
        num -= div * n;
        dec--;
    }
    n = 1;
    for (i = 0; i < order - 1; i++)
        n *= 10;
    index = num / n;
    return index;
}
 
void RadixSort(int *arr, int len, int dec, int order)
{
    int i, j;
    int index; 
    int tmp[len]; 
    int num[10];
    memset(num, 0, 10 * sizeof(int)); 
    memset(tmp, 0, len * sizeof(int));
 
    if (dec < order) {
        return;
    }
    for (i = 0; i < len; i++) {
        index = get_index(arr[i], dec, order);
        num[index]++; 
    }
 
    for (i = 1; i < 10; i++) {
        num[i] += num[i-1];
    }
    for (i = len - 1; i >= 0; i--) {
        index = get_index(arr[i], dec, order); 
        j = --num[index]; 
        tmp[j] = arr[i]; 
    }
 
    for (i = 0; i < len; i++) {
        arr[i] = tmp[i]; 
    }
    RadixSort(arr, len, dec, order+1);
}



int main()
{
	int i;
	int a[6] = {5, 7, 4, 2, 8, 3};
	
	RadixSort(a, 6);
	for(i=0; i<6; i++)
		printf("%4d", a[i]);
	printf("\n");
	
	return 0;
}