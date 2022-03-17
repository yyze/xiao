#include <iostream>
using namespace std;

int mg[10][10] =
{
	{1,1,1,1,1,1,1,1,1,1},
	{1,0,0,1,0,0,0,1,0,1},
	{1,0,0,1,0,0,0,1,0,1},
	{1,0,0,0,0,1,1,0,0,1},
	{1,0,1,1,1,0,0,0,0,1},
	{1,0,0,0,1,0,0,0,0,1},
	{1,0,1,0,0,0,1,0,0,1},
	{1,0,1,1,1,0,1,1,0,1},
	{1,1,0,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,1},
};

typedef struct
{
	int i;
	int j;
	int di;
}Box;

typedef struct
{
	Box data[ 100 ];
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

bool Push(SqStack * &s, Box e)
{
	if (s->top == 99)
		return false;
	s->top++;
	s->data[s->top] = e;
	return true;
}

bool Pop(SqStack * &s, Box &e)
{
	if (s->top == -1)
		return false;
	e = s->data[s->top];
	s->top--;
	return true;
}

bool GetTop(SqStack * s, Box &e)
{
	if (s->top == -1)
		return false;
	e = s->data[s->top];
	return true;
}

bool mgpath(int xi, int yi, int xe, int ye)
{
	Box path[100], f;
	int i, j, di, i1, j1, k;
	bool find;
	SqStack * st;
	InitStack(st);
	f.i = xi;
	f.j = yi;
	f.di = -1;
	Push(st, f);
	mg[xi][yi] = -1;
	while (!StackEmpty(st))
	{
		GetTop(st, f);
		i = f.i; j = f.j; di = f.di;
		if (i == xe && j == ye)
		{
			cout << "迷宫路径如下：" << endl;
			k = 0;
			while (!StackEmpty(st))
			{
				Pop(st, f);
				path[k++] = f;
			}
			while (k >= 1)
			{
				k--;
				cout <<"("<< path[k].i <<","<< path[k].j<<")";
				if ((k + 2) % 5 == 0)
					cout << endl;
			}
			cout << endl;
			DestoryStack(st);
			return true;
		}
		find = false;
		while (di < 4 && !find)
		{
			di++;
			switch (di)
			{
			case 0: i1 = i - 1; j1 = j; break;
			case 1: i1 = i; j1 = j + 1; break;
			case 2: i1 = i + 1; j1 = j; break;
			case 3: i1 = i; j1 = j - 1; break;
			}
			if (mg[i1][j1] == 0)find = true;
		}
		if (find)
		{
			st->data[st->top].di = di;
			f.i = i1; f.j = j1; f.di = -1;
			Push(st, f);
			mg[i1][j1] = -1;
		}
		else
		{
			Pop(st, f);
			mg[f.i][f.j] = 0;
		}
	}
	DestoryStack(st);
	return false;
}


int main()
{
	if (!mgpath(1, 1, 8, 8))
		cout << "无解" << endl;
	system("pause");
	return 1;
}





