//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//#include <stdlib.h>
//
//
//////struct S
//////{
//////	int n;
//////	int arr[];//δ֪��С��
//////};
////struct S
////{
////	int n;
////	int arr[0];//δ֪��С�� -���������Ա -����Ĵ�С�ǿ��Ե�����
////};
////
////int main()
////{
////	struct S s;
////	printf("%d\n", sizeof(s));//4 -����ṹ���С��ʱ�� ���������������Ա
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
////	//�ͷ�
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
////	//������С
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
////	free(ps->arr);//���ͷ�
////	ps->arr = NULL;
////	free(ps);//���ͷ� ������ͷ� ����ͻ��Ҳ���ps->arr
////	ps = NULL;
////	return 0;
////}
//
////void test(int arr[])//������Ԫ�صĵ�ַ ��ָ����
////{
////	int sz = sizeof(arr) / sizeof(arr[0]);
////	printf("%d\n", sz);//1 //32λ����
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
////	const char* p = "abcdef";//"abcdef"��һ�������ַ��� ʵ�����ǰ�a�ĵ�ַ����p
////	*p = 'w';//�����ַ������ܱ��޸�
////	printf("%c\n", *p);//�����
////	printf("%s\n", p);//�����
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
////		printf("haha\n");//��
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
////	//int arr[10] = { 0 };//��������
////	//char ch[5] = { 0 };//�ַ�����
////	//int* parr[4];//�������ָ������� -ָ������
////	//char* pch[5];//����ַ�ָ������� -ָ������
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
////	//int* p = NULL;//p������ָ�� -ָ�����ε�ָ�� -���Դ�����εĵ�ַ
////	//char* pc = NULL;//pc���ַ�ָ�� -ָ���ַ���ָ�� -���Դ���ַ��ĵ�ַ
////	////����ָ�� -ָ�������ָ�� -�������ĵ�ַ
////	//
////	//int arr[10] = { 0 };
////	////arr -��Ԫ�ص�ַ
////	////&arr[0] -��Ԫ�ص�ַ
////	////&arr -����ĵ�ַ
////
////	int arr[10] = { 1, 2, 3, 4, 5 };
////	int(*p) = &arr;//����ĵ�ַҪ������
////	//p��������ָ��
////
////	return 0;
////}
//
//
////int main()
////{
////	char* arr[5];
////	char*(*pa)[5] = &arr;
////	//char* paָ��������Ԫ��������char*
////	//*pa *˵��pa��ָ�� pa��ָ�����������
////	//[5] paָ���������5��Ԫ�ص�
////	return 0;
////}
//
//
////int main()
////{
////	//int* p = NULL;//p������ָ�� -ָ�����ε�ָ�� -���Դ�����εĵ�ַ
////	//char* pc = NULL;//pc���ַ�ָ�� -ָ���ַ���ָ�� -���Դ���ַ��ĵ�ַ
////	////����ָ�� -ָ�������ָ�� -�������ĵ�ַ
////
////	//int arr[10] = { 0 };
////	////arr -��Ԫ�ص�ַ
////	////&arr[0] -��Ԫ�ص�ַ
////	////&arr -����ĵ�ַ
////
////	int arr[10] = { 1, 2, 3, 4, 5 };
////	int(*p)[10] = &arr;//����ĵ�ַҪ������
////	//p��������ָ��
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
//////�������������ʽ
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
//////������ָ�����ʽ
////void print2(int(*p)[5], int x, int y)
////{
////	int i = 0;
////	for (i = 0; i < x; i++)
////	{
////		int j = 0;
////		for (j = 0; j < y; j++)
////		{
////			printf("%d ", *(*(p + i) + j));
////			*(p+i) //�ҵ���һ��
////			(*(p+i)[j])
////		}
////		printf("\n");
////	}
////}
////int main()
////{
////	int arr[3][5] = { { 1, 2, 3, 4, 5 }, { 2, 3, 4, 5, 6 }, {3,4,5,6,7} };
////	print1(arr, 3, 5);//arr -������-��Ԫ�ص�ַ
////	//��arr�����һ��һά���� ��Ԫ�ص�ַ����������һ��
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
//////�������������ʽ
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
//////������ָ�����ʽ
////void print2(int(*p)[5], int x, int y)
////{
////	int i = 0;
////	for (i = 0; i < x; i++)
////	{
////		int j = 0;
////		for (j = 0; j < y; j++)
////		{
////			//*(p+i) �ҵ���һ��
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
////	print1(arr, 3, 5);//arr -������-��Ԫ�ص�ַ
////	//��arr�����һ��һά���� ��Ԫ�ص�ַ����������һ��
////	print2(arr, 3, 5);
////	return 0;
////}
//
////void test(int arr[])//��
////{}
////void test(int arr[10])//��
////{}
////void test(int* arr)//��
////{}
////void test2(int* arr[])//��
////{}
////void test2(int* arr[20])//��
////{}
////void test2(int** arr)//��
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
////void test(int arr[3][5])//��
////{}
////void test(int arr[][5])//�� �п���ʡ��
////{}
////void test(int arr[3][])//�� �в���ʡ��
////{}
////void test(int arr[][])//��
////{}
////void test(int* arr)//�� ��ά�������������ʾ��Ԫ�ص�ַ ��Ԫ�ص�ַ�ǵ�һ�У�һά���飩
////{}
////void test(int** arr)//�� ����������Ԫ�ص�ַ ��Ԫ�ص�ַ�ǵ�һ�� ����ȥ��������һ�еĵ�ַ
////{}//���յ�һ��ָ������ĵ�ַ
////void test(int* arr[5])//��
////{}
////void test(int(*arr)[5])//��
////{}
////int main()
////{
////	int arr[3][5] = { 0 };
////	test(arr);//��ά���鴫��
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
////	test(&a);//��
////	test(p1);//��
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
////	int* arr[10];//��ʱ������Ԫ�صĵ�ַ�� int*
////	test(arr);//ָ�����飨���һ��ָ������飩����Ҳ����
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
////}//////int Add(int a, int b){	return a + b;}int Sub(int a, int b){	return a - b;}int Mul(int a, int b){	return a*b;}int Div(int a, int b){	return a/b;}int main(){	////ָ������	//int* arr[5];	////��Ҫһ������ ���������Դ��4�������ĵ�ַ -����ָ������	//int(*pa)(int, int) = Add;//Sub/Mul/Div	//����ָ������	int(*parr[4])(int, int) = { Add, Sub, Mul, Div };	int i = 0;	for (i = 0; i < 4;i++)
	{
		printf("%d\n", parr[i](2, 3));//5 -1 6 0
	}	return 0;}