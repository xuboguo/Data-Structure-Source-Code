# include <stdio.h>
# include <malloc.h>

typedef struct Queue
{
	int * pBase;
	int front;
	int rear;
}QUEUE;

void init(QUEUE *);
bool en_queue(QUEUE *, int val);
void traverse_queue(QUEUE *);
bool full_queue(QUEUE *);
bool out_queue(QUEUE *, int val);



int main(void)
{
	QUEUE Q;

	init(&Q);
	en_queue(&Q, 1);

	return 0;
}

void init(QUEUE *)
{
	pQ->pBase = (int *)malloc(sizeof(int) * 6);
	pQ->front = 0;
	pQ->rear = 0;
}

bool full_queue(QUEUE * pQ)
{
	if( (pQ->rear+1)%6 == pQ->front )
		return true;
	else
		return false;
}

bool en_queue(QUEUE * pQ, int val)
{
	if(full_queue(pQ))
	{
		return false;
	}
	else
	{
		pQ->pBase[pQ->rear] = val;
		pQ->rear = (pQ->rear+1) % 6;

		return true;
	}
}

void traverse_queue(QUEUE * pQ)
{
	int i = pQ->front; 

	while (i != pQ->rear)
	{
		printf("%d ", pQ->pBase[i]);
		i = (i+1) % 6;
	}

	return;
}


bool emput_queue(QUEUE * pQ)
{
	if ( pQ->front == pQ->rear )
		return true;
	else
		return false;
}

bool out_queue(QUEUE * pQ, int * pVal)
{
	if( emput_queue(pQ) )
	{
		return false;
	}
	else
	{
		* pVal = pQ->pBase[pQ->front];
		pQ->front = (pQ->front + 1) % 6;
		return true;
	}
}



































