#pragma once
#include "console.h"

#define size_y 10
#define size_x 20

enum { BLK, WAL, HUM, OBS };






int StartScreen();
void Mapbase();
void Mapping();
void Jump();
void Gravity();	//�ֱ������� �÷��̾ ������ �������� �ϴ� �Լ�
void Obstacle();
void MapMove();
int Gameover();


void gotoxy(int x, int y);