#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#include <time.h>
#include <conio.h>

int main() {
	// snake ���� ����
	console();
	removeCursor();
	snake();
	getch();
	// snake ��

	system("cls"); // �ܼ� ȭ�� �����(���� ���� �̾)

	// tetris ���� ����
	tetris();
	getch();
	// tetris ��

	return 0;
}