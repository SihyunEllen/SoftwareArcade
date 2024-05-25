#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#include <time.h>
#include <conio.h>

enum ColorType {
    BLACK, darkBLUE, DarkGreen, darkSkyBlue, DarkRed,
    DarkPurple, DarkYellow, GRAY, DarkGray, BLUE,
    GREEN, SkyBlue, RED, PURPLE, YELLOW, WHITE
} COLOR; // �÷� ���� �� �� ����

#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define ENTER 13 

#define T_height 9
#define T_width 30 // Ÿ��Ʋ ���� ��ǥ
#define M_height 25
#define M_width 40 // �޴� ���� ��ǥ
#define Title_Speed 35
const int M_num = 4;
int Selected_Menu_Num = 0; // �޴� �ѹ�

void PrintTitle();
void PrintMenu(int n);
int SelectMenu();
void Delete_Menu();
void eraseTitle();
void textcolor(int color);


int main() {
    console(); // �ܼ� ũ�� ����
    removeCursor();
    int todo = -1;

    while (1) {
        switch (todo) {
        case -1: // ����ȭ��
            todo = ShowTitle();
            system("cls"); // ȭ�� �����
            break;
        case 0: // ������ũ ����
            snake();
            getch();
            system("cls");
            break;
        case 1: // ��Ʈ���� ����
            tetris();
            getch();
            system("cls");
            break;
        case 2: // ƽ���� ����
            tictactoe();
            getch();
            system("cls");
            break;
        case 3: // ����
            return 0;
        }
        system("cls");
        textcolor(WHITE);
    }

    system("cls");
    textcolor(WHITE);
    return 0;
}

int ShowTitle() {
    int select_m = -1;
    system("cls");
    while (select_m == -1) {
        textcolor(WHITE);
        PrintTitle();
        select_m = SelectMenu();
        if (select_m != -1)
            break;

        eraseTitle();
        textcolor(RED);
        PrintTitle();
        select_m = SelectMenu();
        eraseTitle();
    }
    return select_m;
}
void PrintTitle() {
    // ���� ȭ�� ������
    // ���߿� �ٹ̰ڽ��ϴ�.
}
void PrintMenu(int n) {
    char MenuArr[4][10] = { "SNAKE", "TETRIS", "TICTACTOE", "EXIT " };
    // �� ���� �� �� �ֵ���
    for (int i = 0; i < 4; i++) {
        if (n == i) {
            textcolor(darkSkyBlue);
            setCurrentCursorPos(M_width, M_height + i * 2);
            printf(">>"); // ȭ��ǥ�� ����
        }
        else {
            textcolor(GRAY); 
        }

        setCurrentCursorPos(M_width + 4, M_height + i * 2);
        for (int j = 0; j < 10; j++)
            printf("%c", MenuArr[i][j]);
    }

    setCurrentCursorPos(M_width, M_height + n * 2);
    textcolor(darkSkyBlue);
    printf(">>");
}
int SelectMenu() {
    int key;
    int arrM[4] = { 0, 1, 2, 3 };
    PrintMenu(Selected_Menu_Num);

    while (1) {
        if (_kbhit()) {
            key = _getch();
            switch (key) {
            case DOWN:
                Delete_Menu();
                Selected_Menu_Num++; // �Ʒ��� ������ �޴� �ѹ� up
                if (Selected_Menu_Num > M_num - 1) // �ǾƷ��� ������ ��� 
                    Selected_Menu_Num = 0; // ������
                PrintMenu(Selected_Menu_Num);
                break;
            case UP:
                Delete_Menu();
                Selected_Menu_Num--;
                if (Selected_Menu_Num < 0) //������ �÷��� ���
                    Selected_Menu_Num = M_num - 1; // ���� �Ʒ���
                PrintMenu(Selected_Menu_Num);
                break;
            case ENTER: // ���� ġ�� ���� ����
                return arrM[Selected_Menu_Num];
            }
        }
        Sleep(Title_Speed);
    }
}
void Delete_Menu() {
    for (int i = 0; i < 4; i++) {
        setCurrentCursorPos(M_width, M_height + i * 2);
        printf("                  ");
    }
}
void eraseTitle() {
    int n = 15;

    for (int i = 0; i < 7; i++) {
        setCurrentCursorPos(T_width + n, T_height + i);
        printf("                                              \n");
    }

    for (int i = 0; i < 7; i++) {
        setCurrentCursorPos(T_width, T_height + 8 + i);
        printf("                                                                     \n");
    }
}
