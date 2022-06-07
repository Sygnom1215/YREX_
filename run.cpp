#include "run.h"

int StartScreen()
{
	int select = 0, ch = 0;
	int r;

	while (true)
	{
		gotoxy(0, 0);
		if (select == 0)
		{
			cout << ("■■■■■■■■■■■■■■■■■■■■\n");
			cout << ("■       ■                    ■     ■\n");
			cout << ("■       ■ ■  ■ ■        ■  ■   ■\n");
			cout << ("■       ■ ■  ■ ■■  ■■■■     ■\n");
			cout << ("■   ■■     ■   ■  ■  ■■       ■\n");
			cout << ("■                                    ■\n");
			cout << ("■          ▶  Game Start            ■\n");
			cout << ("■                                    ■\n");
			cout << ("■                 Exit               ■\n");
			cout << ("■■■■■■■■■■■■■■■■■■■■\n");
			cout << ("\n w : 메뉴 커서 위로 이동      j : 플레이어 점프\n\n s : 메뉴 커서 아래로 이동    Enter : 메뉴 선택\n");
		}
		else if (select == 1)
		{
			cout << ("■■■■■■■■■■■■■■■■■■■■\n");
			cout << ("■       ■                    ■     ■\n");
			cout << ("■       ■ ■  ■ ■        ■  ■   ■\n");
			cout << ("■       ■ ■  ■ ■■  ■■■■     ■\n");
			cout << ("■   ■■     ■   ■  ■  ■■       ■\n");
			cout << ("■                                    ■\n");
			cout << ("■              Game Start            ■\n");
			cout << ("■                                    ■\n");
			cout << ("■          ▶     Exit               ■\n");
			cout << ("■■■■■■■■■■■■■■■■■■■■\n");
			cout << ("\n w : 메뉴 커서 위로 이동      j : 플레이어 점프\n\n s : 메뉴 커서 아래로 이동    Enter : 메뉴 선택\n");
		}
		ch = _getch();
		if (ch == 'w' || ch == 'W')
		{
			if (select == 0) select = 1;
			else select--;
		}
		else if (ch == 's' || ch == 'S')
		{
			if (select == 1) select = 0;
			else select++;
		}
		else if (ch == 13 && select == 0)
		{
			r = 1;
			break;
		}
		else if (ch == 13 && select == 1)
		{
			r = 0;
			break;
		}
	}
	return r;
}

void Mapbase()
{
	for (int i = 0; i < size_y; i++)
	{
		for (int j = 0; j < size_x; j++)
		{
			if (i == 0 || i == size_y - 1) map[i][j] = WAL;
			else if (j == 0 || j == size_x - 1) map[i][j] = WAL;
			else map[i][j] = BLK;
		}
	}
	map[size_y - 2][3] = HUM;
	person.x = 3;
	person.y = size_y - 2;
}

void Mapping()
{
	for (int i = 0; i < size_y; i++)
	{
		for (int j = 0; j < size_x; j++)
		{
			if (map[i][j] == BLK) printf("  ");
			if (map[i][j] == WAL) printf("■");
			if (map[i][j] == HUM) printf("●");
			if (map[i][j] == OBS) printf("■");
		}
		cout << ("\n");
	}
	printf("\n w : 메뉴 커서 위로 이동      j : 플레이어 점프\n\n s : 메뉴 커서 아래로 이동    Enter : 메뉴 선택\n");

}

void Jump()
{
	int c;

	if (map[person.y - 1][person.x] == BLK)
	{
		c = map[person.y][person.x];
		map[person.y][person.x] = map[person.y - 1][person.x];
		map[person.y - 1][person.x] = c;
		person.y--;
	}
}

void Gravity()
{
	int c;

	if (map[person.y + 1][person.x] == BLK)
	{
		c = map[person.y][person.x];
		map[person.y][person.x] = map[person.y + 1][person.x];
		map[person.y + 1][person.x] = c;
		person.y++;
	}
}

void Obstacle()
{
	int rad;

	rad = rand() % 3;

	if (rad == 0)
	{
		map[size_y - 2][size_x - 2] = OBS;
		map[size_y - 3][size_x - 2] = OBS;
	}
	else if (rad == 1)
	{
		map[size_y - 2][size_x - 2] = OBS;
		map[size_y - 2][size_x - 3] = OBS;
		map[size_y - 3][size_x - 2] = OBS;
		map[size_y - 3][size_x - 3] = OBS;
	}
	else if (rad == 2)
	{
		map[size_y - 2][size_x - 2] = OBS;
		map[size_y - 3][size_x - 2] = OBS;
		map[size_y - 3][size_x - 3] = OBS;
	}
}

void MapMove()
{
	int c;

	for (int i = 1; i < size_y - 1; i++)
	{
		for (int j = 1; j < size_x - 1; j++)
		{
			if (j == 1) map[i][j] = BLK;
			else if (map[i][j] == BLK && map[i][j - 1] != HUM)
			{
				c = map[i][j];
				map[i][j] = map[i][j - 1];
				map[i][j - 1] = c;
			}
			else if (map[i][j] == OBS)
			{
				map[i][j - 1] = OBS;
				map[i][j] = BLK;
			}
		}
	}
}

int Gameover()
{
	int select = 0, ech = 0;
	int er = 1, eturn = 0;

	if (map[person.y][person.x] != HUM) eturn = 1;

	while (eturn)
	{
		gotoxy(0, 0);
		if (select == 0)
		{
			cout << ("■■■■■■■■■■■■■■■■■■■■\n");
			cout << ("■                                    ■\n");
			cout << ("■                                    ■\n");
			cout << ("■         ▶  Main Screen            ■\n");
			cout << ("■                                    ■\n");
			cout << ("■                Exit                ■\n");
			cout << ("■                                    ■\n");
			cout << ("■                                    ■\n");
			cout << ("■                                    ■\n");
			cout << ("■■■■■■■■■■■■■■■■■■■■\n");
			cout << ("\n w : 메뉴 커서 위로 이동      j : 플레이어 점프\n\n s : 메뉴 커서 아래로 이동    Enter : 메뉴 선택\n");
		}
		else if (select == 1)
		{
			cout << ("■■■■■■■■■■■■■■■■■■■■\n");
			cout << ("■                                    ■\n");
			cout << ("■             Main Screen            ■\n");
			cout << ("■                                    ■\n");
			cout << ("■         ▶     Exit                ■\n");
			cout << ("■                                    ■\n");
			cout << ("■                                    ■\n");
			cout << ("■                                    ■\n");
			cout << ("■                                    ■\n");
			cout << ("■■■■■■■■■■■■■■■■■■■■\n");
			cout << ("\n w : 메뉴 커서 위로 이동      j : 플레이어 점프\n\n s : 메뉴 커서 아래로 이동    Enter : 메뉴 선택\n");
		}
		ech = _getch();
		if (ech == 'w' || ech == 'W')
		{
			if (select == 0) select = 1;
			else select--;
		}
		else if (ech == 's' || ech == 'S')
		{
			if (select == 1) select = 0;
			else select++;
		}
		else if (ech == 13 && select == 0)
		{
			er = StartScreen();
			Mapbase();
			break;
		}
		else if (ech == 13 && select == 1)
		{
			er = 0;
			break;
		}
	}
	return er;
}


void gotoxy(int x, int y)
{
	COORD Pos;
	Pos.X = x;
	Pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
