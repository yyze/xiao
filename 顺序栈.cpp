#include <iostream>
using namespace std;
#define MaxSize 10
typedef struct
{
	int data[MaxSize];
	int top;
}SqStack;

void InitStack(SqStack * &s)
{
	s = (SqStack *)malloc(sizeof(SqStack));
	s->top = -1;
}

void DestoryStack(SqStack * &s)
{
	free(s);
}

bool StackEmpty(SqStack * s)
{
	return(s->top == -1);
}

bool Push(SqStack * &s, int e)
{
	if (s->top == MaxSize-1)
		return false;
	s->top++;
	s->data[s->top] = e;
	return true;
}

bool Pop(SqStack * &s, int &e)
{
	if (s->top == -1)
		return false;
	e = s->data[s->top];
	s->top--;
	return true;
}

bool GetTop(SqStack * s, int &e)
{
	if (s->top == -1)
		return false;
	e = s->data[s->top];
	return true;
}

int main()
{
	SqStack *q;
	InitStack(q);
	return 0;
}
