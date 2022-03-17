#include <iostream>
using namespace std;
#define MaxSize 10
typedef struct linknode
{
	int data;
	struct linknode *next;
}LinkStNode;

void InitStack(LinkStNode * &s)
{
	s = (LinkStNode *)malloc(sizeof(LinkStNode));
	s->next = NULL;
}

void DestoryStack(LinkStNode * &s)
{
	LinkStNode *pre = s;
	LinkStNode *p = s->next;
	while (p != NULL)
	{
		free(pre);
		pre = p;
		p = pre->next;
	}
	free(pre);
}

bool StackEmpty(LinkStNode * s)
{
	return(s->next == NULL);
}

void Push(LinkStNode * &s, int e)
{
	LinkStNode *p;
	p = (LinkStNode *)malloc(sizeof(LinkStNode));
	p->data = e;
	p->next = s->next;
	s->next = p;
}

bool Pop(LinkStNode * &s, int &e)
{
	LinkStNode *p;
	if (s->next == NULL)
		return false;
	p = s->next;
	e = p->data;
	s->next = p->next;
	free(p);
	return true;
}

bool GetTop(LinkStNode * s, int &e)
{
	if (s->next == NULL)
		return false;
	e = s->next->data;
	return true;
}

int main()
{
	LinkStNode *p;
	InitStack(p);
	return 0;
}
