#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//int add(int x, int y)
//{
//	return x + y;
//}
//
//int main()
//{
//	//指针数组
//	int* arr[10];
//	//数组指针
//	int*(*pa)[10] = &arr;
//	//函数指针
//	int(*padd)(int, int) = add;//&add
//	int sum = (*padd)(1, 2);
//	int sum = padd(1, 2);//add(1,2)
//	printf("sum=%d\n", sum);
//	//函数指针数组
//	int(*parr[5])(int, int);
//	//指向函数指针数组的指针
//	int(*(*pparr)[5])(int, int) = &parr;
//	return 0;
//}



////void*类型的指针 可以接收任意类型的地址
////void*类型的指针 不能进行解引用操作
////void* 不能进行+-整数的操作
//
//int main()
//{
//	int a = 10;
//	//int* pa = &a;
//	//char* pc = (char*)&a;
//
//	//char ch = 'w';
//	void* p = &a;
//
//	//*p = 0;//非法的间接寻址
//	//void*类型的指针 不能进行解引用操作
//	
//	//p++;
//	//void* 不能进行+-整数的操作
//
//	//p = &ch;
//	//void*类型的指针 可以接收任意类型的地址
//
//	return 0;
//}






////void bubble_sort(int arr[], int sz)
////{
////	int i = 0;
////	for (i = 0; i < sz-1;i++)
////	{
////		int j = 0;
////		for (j = 0; j < sz - 1 - i;j++)
////		{
////			if (arr[j]>arr[j+1])
////			{
////				int tmp = arr[j];
////				arr[j] = arr[j + 1];
////				arr[j + 1] = tmp;
////			}
////		}
////	}
////
////}
//struct Stu 
//{
//	char name[20];
//	int age;
//};
//int cmp_int(const void* e1, const void* e2)
//{
//	//比较两个整形值的
//	return *(int*)e1 - *(int*)e2;
//}
//void test1()
//{
//	int arr[10] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	qsort(arr, sz, sizeof(arr[0]), cmp_int);
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//}
//int cmp_float(const void* e1, const void* e2)
//{
//	//比较两个整形值的
//	//方法1
//	//if (*(float*)e1 == *(float*)e2)
//	//	return 0;
//	//else if (*(float*)e1 > *(float*)e2)
//	//	return 1;
//	//else
//	//	return -1;
//	//方法2
//	return ((int)(*(float*)e1 - *(float*)e2));
//}
//void test2()
//{
//	float f[] = { 9.0, 8.0, 7.0, 6.0, 5.0, 4.0 };
//	int sz = sizeof(f) / sizeof(f[0]);
//	qsort(f, sz, sizeof(f[0]), cmp_float);
//	int j = 0;
//	for (j = 0; j < sz;j++)
//	{
//		printf("%f ", f[j]);
//	}
//}
//int cmp_stu_by_age(const void* e1, const void* e2)
//{
//	return ((struct Stu*)e1)->age - ((struct Stu*)e2)->age;
//}
//int cmp_stu_by_name(const void* e1, const void* e2)
//{
//	return strcmp(((struct Stu*)e1)->name, ((struct Stu*)e2)->name);
//}
//void test3()
//{
//	struct Stu s[3] = { { "zhangsan", 10 }, { "lisi", 30 }, { "wangwu", 20 } };
//	int sz = sizeof(s) / sizeof(s[0]);
//	qsort(s, sz, sizeof(s[0]), cmp_stu_by_age);
//	qsort(s, sz, sizeof(s[0]), cmp_stu_by_name);
//	//第一个参数：待排序手续的首元素地址
//	//第二个参数：待排序数组的元素个数
//	//第三个参数：待排序数组的每个元素的大小-单位是字节
//	//第四个参数：是函数指针 比较两个元素的所用函数的地址 -这个函数使用者自己实现
//	//函数指针的两个参数是：待比较的两个元素的地址
//}
//
////void qsort(void *base,
////			size_t num,
////			size_t width,
////	int(*cmp)(const void *elem1, const void *elem2));
//
//void swap(char* buf1,char* buf2,width)
//{
//	int i = 0;
//	for (i = 0; i < width;i++)
//	{
//		char tmp = *buf1;
//		*buf1 = &buf2;
//		*buf2 = tmp;
//		buf1++;
//		buf2++;
//	}
//}
//void bubble_sort(void* base, int sz, int width,int(*cmp)(void* e1,void* e2))
//{
//	int i = 0;
//	//趟数
//	for (i = 0; i < sz - 1;i++)
//	{
//		//每一趟比较的对数
//		int j = 0;
//		for (j = 0; j < sz - i - 1;j++)
//		{
//			//两个元素的比较
//			if (cmp((char*)base + j*width, (char*)base + (j + 1)*width)>0)
//			{
//				//交换
//				swap((char*)base + j*width, (char*)base + (j + 1)*width,width);
//				
//			}
//		}
//	}
//}
//void test4()
//{
//	int arr[10] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	bubble_sort(arr, sz,sizeof(arr[0]),cmp_int);
//}
////void test5()
////{
////	struct Stu s[3] = { { "zhangsan", 10 }, { "lisi", 30 }, { "wangwu", 20 } };
////	int sz = sizeof(s) / sizeof(s[0]);
////	bubble_sort(s,sz,sizeof(s[0]),cmp_stu_by_age());
////}
//int main()
//{
//	//test1();
// //	test2();
// //	test3();
//	test4();
//	//test5();
//	return 0;
//}

//int main()
//{
//	//一维数组
//	int a[] = { 1, 2, 3, 4 };
//	printf("%d\n", sizeof(a));//16//sizeof(数组名)-计算的数组总大小-单位是字节-16
//	printf("%d\n", sizeof(a + 0));//4
//	printf("%d\n", sizeof(*a));//4
//	printf("%d\n", sizeof(a + 1));//4
//	printf("%d\n", sizeof(a[1]));//4
//	printf("%d\n", sizeof(&a));//4//&数组名-取出的是整个数组的大小 -16
//	printf("%d\n", sizeof(*&a));//16
//	printf("%d\n", sizeof(&a + 1));//4
//	printf("%d\n", sizeof(&a[0]));//4
//	printf("%d\n", sizeof(&a[0] + 1));//4
//	return 0;
//}

//int main()
//{
//	//字符数组
//	char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
//	printf("%d\n", sizeof(arr));//6
//	printf("%d\n", sizeof(arr + 0));//4
//	printf("%d\n", sizeof(*arr));//1
//	printf("%d\n", sizeof(arr[1]));//1
//	printf("%d\n", sizeof(&arr));//4
//	printf("%d\n", sizeof(&arr + 1));//4
//	printf("%d\n", sizeof(&arr[0] + 1));//4
//
//	printf("%d\n", strlen(arr));
//	printf("%d\n", strlen(arr + 0));
//	printf("%d\n", strlen(*arr));
//	printf("%d\n", strlen(arr[1]));
//	printf("%d\n", strlen(&arr));
//	printf("%d\n", strlen(&arr + 1));
//	printf("%d\n", strlen(&arr[0] + 1));
//
//	return 0;
//}



//int main()
//{
//	char arr[] = "abcdef";
//	//printf("%d\n", sizeof(arr));//7
//	//printf("%d\n", sizeof(arr + 0));//4
//	//printf("%d\n", sizeof(*arr));//1
//	//printf("%d\n", sizeof(arr[1]));//1
//	//printf("%d\n", sizeof(&arr));//4
//	//printf("%d\n", sizeof(&arr + 1));//4
//	//printf("%d\n", sizeof(&arr[0] + 1));//4
//
//	//printf("%d\n", strlen(arr));
//	//printf("%d\n", strlen(arr + 0));
//	//printf("%d\n", strlen(*arr));
//	//printf("%d\n", strlen(arr[1]));
//	printf("%d\n", strlen(&arr));
//	printf("%d\n", strlen(&arr + 1));
//	printf("%d\n", strlen(&arr[0] + 1));
//
//	return 0;
//}



int main()
{
	char *p = "abcdef";
	//printf("%d\n", sizeof(p));//4 //计算指针变量p的大小
	//printf("%d\n", sizeof(p + 1));//4 //p+1得到的是字符b的地址
	//printf("%d\n", sizeof(*p));//1 //*p就是字符串的第一个字符
	//printf("%d\n", sizeof(p[0]));//1 //p[0]=*(p+0)='a'
	//printf("%d\n", sizeof(&p));//4
	//printf("%d\n", sizeof(&p + 1));//4 -b的地址
	//printf("%d\n", sizeof(&p[0] + 1));//4 -b的地址

	//printf("%d\n", strlen(p));//6
	//printf("%d\n", strlen(p + 1));//5 -b的地址
	//printf("%d\n", strlen(*p));//err -非法访问内存
	//printf("%d\n", strlen(p[0]));//err
	//printf("%d\n", strlen(&p));//随机值
	//printf("%d\n", strlen(&p + 1));//随机值
	//printf("%d\n", strlen(&p[0] + 1));//随机值

	return 0;
}




//int main()
//{
//	//二维数组
//	int a[3][4] = { 0 };
//
//	printf("%d\n", sizeof(a));//48
//	printf("%d\n", sizeof(a[0][0]));//4
//	printf("%d\n", sizeof(a[0]));//16//a[0]相当于第一行作为一维数组的数组名 sizeof(a[0])把数组名单独放在sizeof()内 计算的是第一行的大小
//	printf("%d\n", sizeof(a[0] + 1));//4//第一行第二个元素的地址
//	printf("%d\n", sizeof(*(a[0] + 1)));//4//(*(a[0] + 1))是第一行第二个元素 大小为4
//	printf("%d\n", sizeof(a + 1));//4//a是二维数组的数组名 a是首元素地址 二维数组首元素是第一行（把二维数组看成一维数组时 二维数组的首元素是他的第一行 a就是第一行的地址）a+1就是第二行的地址
//	printf("%d\n", sizeof(*(a + 1)));//16 第二行的地址解引用 等价于sizeof(a[1]) 计算第二行的大小 单位是字节
//	printf("%d\n", sizeof(&a[0] + 1));//4 第二行的地址
//	printf("%d\n", sizeof(*(&a[0] + 1)));//16 计算第二行的大小 单位是字节
//	printf("%d\n", sizeof(*a));//16//a是首元素地址-第一行地址-*a-第一行 计算第一行的大小
//	printf("%d\n", sizeof(a[3]));//16 //sizeof(）内的表达式不参与真实计算 
//
//	return 0;
//}





