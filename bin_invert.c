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

void binary_invert(int n,char bit);
bool arguments_is_digit(char *buff);	
int flag_digit = 0;
char buff[100];
char buff2[100];
int i =0;
int main(int argc,char *argv[])
{
	bool is_digit = false;
	bool is_bit = false;
	int digit = 0;
	int bit = 0;
	memset(buff,0x0,sizeof(buff));
	memset(buff2,0x0,sizeof(buff2));
	if(argc>2)
	{
		is_digit = arguments_is_digit(argv[1]);	
		is_bit = arguments_is_digit(argv[2]);	
	}else
	{
		printf("please input digit and bit\r\n");
		return 1;
	}
	if(is_digit&&is_bit)
	{
		digit = atoi(argv[1]);
		bit = atoi(argv[2]);
		i =0;
		binary_invert(digit,bit);
		printf("%d->%s,%s->%d",digit,buff2,buff,flag_digit);
		printf("\r\n");
	}
	else
		printf("is not digit\r\n");
	return 0;
}
void binary_invert(int n,char bit)
{
	if(bit==0)
	{
		return;
	}
	buff[i]=n%2+'0';
	bit--;
	i++;
	binary_invert(n/2,bit);
	buff2[bit]=n%2+'0';
	flag_digit|=n%2<<bit;

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
