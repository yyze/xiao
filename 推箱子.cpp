#include <iostream>
#include <string>
#include <Windows.h>
#include <conio.h> //按键，控制
using namespace std;
int map[8][8] =
{
	{1,1,1,1,1,1,1,1},
	{1,0,4,0,1,1,1,1},
	{1,1,3,0,0,1,1,1},
	{1,1,0,0,0,1,1,1},
	{1,1,0,5,1,1,1,1},
	{1,1,1,0,0,0,0,1},
	{1,0,0,0,1,1,1,1},
	{1,1,1,1,1,1,1,1}
};//0是空地 1是墙壁 3是箱子 4是目的地 5是人 7是箱子+目的地 9是人+目的地

void show()//地图
{
	int i, j;
	for ( i = 0; i < 8; i++)
	{
		for ( j = 0; j < 8; j++)
		{
			if (map[i][j] == 0)
				cout << "   ";
			if (map[i][j] == 1)
				cout << " # " ;
			if (map[i][j] == 3)
				cout << " @ " ;
			if (map[i][j] == 4)
				cout << " $ " ;
			if (map[i][j] == 5||map[i][j]==9)
				cout << " o ";
			if (map[i][j] == 7)
				cout << " X ";
			if (j == 7)
				cout << endl;
		}
	}
}

void play()
{
	int i, j;
	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			if (map[i][j] == 5 || map[i][j] == 9)
			{
				break;
			}
		}
		if (map[i][j] == 5 || map[i][j] == 9)
		{
			break;
		}
	}
	cout << i << " " << j;

	char ch= '\0';//捕获用户按键
	ch = _getch();

	switch (ch)
	{
	case 'W':
	case 'w':
		//空地
		if (map[i - 1][j] == 0 || map[i - 1][j] == 4)
		{
			map[i][j] -= 5;
			map[i - 1][j] += 5;
		}
		//推箱子
		if (map[i - 1][j] == 3 || map[i - 1][j] == 7)
		{
			if (map[i - 2][j] == 0 || map[i - 2][j] == 4)
			{
				map[i][j] -= 5;
				map[i - 1][j] += 2;
				map[i - 2][j] += 3;
			}
		}
		break;
	case 'A':
	case 'a':
		//空地
		if (map[i][j-1] == 0 || map[i][j-1] == 4)
		{
			map[i][j] -= 5;
			map[i][j-1] += 5;
		}
		//推箱子
		if (map[i][j-1] == 3 || map[i ][j- 1] == 7)
		{
			if (map[i ][j- 2] == 0 || map[i ][j- 2] == 4)
			{
				map[i][j] -= 5;
				map[i ][j- 1] += 2;
				map[i ][j- 2] += 3;
			}
		}
		break;
	case 'D':
	case 'd':
		//空地
		if (map[i][j + 1] == 0 || map[i][j + 1] == 4)
		{
			map[i][j] -= 5;
			map[i][j + 1] += 5;
		}
		//推箱子
		if (map[i][j + 1] == 3 || map[i ][j+ 1] == 7)
		{
			if (map[i][j + 2] == 0 || map[i][j + 2] == 4)
			{
				map[i][j] -= 5;
				map[i][j + 1] += 2;
				map[i][j + 2] += 3;
			}
		}
		break;
	case 'S':
	case 's':
		//空地
		if (map[i+1][j] == 0 || map[i + 1][j] == 4)
		{
			map[i][j] -= 5;
			map[i + 1][j] += 5;
		}
		//推箱子
		if (map[i + 1][j] == 3 || map[i + 1][j] == 7)
		{
			if (map[i + 2][j] == 0 || map[i + 2][j] == 4)
			{
				map[i][j] -= 5;
				map[i + 1][j] += 2;
				map[i + 2][j] += 3;
			}
		}
		break;
	default:
		break;
	}
}

int main()
{
	while(1)
	{
		show();
		play();
		system("cls");
	}

	system("pause");
	return 0;
}