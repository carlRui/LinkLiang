/*************************************************************************
	> File Name: bin_invert.c
	> Author: ma6174
	> Mail: ma6174@163.com 
	> Created Time: Fri Apr 14 22:18:49 2023
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void binary_invert(int n);
bool arguments_is_digit(char *buff);	

int main(int argc,char *argv[])
{
	bool is_digit = false;
	int digit = 0;

	if(argc>1)
	{
		is_digit = arguments_is_digit(argv[1]);	
	}else
	{
		printf("please input digit\r\n");
		return 1;
	}
	if(is_digit)
	{
		digit = atoi(argv[1]);
		binary_invert(digit);
		printf("\r\n");
	}
	else
		printf("not is digit\r\n");
	return 0;
}

void binary_invert(int n)
{
	printf("%d",n%2);
	n/=2;
	if(n==0)
		return;
	binary_invert(n);
}

bool arguments_is_digit(char *buff)	
{
	char *index = buff;
	char ascii0 = '0';
	char ascii9 = '9';
	
	while(*index)
	{
		if(*index<ascii0||*index>ascii9)
			return false;
		index ++;
	}

	return true;
}
