#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

#define ROW 9
#define COL 9

#define ROWS ROW+2
#define COLS COL+2
#define Easy_Count 10

void Initboard(char board[ROWS][COLS], int rows, int cols, char set);
void Displayboard(char board[ROWS][COLS], int row, int col);
void Setmine(char mine[ROWS][COLS],int row,int col);
void Findmine(char mine[ROWS][COLS],char show[ROWS][COLS],int row,int col);
void First_SafeMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);
void OpenMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col, int x, int y);
int get_mine(char mine[ROWS][COLS], int x, int y);




