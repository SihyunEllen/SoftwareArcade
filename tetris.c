#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#include <time.h>
#include <conio.h>
#include <stdbool.h>
#include "tetrisheader.h"

int posX = 12, posY = 0;
int tetris() {
    speed = 30; // ��� �̵� �ӵ�
    srand((unsigned int)time(NULL)); // ���� ����
    removeCursor();  // Ŀ�� ����
    DrawGameBoard(); // ���� ���� �׸���

    // ���� ���� ����
    while (1) {
        if (IsGameOver() == 0) { // ���� ���� Ȯ��
            break;
        }
        while (1)
        {
            if (BlockDown() == 0) // ����� �� �̻� ������ �� ���� ���
            {
                AddBlockToBoard();  // ����� ���� ���忡 �߰�
                RemoveFillUpLine(); // ���� �� �� ����
                DrawGameBoard(); // ���� ���� �׸���
                break;
            }
            ProcessKeyInput(); // Ű �Է� ó��
        }
        // ���ο� ��� ���� ��ġ
        posX = 6; posY = 2;
        block_id = (rand() % 7) * 4; // ���ο� ��� ���� ����
    }
    // ���� ���� �޽��� ���
    setCurrentCursorPos(14, 0);
    puts("GameOver");
    getchar();
    return 0;
}