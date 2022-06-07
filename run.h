#pragma once
#include "console.h"

#define size_y 10
#define size_x 20

enum { BLK, WAL, HUM, OBS };
int map[size_y][size_x];


struct Coordinate
{
	int x, y;
}person;


int StartScreen();
void Mapbase();
void Mapping();
void Jump();
void Gravity();		//주기적으로 플레이어를 밑으로 내려가게 하는 함수
void Obstacle();
void MapMove();
int Gameover();


void gotoxy(int x, int y);