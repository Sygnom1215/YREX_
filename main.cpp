#include "run.h"


int main()
{
	int turn = 1;
	int ch, t = 0;
	time_t start, finish;
	float score = 0;

	srand((unsigned)time(NULL));
	turn = StartScreen();
	if (turn == 1)
	{
		gotoxy(0, 0);
		Mapbase();
		Mapping();
	}
	else return 0;
	while (true)
	{

		if (_kbhit())
		{
			ch = _getch();
			if (ch == 'j') Jump();
		}
		if (t % 30 == 0) MapMove();
		if (t % 70 == 0) Gravity();
		if (t % 500 == 0) Obstacle();
		gotoxy(0, 0);
		start = clock();

		Mapping();
		turn = Gameover();
		finish = clock();
		score = (float)(finish - start);
		cout << score << "Á¡" << endl;
		if (turn == 0)
			break;
		t++;

	}
	return 0;
}
