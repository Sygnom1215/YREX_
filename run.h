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


int StartScreen();          //시작 화면
void Mapbase();              //맵에 값 저장
void Mapping();              //맵 출력
void Jump();                 //점프
void Gravity();              //주기적으로 플레이어를 밑으로 내려가게 하는 함수
void Obstacle();             //장애물
void MapMove();              //맵을 왼쪽으로 한 칸씩 밈
int Gameover();             //게임 오버 화면


void gotoxy(int x, int y);