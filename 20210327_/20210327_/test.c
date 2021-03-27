#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <assert.h>


//int main()
//{
//	//malloc(10*sizeof(int));
//	int* p = (int*)calloc(10, sizeof(int));
//	if (p==NULL)
//	{
//		printf("%s\n", strerror(errno));
//	}
//	else
//	{
//		int i = 0;
//		for (i = 0; i < 10;i++)
//		{
//			printf("%d ", *(p + i));
//		}
//	}
//	//释放空间
//	//free函数时用来释放动态开辟的空间的
//	free(p);
//	p = NULL;
//	return 0;
//}


//int main()
//{
//	int* p = (int*)malloc(20);
//	if (p==NULL)
//	{
//		printf("%s\n", strerror(errno));
//	}
//	else
//	{
//		int i = 0;
//		for (i = 0; i < 5;i++)
//		{
//			*(p + i) = i;
//		}
//	}
//	int* p2 = realloc(p, 40);//要用一个新的变量来接收realloc函数的返回值
//	int i = 0;
//	for (i = 5; i < 10;i++)
//	{
//		*(p + i) = i;
//	}
//	for (i = 0; i < 10;i++)
//	{
//		printf("%d ", *(p2 + i));//0 1 2 3 4 5 6 7 8 9
//	}
//	//释放内存
//	free(p);
//	p = NULL;
//	return 0;
//}


//常见的动态内存错误
//1.对NULL指针的解引用操作
//2.对动态开辟空间的越界访问
//3.对非动态开辟内存使用free释放
//4.使用free释放一块动态开辟内存的一部分
//5.对同一块动态内存多次释放
//6.动态开辟内存忘记释放（内存泄漏）
//忘记释放不再使用的动态开辟空间会造成内存泄漏


//int main()
//{
//	int* p = (int*)malloc(40);
//	//万一malloc失败 p就被赋值为NULL 要进行返回值的判断
//	int i = 0;
//	for (i = 0; i < 10;i++)
//	{
//		*(p + i) = i;
//	}
//	free(p);
//	p = NULL;
//	return 0;
//}

//int main()
//{
//	int* p = (int*)malloc(5 * sizeof(int));
//	if (p==NULL)
//	{
//		return 0;
//	}
//	else
//	{
//		int i = 0;
//		for (i = 0; i < 10;i++)
//		{
//			*(p + i) = i;//越界访问
//		}
//	}
//	free(p);
//	p = NULL;
//	return 0;
//}


//int main()
//{	
//	int a = 10;
//	int*p = &a;
//	*p = 20;//p在栈上
//	free(p);//free只能释放动态开辟的空间（在堆上）
//	p = NULL;
//	return 0;
//}


//int main()
//{
//	int* p = (int*)malloc(40);
//	if (p=NULL)
//	{
//		return 0;
//	}
//	int i = 0;
//	for (i = 0; i < 10;i++)
//	{
//		*p++ = i;//改正：*(p+i)=i
//	}
//	//回收空间
//	free(p);//p不再指向动态内存的起始位置
//	p = NULL;
//	return 0;
//}

//int main()
//{
//	int* p = (int*)malloc(40);
//	if (p=NULL)
//	{
//		return 0;
//	}
//	free(p);
//	free(p);
//	return 0;
//}

//void test()
//{
//	int* p = (int*)malloc(40);
//	if (p!=NULL)
//	{
//		*p = 20;
//	}
//}
//int main()
//{
//	test();
//	while (1);
//	return 0;
//}


//void GetMemory(char *p)
//{
//	p = (char *)malloc(100);
//	return p;
//}
//void Test(void)
//{
//	char* str = NULL;
//	GetMemory(str);
//	strcpy(str, "hello world");
//	printf(str);//=printf("%s\n",str);
//	free(str);
//	str = NULL;
//}



////返回栈空间地址的问题
//char* GetMemory(void)
//{
//	char p[] = "hello world";
//	return p;//局部变量p在栈上创建 出了函数 p指向的地址就被销毁
//}
//void Test(void)
//{
//	char* str = NULL;
//	str = GetMemory();//非法访问内存
//	printf(str);
//}
//int main()
//{
//	Test();
//	return 0;
//}


//int* test()
//{
//	static int a = 10;//栈区
//	return &a;
//}
//int main()
//{
//	int* p = test();
//	*p = 20;
//	return 0;
//}


//void GetMemory(char **p, int num)
//{
//	*p = (char *)malloc(num);//忘记释放动态开辟的内存导致内存泄漏
//}
//void Test(void)
//{
//	char *str = NULL;
//	GetMemory(&str, 100);
//	strcpy(str, "hello");
//	printf(str);//hello
//}
//int main()
//{
//	Test();
//	return 0;
//}


//void GetMemory(char **p, int num)
//{
//	*p = (char *)malloc(num);//忘记释放动态开辟的内存导致内存泄漏
//}
//void Test(void)
//{
//	char *str = NULL;
//	GetMemory(&str, 100);
//	strcpy(str, "hello");
//	printf(str);//hello
//	free(str);
//	str = NULL;
//}
//int main()
//{
//	Test();
//	return 0;
//}

//void Test(void)
//{
//	char* str = (char*)malloc(100);
//	strcpy(str, "hello");
//	free(str);//free释放str指向的空间后 并不会把str置为NULL
//	if (str!=NULL)//这个判断失效 free释放之后并没有把str置为NULL
//	{
//		strcpy(str, "world");//str已经被释放 释放的空间再次被使用 存在非法访问内存的问题
//		printf(str);//world
//	}
//}
//int main()
//{
//	Test();
//	return 0;
//}


//void Test(void)
//{
//	char* str = (char*)malloc(100);
//	strcpy(str, "hello");
//	free(str);
//	str = NULL;
//	if (str != NULL)
//	{
//		strcpy(str, "world");
//		printf(str);//不输出
//	}
//}
//int main()
//{
//	Test();
//	return 0;
//}


//struct S 
//{
//	int n;
//	int arr[];//未知大小的
//};
//struct S
//{
//	int n;
//	int arr[0];//未知大小的-柔性数组成员-数组的大小是可以调整的
//};
//int main()
//{
//	struct S s;
//	printf("%d\n", sizeof(s));//4 计算结构体大小时,不包括柔性数组成员
//	
//	//柔性数组的使用
//	struct S* ps = (struct S*)malloc(sizeof(struct S) + 5 * sizeof(int));
//	
//	return 0;
//}




//int main()
//{
//	char* p1 = "abcdef";
//	char* p2 = "def";
//	char* ret=strstr(p1, p2)；
//	if (ret == NULL)
//	{
//	      printf("子串不存在\n");
//	}
//	else
//	{
//	      printf("%s\n", ret);//def
//	}
//
//	char* p1 = "abcdef";
//	char* p2 = "defQ";
//	char* ret = strstr(p1, p2);
//	if (ret == NULL)
//	{
//	      printf("子串不存在\n");//√
//	}
//	else
//	{
//	      printf("%s\n", ret);
//	}
//
//
//	char* p1 = "abcdefabcdef";
//	char* p2 = "def";
//	char* ret = strstr(p1, p2);
//	if (ret == NULL)
//	{
//		printf("子串不存在\n");
//	}
//	else
//	{
//		printf("%s\n", ret);//defabcdef
//		//返回的是p1字符串中p2第一次出现的位置
//	}
//	return 0;
//}




char* my_strstr(const char* p1, const char* p2)
{
	assert(p1 != NULL);
	assert(p2 != NULL);
	char* s1 = (char*)p1;
	char* s2 = (char*)p2;
	char* cur = (char*)p1;//因为p1被const修饰保护 强制类型转换
	if (*p2 == '\0')
	{
		return (char*)p1;
	}
	while (*cur)
	{
		s1 = cur;
		s2 = (char*)p2;
		while (*s1 && *s2 && (*s1 == *s2))//(*s1 != '\0') && (*s2 != '\0') && (*s1  == *s2)
		{
			s1++;
			s2++;
		}
		if (*s2 == '\0')
		{
			return cur;//找到子串
		}
		cur++;
	}
	return NULL;//找不到子串
}
int main()
{
	char* p1 = "abcdefabcdef";
	char* p2 = "def";
	char* ret = my_strstr(p1, p2);
	if (ret == NULL)
	{
		printf("子串不存在\n");
	}
	else
	{
		printf("%s\n", ret);//defabcdef
		//返回的是p1字符串中p2第一次出现的位置
	}
	return 0;
}