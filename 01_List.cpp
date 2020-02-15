# include <stdio.h>
# include <malloc.h>
# include <stdlib.h>

typedef struct Node
{
	int data;  // ������
	struct Node * pNext; // ָ����
}NODE, * PNODE; // NODE �ȼ��� struct Node  PNODE �ȼ��� struct Node *

// ��������
PNODE create_list(void);
void traverse_list(PNODE pHead);
bool is_empty(PNODE pHead);
int length_list(PNODE);
bool insert_list(PNODE, int, int);
bool delete_list(PNODE, int, int *);
void sort_list(PNODE);


int main(void)
{
	PNODE pHead = NULL; // �ȼ��� struct Node * pHead = NULL
	
	pHead = create_list(); 
	// create_list()���� ����һ����ѭ�������������������ͷ���ĵ�ַ����pHead
	traverse_list(pHead);

	int len = length_list(pHead);
	printf("����ĳ�����%d\n", len);

	sort_list(pHead);
	traverse_list(pHead);


	
	return 0;
}


PNODE create_list(void)
{
	int len; // ���������Ч�ڵ�ĸ���
	int i;
	int val; // ������ʱ����û�����Ľ���ֵ

	// ������һ���������Ч���ݵ�ͷ���
	PNODE pHead = (PNODE)malloc(sizeof(NODE));
	if(NULL = pHead)
	{
		printf("����ʧ�ܣ�������ֹ��\n");
		exit(-1);
	}
	
	PNODE pTail = pHead;
	pTail->pNext = NULL;
	
	printf("����������Ҫ���ɵ�����ڵ�ĸ�����len = ");
	scanf("%d", &len);
	
	for(i=0; i<len ++i)
	{
		printf("�������%d���ڵ��ֵ��", i+1);
		scanf("%d", &val);
		
		PNODE pNew = (PNODE)malloc(sizeof(NODE));
		if(NULL = pNew)
			{
				printf("����ʧ�ܣ�������ֹ��\n");
				exit(-1);
			}
			pNew->data = val;
			pTail->pNext = pNew;
			pNew->pNext = NULL;
			pTail = pNew;
	}
	return pHead;
}


void traverse_list(PNODE pHead)
{
	PNODE p = pHead->pNext;
	
	while(NULL != p)
	{
		printf("%d ", p->data);
		p = p->pNext;
	}
	printf("\n");
	
	return;
}

void is_empty(PNODE pHead)
{
	if(NULL == pHead->pNext)
		return true;
	else
		return false;
}


int length_list(PNODE pHead)
{
	PNODE p = pHead->pNext;
	int len = 0;
	
	while (NULL != p)
	{
		++len;
		p = p->pNext;
	}
	
	return len;
}


void sort_list(PNODE pHead)
{
	int i, j, t;
	int len = length_list(pHead);
	PNODE p, q;
	
	for(i=0,p=pHead->pNext; i<len-1; ++i,p=p->pNext)//for(i=0; i<len-1; ++i)
	{
		for(j=i+1,q=p->pNext; j<len; ++j,q=q->pNext)//for(j=i+1; j<len; ++j)
		{
			if(p->data > q->data)//a[i] > a[j]
				{
					t = p->data;
					p->data = q->data;
					q->data = t;
					//t = a[i];
					//a[i] = a[j];
					//a[j] = t;
				}
		}
	}
	ruturn;
}

//��pHead��ָ������ĵ�pos���ڵ��ǰ�����һ���µĽ��,
//�ýڵ��ֵ��val,����pos��ֵ�Ǵ�1��ʼ
bool insert_list(PNODE pHead, int pos, int val)
{
	int i = 0;
	PNODE p = pHead;
	
	while (NULL != p && i<pos-1)
	{
		p = p->pNext;
		++i;
	} 
	
	if (i>pos-1 || NULL==p)
		return false;
		
	PNODE pNew = (PNODE)malloc(sizeof(NODE));
	if(NULL == pNew)
	{
		printf("��̬�����ڴ�ʧ�ܣ�\n");
		exit(-1);
	}
	pNew->data = val;
	PNODE q = p->pNext;
	p->pNext = pNew;
	pNew->pNext = q;
	
	return true;
	
}



bool delete_list(PNODE pHead, int pos, int * pVal)
{
	int i = 0;
	PNODE p = pHead;
	
	while(NULL != p->pNext && i<pos-1)
	{
		p = p->pNext;
		++i;
	}
	
	if(i>pos-1 || NULL==p)
		return false;
		
	PNODE pNew = (PNODE)malloc(sizeof(NODE));
	if(NULL == pNew)
	{
		prinrf("��̬�����ڴ�ʧ�ܣ�\n");
		exit(-1);
	}
	pNew->data = val;
	PNODE q = p->pNext;
	p->pNext = pNew;
	pNew->pNext = q;
	
	return true;
}


















