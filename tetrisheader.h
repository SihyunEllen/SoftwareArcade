#pragma once

#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#include <time.h>
#include <conio.h>
#include <stdbool.h>

#define GBOARD_WIDTH 10   // ���� ������ �ʺ�
#define GBOARD_HEIGHT 20  // ���� ������ ����
#define GBOARD_ORIGIN_X 4 // ���� ������ x��
#define GBOARD_ORIGIN_Y 2 // ���� ������ y��

int gameBoardInfo[GBOARD_HEIGHT + 1][GBOARD_WIDTH + 2]; // ���� ���� ����
void DrawGameBoard(); // ���� ���带 �׸��� �Լ�

int score = 0, best_score = 0; // ���� ����, �ְ� ����

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