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


int StartScreen();          //���� ȭ��
void Mapbase();              //�ʿ� �� ����
void Mapping();              //�� ���
void Jump();                 //����
void Gravity();              //�ֱ������� �÷��̾ ������ �������� �ϴ� �Լ�
void Obstacle();             //��ֹ�
void MapMove();              //���� �������� �� ĭ�� ��
int Gameover();             //���� ���� ȭ��


void gotoxy(int x, int y);