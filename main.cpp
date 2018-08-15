#include <iostream>
#include <Windows.h>

using namespace std;

void setCursorPosition(int x, int y)
{
	static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	cout.flush();
	COORD coord = { (SHORT)x, (SHORT)y };
	SetConsoleCursorPosition(hOut, coord);
}

int main()
{
	int y = 24, x = 39;
	bool map[24][39][2];
	double fill = 0.1;

	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < x; j++)
		{
			map[i][j][0] = 0;
			map[i][j][1] = 0;
		}
	}
	for (int i = 0; i < y * x * fill; i++)
	{
		map[rand() % y][rand() % x][0] = 1;
	}

	/*map[1][1][0] = true;
	map[1][2][0] = true;
	map[2][2][0] = true;
	map[2][3][0] = true;
	map[3][1][0] = true;*/
	
	while (1)
	{
		for (int i = 0; i < y; i++)
		{
			for (int j = 0; j < x; j++)
			{
				int neigberhood = map[(i - 1 + y) % y][(j - 1 + x) % x][0] +
					map[(i - 1 + y) % y][j][0] +
					map[(i - 1 + y) % y][(j + 1 + x) % x][0] +
					map[i][(j + 1 + x) % x][0] +
					map[(i + 1 + y) % y][(j + 1 + x) % x][0] +
					map[(i + 1 + y) % y][j][0] +
					map[(i + 1 + y) % y][(j - 1 + x) % x][0] +
					map[i][(j - 1 + x) % x][0];

				if(map[i][j][0])
				{
					if (neigberhood == 2 || neigberhood == 3/* || neigberhood == 1 || neigberhood == 4 || neigberhood == 5*/) map[i][j][1] = 1;
					else map[i][j][1] = 0;
				}
				else
				{
					if (neigberhood == 3) map[i][j][1] = 1;
					else map[i][j][1] = 0;
				}
			}
		}
		for (int i = 0; i < y; i++)
		{
			for (int j = 0; j < x; j++)
			{
				map[i][j][0] = map[i][j][1];
			}
		}

		//system("cls");
		setCursorPosition(0, 0);
		for (int i = 0; i < y; i++)
		{
			for (int j = 0; j < x; j++)
			{
				cout << (map[i][j][0] ? "[]" : "  ");
			}
			cout << endl;
		}
		Sleep(10);
	}
	Sleep(1000);
	return 0;
}