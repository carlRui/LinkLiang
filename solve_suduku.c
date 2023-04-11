/*************************************************************************
	> File Name: solve_suduku.c
	> Author: ma6174
	> Mail: ma6174@163.com 
	> Created Time: Wed Apr 12 00:11:05 2023
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SUDOKU_ROW 9
#define SUDOKU_COL 9

unsigned sudoku_model[SUDOKU_ROW][SUDOKU_COL] = {
	{3,1,0,6,0,5,4,0,0},
	{6,8,4,2,0,0,0,0,0},
	{0,0,2,3,9,0,8,0,6},
	{9,0,0,1,0,6,7,5,0},
	{0,0,5,0,0,0,0,0,4},
	{8,0,1,7,0,3,0,0,0},
	{0,0,0,0,0,0,2,0,9},
	{0,5,0,4,0,0,6,7,0},
	{1,0,0,8,7,2,5,4,3},
};

unsigned row_data[SUDOKU_ROW][SUDOKU_COL+1];
unsigned col_data[SUDOKU_ROW][SUDOKU_COL+1];
unsigned group_data[SUDOKU_ROW][SUDOKU_COL+1];

void set_row_data(void);
void set_col_data(void);
void set_group_data(void);

int main(void)
{
	memset(row_data,0x0,sizeof(row_data));
	memset(col_data,0x0,sizeof(col_data));
	memset(group_data,0x0,sizeof(group_data));

	set_row_data();
	set_col_data();
	set_group_data();
	int i,j;
	for(i = 0;i<SUDOKU_ROW;i++)
	{
		for(j = 0;j<=SUDOKU_COL;j++)
		{
			printf("%d ",row_data[i][j]);
		}
		printf("\r\n");
	}
		printf("\r\n");

	for(i = 0;i<SUDOKU_ROW;i++)
	{
		for(j = 0;j<=SUDOKU_COL;j++)
		{
			printf("%d ",col_data[i][j]);
		}
		printf("\r\n");
	}

	return 0;
}

void set_row_data(void)
{
	int i,j,record,find;
	for(i=0;i<SUDOKU_ROW;i++)
	{
		for(j = 0,record = 0;j<SUDOKU_COL;j++)
		{
			for(find=0;find<SUDOKU_COL;find++)
			{
				if(sudoku_model[i][find]==(j+1))
				{
					break;
				}else if(find==SUDOKU_COL-1)
				{
					row_data[i][record]=j+1;
					record++;
				}
			}
		}
		row_data[i][SUDOKU_COL]=record;
	}

}
void set_col_data(void)
{
	int i,j,record,find;
	for(i=0;i<SUDOKU_COL;i++)
	{
		for(j = 0,record = 0;j<SUDOKU_ROW;j++)
		{
			for(find=0;find<SUDOKU_ROW;find++)
			{
				if(sudoku_model[find][i]==(j+1))
				{
					break;
				}else if(find==SUDOKU_COL-1)
				{
					col_data[i][record]=j+1;
					record++;
				}
			}
		}
		col_data[i][SUDOKU_ROW]=record;
	}
}


void set_group_data(void)
{
	int i,j,record,find;
	for(i=0;i<SUDOKU_ROW;i++)
	{
		for(j = 0,record = 0;j<SUDOKU_COL;j++)
		{
			for(find=0;find<SUDOKU_COL;find++)
			{
				if(sudoku_model[i][find]==(j+1))
				{
					break;
				}else if(find==SUDOKU_COL-1)
				{
					row_data[i][record]=j+1;
					record++;
				}
			}
		}
		row_data[i][SUDOKU_COL]=record;
	}

}
