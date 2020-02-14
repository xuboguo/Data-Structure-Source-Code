# include <stdio.h>

int Bin_Search(int *num,int cnt,int target)
{
	int first = 0,last = cnt-1,mid;
	int counter = 0;
	while(first <= last)
	{
		counter ++;
		mid = (first + last) / 2;//确定中间元素	
		if(num[mid] > target)
		{
			last = mid-1; //mid已经交换过了,last往前移一位
		}
		else if(num[mid] < target)
		{
			first = mid+1;//mid已经交换过了,first往后移一位
		}	
		else //判断是否相等
		{
			printf("查找次数:%d\n",counter);
			return 1;
		}
	}
	printf("查找次数:%d\n",counter);
	return 0;
}

int main(void)
{
	int flag = 0,target;
	int num[10] = {1,2,3,4,5,6,7,8,10};
	while(1)
	{
		printf("请输入您要查找的数字:\n");
		scanf("%d",&target);
		flag = Bin_Search(num,10,target);
		if(flag) printf("已经找到该数字!!\n");
		else printf("无该数字!!\n");	
	}
	return 0;
}
