#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include <errno.h>

//int main()
//{
//	//1.const如果放在指针的左边 修饰的是指针指向的内容 保证指针指向的内容不能通过指针来改变 但是指针变量本身的内容可变
//	int num = 10;
//	const int* p = &num;
//
//	*p = 20;//× const放在指针变量的*左边时 修饰的是*p 也就是说 不能通过p来改变*p(num)的值
//	printf("%d\n", num);
//
//	//int n = 100;
//	//p = &n;
//	//printf("%d\n", num);//10
//	//printf("%d\n", *p);//100
//	return 0;
//}
//
//
//int main()
//{
//	//2.const如果放在指针的右边 修饰的是指针变量本身 保证了指针变量的内容不能修改 但是指针指向的内容 可以通过指针改变
//	int num = 10;
//	int* const p = &num;
//
//	*p = 20;
//	printf("%d\n", num);//√ 20
//
//	int n = 100;
//	p = &n;//× const放在指针变量的*右边时 修饰的指针变量p本身 p不能被改变
//	printf("%d\n", num);//10
//	printf("%d\n", *p);//100
//	return 0;
//}


//int main()
//{
//	//1.const如果放在指针的左边 ，修饰的是指针指向的内容，保证指针指向的内容不能通过指针来改变，但是指针变量本身的内容可变。
//	int num = 10;
//
//	const int* p = &num;
//
//	//*p = 20;//× const放在指针变量的*左边时 修饰的是*p，也就是说，不能通过p来改变*p(num)的值
//	//printf("%d\n", num);
//
//	int n = 100;
//	p = &n;
//	printf("%d\n", num);//10
//	printf("%d\n", *p);//100
//
//	return 0;
//}


//int main()
//{
//	//2.const如果放在指针的右边，修饰的是指针变量本身，保证了指针变量的内容不能修改，但是指针指向的内容，可以通过指针改变。
//	int num = 10;
//	int* const p = &num;
//
//	//*p = 20;
//	//printf("%d\n", num);//√ 20
//
//	int n = 100;
//	p = &n;//× const放在指针变量的*右边时 修饰的指针变量p本身 p不能被改变
//	printf("%d\n", num);//10
//	printf("%d\n", *p);//100
//
//	return 0;
//}


//int main()
//{
//	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };//arr-整形有序数组
//	int k = 6;//找6
//	int sz = sizeof(arr) / sizeof(arr[0]);//计算元素个数
//	int left = 0;//左下标
//	int right = sz - 1;//右下标
//	while (left <= right)
//	{
//		int mid = (left + right) / 2;
//		if (arr[mid] > k)
//		{
//			right = mid - 1;
//		}
//		else if (arr[mid] < k)
//		{
//			left = mid + 1;
//		}
//		else
//		{
//			printf("找到了,下标是：%d\n", mid);
//			break;
//		}
//	}
//	if (left>right)
//	{
//		printf("找不到\n");
//	}
//	return 0;
//}


//int binary_search(int arr[], int k, int sz)
//{
//	//算法实现
//	int left = 0;
//	int right = sz - 1;
//	while (left <= right)// =不能丢
//	{
//		int mid = (left + right) / 2;//这句代码必须放在while循环之中，因为mid要变化
//		if (arr[mid] < k)
//		{
//			left = mid + 1;
//		}
//		else if (arr[mid]>k)
//		{
//			right = mid - 1;
//		}
//		else
//		{
//			return mid;
//		}
//	}
//	return -1;//return -1放在while循环的外面
//}
//int main()
//{
//	//二分查找
//	//在一个有序数组中查找具体的某个数
//	//如果找到了返回这个数的下标 找不到返回-1
//	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	int k = 6;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int ret = binary_search(arr, k, sz);
//	if (ret == -1)
//	{
//		printf("找不到指定的数字\n");
//	}
//	else
//	{
//		printf("找到了，下标是：%d\n", ret);
//	}
//	return 0;
//}




//void bubble_sort(int arr[], int sz)
//{
//	//确定冒泡排序的趟数
//	int i = 0;
//	for (i = 0; i < sz - 1; i++)
//	{
//		//每一趟冒泡排序
//		int j = 0;
//		for (j = 0; j < sz - 1 - i; j++)
//		{
//			if (arr[j]>arr[j + 1])
//			{
//				int tmp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = tmp;
//			}
//		}
//	}
//}
//int main()
//{
//	int arr[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
//	int i = 0;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	//对arr进行排序，排成升序:从小到大
//	bubble_sort(arr, sz);
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}




//strlen
//size_t strlen(const char* str)
//字符串以'\0'作为结束标志,strlen函数返回的是在字符串中'\0'前面出现的字符个数（不包含'\0'）
//参数指向的字符串必须要以'\0'结束
//注意函数的返回值size_t是无符号的

//int main()
//{
//	char arr[] = { 'a', 'b', 'c' };
//	int len = strlen(arr);
//	printf("%d\n", len);//15
//	return 0;
//}

//模拟实现strlen
//1.计数器
//2.递归
//3.指针-指针

//int my_strlen(const char* str)
//{
//	int count = 0;
//	assert(str != NULL);
//	while (*str)//(*str != '\0')
//	{
//		count++;
//		str++;
//	}
//	return count;
//}
//int main()
//{
//	int len = my_strlen("abc");
//	printf("%d\n", len);
//	return 0;
//}

//int main()
//{	////3-6=-3 3.6两个无符号数相减得到的是无符号数 =3 hehe
//	if (strlen("abc") - strlen("abcdef"))
//	{
//		printf("hehe\n");//hehe
//	}
//	else
//	{
//		printf("haha\n");
//	}
//	return 0;
//}


//strcpy
//char* strcpy(char* destination,const char* source)
//源字符串必须以'\0'结束
//会将源字符串中的'\0'拷贝到目标空间
//目标空间必须足够大 以确保能存放源字符串
//目标空间必须可变


////迭代1
//char* my_strcpy(char* dest, char*src)
//{
//	assert(dest != NULL);
//	assert(src != NULL);
//	char* ret = dest;
//	while (*src != '\0')
//	{
//		*dest = *src;
//		dest++;
//		src++;
//	}
//	*dest = *src;//'\0'
//	return ret;
//}
//int main()
//{
//	char arr1[] = "abcdefghi";
//	char arr2[] = "bit";
//	my_strcpy(arr1, arr2);
//	printf("%s\n", arr1);
//}

////迭代2
//char* my_strcpy(char* dest, const char*src)
//{
//	assert(dest != NULL);
//	assert(src != NULL);
//	char* ret = dest;
//	//拷贝src指向的字符串到dest指向的空间 包含'\0'
//	while (*dest++ = *src++)//'\0'的ASCII码值为0
//	{
//		;
//	}
//	return ret;//返回目的空间的起始地址
//}
//int main()
//{
//	char arr1[] = "abcdefghi";
//	char arr2[] = "bit";
//	my_strcpy(arr1, arr2);
//	printf("%s\n", arr1);
//}


//int main()
//{
//	char arr1[] = "abcdefghi";
//	char arr2[] = { 'b', 'i', 't' };//会向后越界访问
//	strcpy(arr1, arr2);
//	printf("%s\n", arr1);
//}

//int main()
//{
//	char *arr1 = "abcdef";//目标空间必须可变
//	char arr2[] = "bit";
//	strcpy(arr1, arr2);
//	printf("%s\n", arr1);//不输出
//}

//stract -字符串追加
//char* stract(char* destination,const char* source)
//源字符串必须以'\0'结束
//目标空间必须足够大 能容纳下源字符串的内容
//目标空间必须可修改

//char* my_strcat(char* dest, const char* src)
//{
//	char* ret = dest;
//	assert(dest != NULL);
//	assert(src);
//	//1.找到目的字符串的'\0'
//	while (*dest!='\0')
//	{
//		dest++;
//	}
//	//2.追加
//	while (*dest++ = *src++)
//	{
//		;
//	}
//	return ret;
//
//}
//int main()
//{
//	char arr1[30] = "hello\0xxxxxx";
//	char arr2[] = "world";
//	my_strcat(arr1, arr2);
//	printf("%s\n", arr1);
//}



//strcmp -比较两个字符串
//int strcmp(const char* str1,const char* str2)
//标准规定：
//第一个字符串大于第二个字符串 则返回大于0的数字
//第一个字符串等于第二个字符串 则返回0
//第一个字符串小于第二个字符串 则返回小于0的数组

//int main()
//{
//	char* p1 = "abcdef";//6
//	char* p2 = "sqwer";//5
//	int ret = strcmp(p1, p2);//对应字符 分别比较ASCII码值
//	printf("%d\n", ret);//-1
//	return 0;
//}



//int my_strcmp(const char* str1, const char* str2)
//{
//	assert(str1 &&str2);
//	//比较
//	while (*str1 == *str2)
//	{
//		if (*str1=='\0')
//		{
//			return 0;//相等
//		}
//		str1++;
//		str2++;
//	}
//	if (*str1 > *str2)
//		return 1;//大于
//	else
//		return -1;//小于
//}
//int main()
//{
//	char* p1 = "abc";
//	char* p2 = "abcd";
//	int ret = my_strcmp(p1, p2);
//	printf("%d\n", ret);//0
//}





//int my_strcmp(const char* str1, const char* str2)
//{
//	assert(str1 &&str2);
//	//比较
//	while (*str1 == *str2)
//	{
//		if (*str1 == '\0')
//		{
//			return 0;//相等
//		}
//		str1++;
//		str2++;
//	}
//	return(*str1 - *str2);
//}
//int main()
//{
//	char* p1 = "abc";
//	char* p2 = "abcd";
//	int ret = my_strcmp(p1, p2);
//	printf("%d\n", ret);//0
//}

//char* strncpy(char* destination, const char* source, size_t num);
//char* strncat(char* destination, const char* source, size_t num);
//int strncmp(const char* str1, const char* str2, size_t num);

//int main()
//{
//	char arr1[5] = "abc";
//	char arr2[] = "hello bit";
//	strncpy(arr1, arr2, 4);
//	return 0;
//}


//int main()
//{
//	//向内存申请10个整形空间
//	int* p =(int*) malloc(10 * sizeof(int));
//	if (p == NULL)
//	{
//		//打印错误原因的一个方式
//		printf("%s\n", strerror(errno));
//	}
//	else
//	{
//		//正常使用空间
//		int i = 0;
//		for (i = 0; i < 10;i++)
//		{
//			*(p + i) = i;
//		}
//		for (i = 0; i < 10; i++)
//		{
//			printf("%d ", *(p + i));
//		}
//	}
//	//当动态申请的空间不再使用的时候 就应该还给操作系统
//	free(p);
//	p = NULL;//因为释放p之后 p的地址没有变化
//	return 0;
//}


//int is_prime(int n)
//{
//      int j = 0;
//      for (j = 2; j < n; j++)
//      {
//             if (n%j == 0)
//                     return 0;
//      }
//      //只有一种情况 当j=n的时候才会来到这里
//      //所以不用加if(j==n)的判断条件
//      return 1;
//}
//int main()
//{
//      int i = 0;
//      for (i = 100; i <= 200;i++)
//      {
//             //判断i是否为素数
//             if (1 == is_prime(i))
//                     printf("%d ", i);
//      }
//      return 0;
//}


//int main()
//{
//	int i = 0;
//	int n = 0;
//	int ret = 1;
//	scanf("%d", &n);
//	for (i = 1; i <= n; i++)
//	{
//		ret = ret*i;
//	}
//	printf("ret=%d\n", ret);
//	return 0;
//}

//int main()
//{
//	int i = 0;
//	int n = 0;
//	int ret = 1;
//	int sum = 0;
//	//1+2+6=9
//	for (n = 1; n <= 3; n++)
//	{
//		//如果不加ret=1 第三次进入循环ret=2
//		ret = 1;
//		for (i = 1; i <= n; i++)
//		{
//			ret = ret*i;
//		}
//		//n的阶乘
//		sum = sum + ret;
//	}
//	//如果不加ret=1
//	//ret=1*1=1
//	//ret=1*1*2=2
//	//ret=2*1*2*3=12
//	printf("sum=%d\n", sum);
//	return 0;
//}


//循环

//int Fac1(int n)
//{
//      int i = 0;
//      int ret = 1;
//      for (i = 1; i <= n;i++)
//      {
//             ret *= i;
//      }
//      return ret;
//}
//
//int main()
//{
//      //求n的阶乘
//      int n = 0;
//      int ret = 0;
//      scanf("%d", &n);
//      ret = Fac1(n);
//      printf("%d\n", ret);
//      return 0;
//}

//int main()
//{
//	int arr[10] = { 1, 2, 3, 4, 5 };
//	printf("%p\n", arr);//0073FD64
//	printf("%p\n", &arr[0]);//0073FD64
//	printf("%p\n", &arr);//0073FD64 //&arr-数组的地址
//	printf("%p\n", &arr[1]); //0073FD68
//	printf("%p\n", &arr + 1);//0073FD8C
//	printf("%d\n", *arr);//1
//	return 0;
//}