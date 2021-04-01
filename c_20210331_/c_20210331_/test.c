#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

union Un
{         //大小 默认 较小值
	int a;//4 8 4
	char arr[5];//5 1 8 1
};
int main()
{
	union Un u;
	printf("%d\n", sizeof(u));//8
}