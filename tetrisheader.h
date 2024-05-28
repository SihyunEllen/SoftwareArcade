#pragma once

#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#include <time.h>
#include <conio.h>
#include <stdbool.h>
#include "BlockModel.h"

int posX, posY; // Ŀ�� ��ġ
#define GBOARD_WIDTH 10   // ���� ������ �ʺ�
#define GBOARD_HEIGHT 20  // ���� ������ ����
#define GBOARD_ORIGIN_X 4 // ���� ������ x��
#define GBOARD_ORIGIN_Y 2 // ���� ������ y��

int block_id;
int gameBoardInfo[GBOARD_HEIGHT + 1][GBOARD_WIDTH + 2]; // ���� ���� ����
void ShowBlock(char blockInfo[4][4]);   // ����� ȭ�鿡 ǥ���ϴ� �Լ�                      
void DeleteBlock(char blockInfo[4][4]); // ȭ�鿡�� ����� ����� �Լ�                      
void DrawGameBoard(); // ���� ���带 �׸��� �Լ�
int DetectCollision(int PosX, int PosY, char blockModel[4][4]); // �浹�� �����ϴ� �Լ� 
void ShiftRight(void); // ����� ���������� �̵���Ű�� �Լ�
void ShiftLeft(void);  // ����� �������� �̵���Ű�� �Լ�
int BlockDown();       // ����� �Ʒ��� �� ĭ �̵���Ű�� �Լ�
void RotateBlock();    // ����� ȸ����Ű�� �Լ�
void SpaceDown();      // ����� �ٴڱ��� �� ���� ������ �Լ�

int score = 0, best_score = 0; // ���� ����, �ְ� ����

void ShowBlock(char blockInfo[4][4]) // ����� ȭ�鿡 ǥ���ϴ� �Լ�
{
	int x, y;
	COORD curPos = getCurrentCursorPos2(); // ���� Ŀ�� ��ġ
	for (y = 0; y < 4; y++)
	{
		for (x = 0; x < 4; x++)
		{
			setCurrentCursorPos(curPos.X + (x * 2), curPos.Y + y); // �ش� ��ǥ�� Ŀ�� �̵�
			if (blockInfo[y][x] == 1) // ����� ������
				printf("��");          // ��� ǥ��
		}
	}
	setCurrentCursorPos(curPos.X, curPos.Y); // ���� ��ġ�� Ŀ�� �̵�
}
void DeleteBlock(char blockInfo[4][4]) // ȭ�鿡�� ����� ����� �Լ�
{
	int x, y;
	COORD curPos = getCurrentCursorPos2(); // ���� Ŀ�� ��ġ
	for (y = 0; y < 4; y++)
	{
		for (x = 0; x < 4; x++)
		{
			setCurrentCursorPos(curPos.X + (x * 2), curPos.Y + y); // �ش� ��ǥ�� Ŀ�� �̵�
			if (blockInfo[y][x] == 1) // ����� ������
				printf(" ");          // ��� ����
		}
	}
	setCurrentCursorPos(curPos.X, curPos.Y); // ���� ��ġ�� Ŀ�� �̵�
}
void DrawGameBoard() { // ���� ���带 �׸��� �Լ�
	int x, y;
	for (y = 0; y <= GBOARD_HEIGHT; y++) {
		setCurrentCursorPos(GBOARD_ORIGIN_X, GBOARD_ORIGIN_Y + y);
		if (y == GBOARD_HEIGHT)
			printf("��"); // ���� �Ʒ� �𼭸�
		else
			printf("��"); // ���� ��
	}
	for (y = 0; y <= GBOARD_HEIGHT; y++) {
		setCurrentCursorPos(GBOARD_ORIGIN_X + (GBOARD_WIDTH + 1) * 2, GBOARD_ORIGIN_Y + y);
		if (y == GBOARD_HEIGHT)
			printf("��"); // ������ �Ʒ� �𼭸�
		else
			printf("��"); // ������ ��
	}
	for (x = 1; x < GBOARD_WIDTH + 1; x++) {
		setCurrentCursorPos(GBOARD_ORIGIN_X + x * 2, GBOARD_ORIGIN_Y + GBOARD_HEIGHT);
		printf("��"); // �Ʒ� ��
	}
	setCurrentCursorPos(GBOARD_ORIGIN_X + GBOARD_WIDTH, 0);

	// ���� ���� �迭 �ʱ�ȭ
	for (x = 0; x < GBOARD_WIDTH + 2; x++) {
		gameBoardInfo[GBOARD_HEIGHT][x] = 2; // �ٴ��� 2�� ����
	}
	for (y = 0; y < GBOARD_HEIGHT; y++) {
		gameBoardInfo[y][0] = 2;				// ���� ���� 2�� ����
		gameBoardInfo[y][GBOARD_WIDTH + 1] = 2; // ������ ���� 2�� ����
	}

	// ���� ����, ���� ����
	setCurrentCursorPos(34, 9);  printf("      SCORE : %6d", score);       // ���� ����
	setCurrentCursorPos(34, 12); printf(" BEST SCORE : %6d", best_score);  // �ְ� ����
	setCurrentCursorPos(34, 15); printf("  ��   : ��� �ٲٱ�");
	setCurrentCursorPos(34, 16); printf("��   �� : ��� �̵�");
	setCurrentCursorPos(34, 17); printf("  ��   : Soft Drop");
	setCurrentCursorPos(34, 18); printf("SPACE : Hard Drop");
}


int DetectCollision(int PosX, int PosY, char blockModel[4][4]) // �浹�� �����ϴ� �Լ�
{
	int X, Y;
	int arrX = (PosX - GBOARD_ORIGIN_X) / 2;
	int arrY = PosY - GBOARD_ORIGIN_Y;
	for (X = 0; X < 4; X++)
	{
		for (Y = 0; Y < 4; Y++)
		{
			if (blockModel[Y][X] == 1 && gameBoardInfo[arrY + Y][arrX + X] == 2)
				return 0; // �浹�ϸ� 0 ��ȯ
		}
	}
	return 1; // �浹���� ������ 1 ��ȯ
}
void ShiftRight(void) // ����� ���������� �̵���Ű�� �Լ�
{
	if (DetectCollision(posX + 2, posY, blockModel[block_id]) == 0) { // ������ �̵� �������� Ȯ��
		return; // �浹�ϸ� �̵����� ����
	}
	DeleteBlock(blockModel[block_id]); // ���� ��� ����
	posX += 2;
	setCurrentCursorPos(posX, posY); // Ŀ�� �̵�
	ShowBlock(blockModel[block_id]); // ��� �׸���
}
void ShiftLeft(void) // ����� �������� �̵���Ű�� �Լ�
{
	if (DetectCollision(posX - 2, posY, blockModel[block_id]) == 0) { // ���� �̵� �������� Ȯ��
		return; // �浹�ϸ� �̵����� ����
	}
	DeleteBlock(blockModel[block_id]); // ���� ��� ����
	posX -= 2;
	setCurrentCursorPos(posX, posY); // Ŀ�� �̵�
	ShowBlock(blockModel[block_id]); // ��� �׸���
}
int BlockDown() // ����� �Ʒ��� �� ĭ �̵���Ű�� �Լ�
{
	if (!DetectCollision(posX, posY + 1, blockModel[block_id])) { // �Ʒ� �̵� ���� Ȯ��
		return 0;
	}
	DeleteBlock(blockModel[block_id]); // ���� ��� ����
	posY += 1;
	setCurrentCursorPos(posX, posY); // Ŀ�� �̵�
	ShowBlock(blockModel[block_id]); // ��� �׸���
	return 1; // �̵� ���� �� 1 ��ȯ
}
void RotateBlock()  // ����� ȸ����Ű�� �Լ�
{
	int block_base;
	block_base = block_id - block_id % 4;
	int block_rotated = block_base + (block_id + 1) % 4;
	if (!DetectCollision(posX, posY, blockModel[block_rotated])) { // ȸ���� �� �ִ��� Ȯ��
		return 0; // �浹�ϸ� ȸ������ ����
	}
	DeleteBlock(blockModel[block_id]); // ���� ��� ����
	block_id = block_rotated;
	ShowBlock(blockModel[block_id]); // ȸ���� ����� �׸�
}
void SpaceDown()  // ����� �ٴڱ��� �� ���� ������ �Լ�
{
	while (BlockDown()); // ����� �� �̻� ������ �� ���� ������ ��� ����
}

