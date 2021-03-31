#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


////struct S
////{
////      int n;
////      int arr[];//未知大小的数组
////};
//
//
//
//struct S
//{
//	int n;
//	int arr[0];//未知大小的数组 -柔性数组成员 -数组的大小是可以调整的
//};
//int main()
//{
//	struct S s;
//	printf("%d\n", sizeof(s));//4 -计算结构体大小的时候 不包含柔性数组成员
//
//	struct S *ps = (struct S*) malloc(sizeof(struct S) + 5 * sizeof(int));
//
//	int i = 0;
//	for (i = 0; i < 5; i++)
//	{
//		ps->arr[i] = i;//0 1 2 3 4
//	}
//	for (i = 0; i < 5; i++)
//	{
//		printf("%d ", ps->arr[i]);
//	}
//
//	struct S* ptr = realloc(ps, 44);
//	if (ptr != NULL)
//	{
//		ps = ptr;
//	}
//
//	for (i = 5; i < 10; i++)
//	{
//		ps->arr[i] = i;
//	}
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", ps->arr[i]);//0 1 2 3 4 5 6 7 8 9
//	}
//
//	//释放
//	free(ps);
//	ps = NULL;
//
//	return 0;
//}


//struct S
//{
//	int n;
//	int* arr;
//};
//int main()
//{
//	struct S *ps = (struct S*)malloc(sizeof(struct S));
//	ps->arr = malloc(5 * sizeof(int));
//
//	int i = 0;
//	for (i = 0; i < 5; i++)
//	{
//		ps->arr[i] = i;
//	}
//	for (i = 0; i < 5; i++)
//	{
//		printf("%d ", ps->arr[i]);
//	}
//
//	//调整大小
//	int *ptr = realloc(ps->arr, 10 * sizeof(int));
//	if (ptr != NULL)
//	{
//		ps->arr = ptr;
//	}
//
//	for (i = 5; i < 10; i++)
//	{
//		ps->arr[i] = i;
//	}
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", ps->arr[i]);
//	}
//
//	free(ps->arr);//先释放
//	ps->arr = NULL;
//	free(ps);//后释放 如果先释放 后面就会找不到ps->arr
//	ps = NULL;
//
//	return 0;
//}



//int main()
//{
//	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int i = 0;
//	
//	//int* p = arr;
//	//for (i = 0; i < sz;i++)
//	//{
//	//      printf("%d ", *p);//1 2 3 4 5 6 7 8 9 10
//	//	  p++; 
//	//}
//
//	//for (i = 0; i < 5; i++)
//	//{
//	//      printf("%d ", *p);//1 3 5 7 9
//	//      p += 2;
//	//}
//
//	int* p = &arr[9];
//	for (i = 0; i < 5; i++)
//	{
//		printf("%d ", *p);//10 8 6 4 2
//		p -= 2;
//	}
//	return 0;
//}

//int main()
//{
//	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	printf("%d\n", &arr[9] - &arr[0]);
//	return 0;
//}