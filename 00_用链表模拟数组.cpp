# include <stdio.h>
# include <stdlib.h>  //������exit����
# include <malloc.h>  //������malloc����

// ������һ���������� ���������͵����ֽ���struct Arr
// ���������ͺ���������Ա���ֱ���pBase, len, cnt
struct Arr
{
	int * pBase;    //�洢���������һ��Ԫ�صĵ�ַ
	int len;        //�����������ɵ����Ԫ�صĸ���
	int cnt;        //��ǰ������ЧԪ�صĸ���
	// int increment;  //�Զ���������
};


void init_arr(struct Arr * pArr, int length);
bool append_arr(struct Arr * pArr, int val);    //׷��
//pos��ֵ��1��ʼ
bool insert_arr(struct Arr * pArr, int pos, int val);
bool delete_arr(struct Arr * pArr, int pos, int * pVal);
int get();
bool is_empty(struct Arr * pArr);
bool is_full(struct Arr * pArr);
void sort_arr(struct Arr * pArr);
void show_arr(struct Arr * pArr);
void inversion_arr(struct Arr * pArr);


int main(void)
{
	struct Arr arr;
	int val;

	init_arr(&arr, 6);
	show_arr(&arr);

	append_arr(&arr, 1);
	delete_arr(&arr, 1, &val);

	printf("����ǰ\n");
	append_arr(&arr, 5);
	append_arr(&arr, 7);
	append_arr(&arr, 4);
	append_arr(&arr, 2);
	append_arr(&arr, 8);
	append_arr(&arr, 3);
	show_arr(&arr);

	printf("�����\n");
	sort_arr(&arr);
	show_arr(&arr);

	return 0;
}






// ��ʼ��
void init_arr(struct Arr * pArr, int length)
{
	pArr->pBase = (int * )malloc(sizeof(int) * length) ;

	if (NULL == pArr->pBase)
	{
		printf("��̬�ڴ����ʧ�ܣ�\n");
		exit(-1);  // ��ֹ��������
	}
	else
	{
		pArr->len = length;
		pArr->cnt = 0;
	}
	return;
}

bool is_empty(struct Arr * pArr)
{
	if (0 == pArr->cnt)
		return true;
	else
		return false;
}

bool is_full(struct Arr * pArr) 
{
	if (pArr->cnt == pArr->len)
		return true;
	else
		return false;
}

void show_arr(struct Arr * pArr)
{
	if (is_empty(pArr))
	{
		printf("����Ϊ�գ�\n");
	}
	else
	{
		for (int i = 0; i < pArr->cnt; ++i)
			printf("%d ", pArr->pBase[i]);
		printf("\n");
	}
}

bool append_arr(struct Arr * pArr, int val)
{
	//��ʱ����false
	if (is_full(pArr))
		return false;
	
	//����ʱ׷��
	pArr->pBase[pArr->cnt] = val;
	(pArr->cnt)++;
	return true;
}


bool insert_arr(struct Arr * pArr, int pos, int val)
{
	int i;
	if (is_full(pArr))
		return false;
	if (pos<1 || pos>pArr->cnt+1)
		return false;

	for (i=pArr->cnt-1; i>=pos-1; --i)
	{
		pArr->pBase[i+1] = pArr->pBase[i];
	}
	pArr->pBase[pos-1]= val;
	(pArr->cnt)++;
	return true;
}


bool delete_arr(struct Arr * pArr, int pos, int * pVal)
{
	if (is_empty(pArr))
		return false;
	if (pos<1 || pos>pArr->cnt)
		return false;

	*pVal = pArr->pBase[pos-1];
	for (int i=pos; i<pArr->cnt; ++i)
	{
		pArr->pBase[i-1] = pArr->pBase[i];
	}
	(pArr->cnt)--;
	return true;
}

void inversion_arr(struct Arr * pArr)
{
	int i = 0;
	int j = pArr->cnt-1;
	int t;

	while (i < j)
	{
		t = pArr->pBase[i];
		pArr->pBase[i] = pArr->pBase[j];
		pArr->pBase[j] = t;
		++i;
		--j;
	}
	return;
}

void sort_arr(struct Arr * pArr)
{
	int i, j, t;

	for (i=0; i<pArr->cnt; ++i)
	{
		for (j=i+1; j<pArr->cnt; ++j)
		{
			if (pArr->pBase[i] > pArr->pBase[j])
			{
				t = pArr->pBase[i];
				pArr->pBase[i] = pArr->pBase[j];
				pArr->pBase[j] = t;
			}
		}
	}
}

