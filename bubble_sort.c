/*************************************************************************
	> File Name: bubble_sort.c
	> Author: ma6174
	> Mail: ma6174@163.com 
	> Created Time: Thu Apr 13 23:43:21 2023
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void bubble_sort(int *arr,int len)
{
	int i,j,tem;
	for(i=0;i<len-1;i++)
	{
		for(j = 0;j<len-1-i;j++)
		{
			if(arr[j]>arr[j+1])
			{
				tem = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = tem;
			}
		}
	}
}

int main(void)
{
	srand((unsigned)time(NULL));
	int arr[20]={0};
	int len = sizeof(arr)/sizeof(arr[0]);
	int i;
	for(i = 0;i<len;i++)
	{
		arr[i] = rand()%100;
	}

	bubble_sort(arr,len);
	for(i = 0;i<len;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\r\n");


	return 0;
}
