#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>

////创建一个整形数组 完成对数组的操作
////1.实现函数init()初始化数组全为0
////2.实现pirnt()打印数组的每个元素
////3.实现reverse() 函数完成数组元素的逆置
//
//void init(int arr[], int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz;i++)
//	{
//		arr[i] = 0;
//	}
//}
//
//void print(int arr[], int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz;i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//}
//
//void reverse(int arr[], int sz)
//{
//	int left = 0;
//	int right = sz - 1;
//	while (left<right)
//	{
//		int tmp = arr[left];
//		arr[left] = arr[right];
//		arr[right] = tmp;
//		left++;
//		right--;
//	}
//}
//
//int main()
//{
//	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	//init(arr, sz);
//	print(arr, sz);
//	reverse(arr, sz);
//	print(arr, sz);
//	return 0;
//}

////交换数组
////将数组A中的内容和数组B中的内容进行交换
//int main()
//{
//	int arr1[] = { 1, 3, 5, 7, 9 };
//	int arr2[] = { 2, 4, 6, 8, 0 };
//	int tmp = 0;
//	int i = 0;
//	int sz = sizeof(arr1) / sizeof(arr1[0]);
//	for (i = 0; i < sz;i++)
//	{
//		tmp = arr1[i];
//		arr1[i] = arr2[i];
//		arr2[i] = tmp;
//	}
//	return 0;
//}
 

////统计二进制中1的个数
////写一个函数返回参数二进制中1的个数
////比如 15 0000 1111 4个1
//
////方法1
////整形在内存中以补码的形式存放
////补码的二进制序列中有几个1
//
////-1
////10000000 00000000 00000000 00000001
////11111111 11111111 11111111 11111110
////11111111 11111111 11111111 11111111
////-1%2=-1
////-1/2=0
////while循环终止
//
////13
////1101
////00000000 00000000 00000000 00001101
//
////int count_bit_one(int n)
////{
////	int count = 0;
////	while (n)
////	{
////		if (n%2 == 1)
////		{
////			count++;
////		}
////		n = n / 2;
////	}
////	return count;
////}
////改进：
////int count_bit_one(unsigned int n)
////{
////	int count = 0;
////	while (n)
////	{
////		if (n%2 == 1)
////		{
////			count++;
////		}
////		n = n / 2;
////	}
////	return count;
////}
//
//
////方法2
//////-1
//////10000000 00000000 00000000 00000001
//////11111111 11111111 11111111 11111110
//////11111111 11111111 11111111 11111111
//////-1&1
//////11111111 11111111 11111111 11111111
//////00000000 00000000 00000000 00000001
//////00000000 00000000 00000000 00000001
//////-1>>1&1
//////01111111 11111111 11111111 11111111
//////00000000 00000000 00000000 00000001
//////00000000 00000000 00000000 00000001
////
////int count_bit_one(int n)
////{
////	int count = 0;
////	int i = 0;
////	for (i = 0; i < 32;i++)
////	{
////		if (((n >> 1) & 1) == 1)
////		{
////			count++;
////		}
////			
////	}
////	return count;
////}
//
//
////方法3
////n=n&(n-1)
////n
////13
////1101 n
////1100 n-1
////1100 n
////1011 n-1
////1000 n
////0111 n-1
////0000 n
////会让剩下二进制序列中最右边的1消失
//int count_bit_one(int n)
//{
//	int count = 0;
//	while (n)
//	{
//		n = n&(n - 1);
//		count++;
//	}
//	return count;
//}
//
//
//int main()
//{
//	int a = 0;
//	scanf("%d", &a);
//	int count = count_bit_one(a);
//	printf("count=%d\n", count);
//	//system("pause");//system库函数 -执行系统命令 -pause(暂停)
//	return 0;
//}


//求二进制中不同位的个数
//编程实现：两个int(32位)整数m和n中 有多少个bit位不同
//输入 1999 2999
//输出 7

//int count_bit_one(int n)
//{
//	int count = 0;
//	while (n)
//	{
//		n = n&(n - 1);
//		count++;
//	}
//	return count;
//int get_diff_bit(int m, int n)
//{ 
//	int tmp = m^n;
//	return count_bit_one(tmp);
//}

//int get_diff_bit(int m, int n)
//{
//	int tmp = m^n;
//	int count = 0;
//	while (tmp)
//	{
//		tmp = tmp&(tmp - 1);
//		count++;
//	}
//}
//int main()
//{
//	int m = 0;
//	int n = 0;
//	scanf("%d%d", &m, &n);
//	int count = get_diff_bit(m, n);
//	printf("count=%d\n", count);
//	return 0;
//}


////打印二进制的奇数位和偶数位
////获取一个整数二进制序列中所有的偶数位和奇数位 分别打印出二进制序列
//
//void print(int m)
//{
//	int i = 0;
//	printf("奇数位：\n");
//	for (i = 30; i >= 0;i-=2)
//	{
//		printf("%d ", (m >> i) & 1);
//	}
//	printf("\n");
//	printf("偶数位：\n");
//	for (i = 31	; i >= 0; i -= 2)
//	{
//		printf("%d ", (m >> i) & 1);
//	}
//	printf("\n");
//}
//int main()
//{
//	int m = 0;
//	scanf("%d",&m);
//	print(m);
//	return 0;
//}


////使用指针打印数组内容
////写一个函数打印arr数组的内容 不使用数组下标 使用指针
////arr是一个整形一维数组
//void print(int* p, int sz)
//{
//	//遍历
//	int i = 0;
//	for (i = 0; i < sz;i++)
//	{
//		printf("%d ", *(p + i));
//	}
//}
//int main()
//{
//	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	print(arr, sz);
//	return 0;
//}


////用函数实现打印乘法口诀表
//
//void print_table(int n)
//{
//	int i = 0;
//	for (i = 0; i <= n;i++)
//	{
//		int j = 0;
//		for (j = 1; j <=i ;j++)
//		{
//			printf("%d*%d=%-3d ", i, j, i*j);
//		}
//		printf("\n");
//	}
//}
//int main()
//{
//	int n = 0;
//	scanf("%d",&n);
//	print_table(n);
//}

////字符串逆序（递归实现）
////编写一个函数 reverse_string(char* string)
////将参数字符串中的字符反向排列
////要求不使用库函数
//
//
//////循环的方法
////int my_strlen(char* str)
////{
////	int count = 0;
////	while (*str!='\0')
////	{
////		count++;
////		str++;
////	}
////	return count;
////}
////
////void reverse_string(char arr[])
////{
////	int left = 0;
////	int right = my_strlen(arr) - 1;
////	while (left<right)
////	{
////		int tmp = arr[left];
////		arr[left] = arr[right];
////		arr[right] = tmp;
////		left++;
////		right--;
////	}
////}
////
////int main()
////{
////	char arr[] = "abcdef";
////	reverse_string(arr);
////	printf("%s\n", arr);
////	return 0;
////}
//
//
//
////递归
////逆序a b c d e f
////1.a和f交换
////2.逆序b c d e
//
//
//
//int my_strlen(char* str)
//{
//	int count = 0;
//	while (*str!='\0')
//	{
//		count++;
//		str++;
//	}
//	return count;
//}
//void reverse_string(char arr[])
//{
//	char tmp = arr[0];
//	int len = my_strlen(arr);
//	arr[0] = arr[len - 1];
//	arr[len - 1] = '\0';
//	if (my_strlen(arr + 1) >= 2)
//		reverse_string(arr + 1);
//	arr[len - 1] = tmp;
//}
//
//int main()
//{
//	char arr[] = "abcdef";
//	reverse_string(arr);
//	printf("%s\n", arr);
//	return 0;
//}



////写一个递归函数Digitsum(n),输入一个非负整数，返回组成它的数字之和
////例如 输入1729 输出：19
//
////digitsum(1729)
////digitsum(172)+1729%10
////digitsum(17)+172%10+1729%10
////digitsum(1)+17%10+...
////1+7+2+9
//int digitsum(unsigned int num)
//{
//	if (num > 9)
//	{
//		return digitsum(num / 10) + num % 10;
//	}
//	else
//	{
//		return num;
//	}
//}
//int main()
//{
//	unsigned int num = 0;
//	scanf("%d", &num);
//	int ret = digitsum(num);
//	printf("ret=%d\n", ret);
//	return 0;
//}


////编写一个函数实现n的k次方 使用递归实现
//double pow(int n, int k)
//{
//	//n^k=n*n^(k-1)
//	if (k < 0)
//		return (1.0 / pow(n, -k));
//	if (k <= 0)
//		return 1;
//	else
//		return n*pow(n, k - 1);
//}
//int main()
//{
//	int n = 0;
//	int k = 0;
//	scanf("%d%d", &n, &k);
//	double ret = pow(n, k);
//	printf("ret=%lf\n", ret);
//	return 0;
//}