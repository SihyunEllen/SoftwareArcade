#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#include <time.h>
#include <conio.h>
#include <stdbool.h>
#include "tetrisheader.h"

int tetris() {
    srand((unsigned int)time(NULL)); // ���� ����
    removeCursor();  // Ŀ�� ����
    DrawGameBoard(); // ���� ���� �׸���
	return 0;
}