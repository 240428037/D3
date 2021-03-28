//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//#include <stdlib.h>
//
//
//////struct S
//////{
//////	int n;
//////	int arr[];//未知大小的
//////};
////struct S
////{
////	int n;
////	int arr[0];//未知大小的 -柔性数组成员 -数组的大小是可以调整的
////};
////
////int main()
////{
////	struct S s;
////	printf("%d\n", sizeof(s));//4 -计算结构体大小的时候 不包含柔性数组成员
////	struct S* ps =(struct S*) malloc(sizeof(struct S) + 5 * sizeof(int));
////	ps->n = 100;
////	int i = 0;
////	for (i = 0; i < 5;i++)
////	{
////		ps->arr[i] = i;//0 1 2 3 4
////	}
////	struct S* ptr = realloc(ps, 44);
////	if (ptr!=NULL)
////	{
////		ps = ptr;
////	}
////	for (i = 5; i < 10;i++)
////	{
////		ps->arr[i] = i;
////	}
////	for (i = 0; i < 10;i++)
////	{
////		printf("%d ", ps->arr[i]);//0 1 2 3 4 5 6 7 8 9
////	}
////	//释放
////	free(ps);
////	ps = NULL;
////	return 0;
////}
//
//
////struct S
////{
////	int n;
////	int* arr;
////};
////int main()
////{
////	struct S*ps = (struct S*)malloc(sizeof(struct S));
////	ps->arr = malloc(5 * sizeof(int));
////	int i = 0;
////	for (i = 0; i < 5;i++)
////	{
////		ps->arr[i] = i;
////	}
////	for (i = 0; i < 5;i++)
////	{
////		printf("%d ", ps->arr[i]);
////	}
////	//调整大小
////	int* ptr=realloc(ps->arr, 10 * sizeof(int));
////	if (ptr!=NULL)
////	{
////		ps->arr = ptr;
////	}
////	for (i = 5; i < 10;i++)
////	{
////		ps->arr[i] = i;
////	}
////	for (i = 0; i < 10; i++)
////	{
////		printf("%d ", ps->arr[i]);
////	}
////	free(ps->arr);//先释放
////	ps->arr = NULL;
////	free(ps);//后释放 如果先释放 后面就会找不到ps->arr
////	ps = NULL;
////	return 0;
////}
//
////void test(int arr[])//数组首元素的地址 用指针存放
////{
////	int sz = sizeof(arr) / sizeof(arr[0]);
////	printf("%d\n", sz);//1 //32位机器
////}
////int main()
////{
////	int arr[10] = { 0 };
////	test(arr);
////	return 0;
////}
//
////int main()
////{
////	char ch = 'w';
////	char* pc = &ch;
////	return 0;
////}
//
////int main()
////{
////	char arr[] = "abcdef";
////	char* pc = arr;
////	printf("%s\n", arr);//abcdef
////	printf("%s\n", pc);//abcdef
////}
//
////int main()
////{
////	const char* p = "abcdef";//"abcdef"是一个常量字符串 实际上是把a的地址赋给p
////	*p = 'w';//常量字符串不能被修改
////	printf("%c\n", *p);//不输出
////	printf("%s\n", p);//不输出
////}
//
//
//
////int main()
////{
////	char arr1[] = "abcdef";
////	char arr2[] = "abcdef";
////	char* p1 = "abcdef";
////	char* p2 = "abcdef";
////	if (arr1==arr2)
////	{
////		printf("hehe\n");
////	}
////	else if(p1 == p2)	
////	{
////		printf("haha\n");//√
////	}
////	else
////	{
////		return 0;
////	}
////	return 0;
////}
//
//
////int main()
////{
////	//int arr[10] = { 0 };//整形数组
////	//char ch[5] = { 0 };//字符数组
////	//int* parr[4];//存放整形指针的数组 -指针数组
////	//char* pch[5];//存放字符指针的数组 -指针数组
////	return 0;
////}
//
////int main()
////{
////	int a = 10;
////	int b = 20;
////	int c = 30;
////	int d = 40;
////	int* arr[4] = { &a,&b, &c, &d };
////	int i = 0;
////	for (i = 0; i < 4;i++)
////	{
////		printf("%d ", *arr[i]);//10 20 30 40
////	}
////	return 0;
////}
//
//
////int main()
////{
////	int arr1[] = { 1, 2, 3, 4, 5 };
////	int arr2[] = { 2, 3, 4, 5, 6 };
////	int arr3[] = { 3, 4, 5, 6, 7 };
////	int* parr[] = { arr1, arr2, arr3 };
////	int i = 0;
////	for (i = 0; i < 3;i++)
////	{
////		int j = 0;
////		for (j = 0; j < 5;j++)
////		{
////			printf("%d ", *(parr[i] + j));
////		}
////		printf("\n");
////	}
////	return 0;
////}
//
//
////int main()
////{
////	//int* p = NULL;//p是整形指针 -指向整形的指针 -可以存放整形的地址
////	//char* pc = NULL;//pc是字符指针 -指向字符的指针 -可以存放字符的地址
////	////数组指针 -指向数组的指针 -存放数组的地址
////	//
////	//int arr[10] = { 0 };
////	////arr -首元素地址
////	////&arr[0] -首元素地址
////	////&arr -数组的地址
////
////	int arr[10] = { 1, 2, 3, 4, 5 };
////	int(*p) = &arr;//数组的地址要存起来
////	//p就是数组指针
////
////	return 0;
////}
//
//
////int main()
////{
////	char* arr[5];
////	char*(*pa)[5] = &arr;
////	//char* pa指向的数组的元素类型是char*
////	//*pa *说明pa是指针 pa是指针变量的名字
////	//[5] pa指向的数组是5个元素的
////	return 0;
////}
//
//
////int main()
////{
////	//int* p = NULL;//p是整形指针 -指向整形的指针 -可以存放整形的地址
////	//char* pc = NULL;//pc是字符指针 -指向字符的指针 -可以存放字符的地址
////	////数组指针 -指向数组的指针 -存放数组的地址
////
////	//int arr[10] = { 0 };
////	////arr -首元素地址
////	////&arr[0] -首元素地址
////	////&arr -数组的地址
////
////	int arr[10] = { 1, 2, 3, 4, 5 };
////	int(*p)[10] = &arr;//数组的地址要存起来
////	//p就是数组指针
////	return 0;
////}
//
//
////int main()
////{
////	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
////	int(*pa)[10] = &arr;
////	int i = 0;
////	for (i = 0; i < 10;i++)
////	{
////		printf("%d ", (*pa)[i]);//1 2 3 4 5 6 7 8 9 10
////	}
////	printf("\n");
////	for (i = 0; i < 10; i++)
////	{
////		printf("%d ", *(*pa + i));//1 2 3 4 5 6 7 8 9 10
////	}
////	printf("\n");
////	int* p = arr;
////	for (i = 0; i < 10; i++)
////	{
////		printf("%d ", *(p + i));//1 2 3 4 5 6 7 8 9 10
////	}
////	return 0;
////}
//
//////参数是数组的形式
////void print1(int arr[3][5], int x, int y)
////{
////	int i = 0;
////	int j = 0;
////	for (i = 0; i < x;i++)
////	{
////		for (j = 0; j < y; j++)
////		{
////			printf("%d ", arr[i][j]);
////		}
////		printf("\n");
////	}
////}
//////参数是指针的形式
////void print2(int(*p)[5], int x, int y)
////{
////	int i = 0;
////	for (i = 0; i < x; i++)
////	{
////		int j = 0;
////		for (j = 0; j < y; j++)
////		{
////			printf("%d ", *(*(p + i) + j));
////			*(p+i) //找到这一行
////			(*(p+i)[j])
////		}
////		printf("\n");
////	}
////}
////int main()
////{
////	int arr[3][5] = { { 1, 2, 3, 4, 5 }, { 2, 3, 4, 5, 6 }, {3,4,5,6,7} };
////	print1(arr, 3, 5);//arr -数组名-首元素地址
////	//把arr想象成一个一维数组 首元素地址就是整个第一行
////	print2(arr, 3, 5);
////	return 0;
////}
//
//
////int main()
////{
////	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
////	int i = 0;
////	int* p = arr;
////	for (i = 0; i < 10;i++)
////	{
////		printf("%d ", p[i]);//1 2 3 4 5 6 7 8 9 10
////
////		printf("%d ", *(p + i));//1 2 3 4 5 6 7 8 9 10
////
////		printf("%d ", *(arr + i));//1 2 3 4 5 6 7 8 9 10
////
////		printf("%d ", arr[i]);//1 2 3 4 5 6 7 8 9 10
////		
////		//arr[i]=*(arr+i)=*(p+i)=p[i]
////	}
////	return 0;
////}
//
//
//////参数是数组的形式
////void print1(int arr[3][5], int x, int y)
////{
////	int i = 0;
////	int j = 0;
////	for (i = 0; i < x; i++)
////	{
////		for (j = 0; j < y; j++)
////		{
////			printf("%d ", arr[i][j]);
////		}
////		printf("\n");
////	}
////}
//////参数是指针的形式
////void print2(int(*p)[5], int x, int y)
////{
////	int i = 0;
////	for (i = 0; i < x; i++)
////	{
////		int j = 0;
////		for (j = 0; j < y; j++)
////		{
////			//*(p+i) 找到这一行
////			//printf("%d ", *(*(p + i) + j));
////			//printf("%d ", (*(p + i))[j]);
////			//printf("%d ", *(p[i] + j));
////			printf("%d ", p[i][j]);
////		}
////		printf("\n");
////	}
////}
////int main()
////{
////	int arr[3][5] = { { 1, 2, 3, 4, 5 }, { 2, 3, 4, 5, 6 }, { 3, 4, 5, 6, 7 } };
////	print1(arr, 3, 5);//arr -数组名-首元素地址
////	//把arr想象成一个一维数组 首元素地址就是整个第一行
////	print2(arr, 3, 5);
////	return 0;
////}
//
////void test(int arr[])//√
////{}
////void test(int arr[10])//√
////{}
////void test(int* arr)//√
////{}
////void test2(int* arr[])//√
////{}
////void test2(int* arr[20])//√
////{}
////void test2(int** arr)//√
////{}
////int main()
////{
////	int arr[10] = { 0 };
////	int* arr2[20] = { 0 };
////	test(arr);
////	test(arr2);
////	return 0;
////}
//
////void test(int arr[3][5])//√
////{}
////void test(int arr[][5])//√ 行可以省略
////{}
////void test(int arr[3][])//× 列不能省略
////{}
////void test(int arr[][])//×
////{}
////void test(int* arr)//× 二维数组的数组名表示首元素地址 首元素地址是第一行（一维数组）
////{}
////void test(int** arr)//× 数组名是首元素地址 首元素地址是第一行 传过去的生死第一行的地址
////{}//接收的一级指针变量的地址
////void test(int* arr[5])//×
////{}
////void test(int(*arr)[5])//√
////{}
////int main()
////{
////	int arr[3][5] = { 0 };
////	test(arr);//二维数组传参
////	return 0;
////}
//
////void print(int* p, int sz)
////{
////	int i = 0;
////	for (i = 0; i < sz;i++)
////	{
////		printf("%d ", *(p + i));
////	}
////}
////int main()
////{
////	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
////	int* p = arr;
////	int sz = sizeof(arr) / sizeof(arr[0]);
////	print(p, sz);
////	return 0;
////}
//
////void test(int* p)
////{}
////int main()
////{
////	int a = 10;
////	int* p1 = &a;
////	test(&a);//√
////	test(p1);//√
////}
//
////void test(int** ptr)
////{
////	printf("num=%d\n", **ptr);
////}
////int main()
////{
////	int a = 10;
////	int* p = &a;
////	int** pp = &p;
////	test(pp);
////	test(&p);
////	return 0;
////}
//
//
////void test(int** ptr)
////{}
////int main()
////{
////	int* ptr;
////	int** pp = &ptr;
////	test(&ptr);
////	test(pp);
////	int* arr[10];//此时数组首元素的地址是 int*
////	test(arr);//指针数组（存放一级指针的数组）传参也可以
////	return 0;
////}
//
////int Add(int a, int b)
////{
////	return a + b;
////}
////int main()
////{
////	int a = 10;
////	int b = 20;
////	printf("%p\n", Add);
////	printf("%p\n", &Add);
////
////	int arr[10] = { 0 };
////	int(*p)[10] = &arr;
////
////	int(*pa)(int, int) = Add;
////	printf("%d\n", (*pa)(2, 3));//5
////
////	return 0;
////}
//
//
//
////void Print(char* str)
////{
////	printf("%s\n", str);
////}
////int main()
////{
////	void(*p)(char*) = Print;
////	(*p)("hello bit");//hello bit
////	return 0;
////}//////int Add(int a, int b){	return a + b;}int Sub(int a, int b){	return a - b;}int Mul(int a, int b){	return a*b;}int Div(int a, int b){	return a/b;}int main(){	////指针数组	//int* arr[5];	////需要一个数组 这个数组可以存放4个函数的地址 -函数指针数组	//int(*pa)(int, int) = Add;//Sub/Mul/Div	//函数指针数组	int(*parr[4])(int, int) = { Add, Sub, Mul, Div };	int i = 0;	for (i = 0; i < 4;i++)
	{
		printf("%d\n", parr[i](2, 3));//5 -1 6 0
	}	return 0;}