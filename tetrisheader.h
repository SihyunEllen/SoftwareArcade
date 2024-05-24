#pragma once

#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#include <time.h>
#include <conio.h>
#include <stdbool.h>

#define kbhit _kbhit   
#define getch _getch   

void hideCursor() {
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    cursorInfo.bVisible = FALSE; // Ŀ���� ����
    SetConsoleCursorInfo(consoleHandle, &cursorInfo);
}

void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void setColor(int color) { // ���� ����
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void firsttitle(void) {
    int x = 5;  // ���� ȭ���� ǥ�õǴ� x��ǥ 
    int y = 4;  // ���� ȭ���� ǥ�õǴ� y��ǥ 

    int mintColor = FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY;

    // ����
    setColor(mintColor);
    gotoxy(x, y + 0); printf("�������  �������  �������  �������  �������   ������"); Sleep(100);
    gotoxy(x, y + 1); printf("  ���    ���        ���    ���  ���    ���    ����"); Sleep(100);
    gotoxy(x, y + 2); printf("  ���    ���        ���    �������    ���      ����"); Sleep(100);
    gotoxy(x, y + 3); printf("  ���    �������    ���    ��� ���     ���       ����"); Sleep(100);
    gotoxy(x, y + 4); printf("  ���    ���        ���    ���  ���    ���        ����"); Sleep(100);
    gotoxy(x, y + 5); printf("  ���    ���        ���    ���  ���    ���       ����"); Sleep(100);
    gotoxy(x, y + 6); printf("  ���    �������    ���    ���  ���  �������  ������"); Sleep(100);

    int defaultColor = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE;
    setColor(defaultColor);
    gotoxy(x, y + 11); printf("������ �����Ϸ��� �ƹ�Ű�� ��������");
    gotoxy(x, y + 13); printf("P R E S S  A N Y  K E Y");
    while (kbhit()) getch(); // ����� Ű ���� ����
}