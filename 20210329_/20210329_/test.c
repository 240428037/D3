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
//	//ָ������
//	int* arr[10];
//	//����ָ��
//	int*(*pa)[10] = &arr;
//	//����ָ��
//	int(*padd)(int, int) = add;//&add
//	int sum = (*padd)(1, 2);
//	int sum = padd(1, 2);//add(1,2)
//	printf("sum=%d\n", sum);
//	//����ָ������
//	int(*parr[5])(int, int);
//	//ָ����ָ�������ָ��
//	int(*(*pparr)[5])(int, int) = &parr;
//	return 0;
//}



////void*���͵�ָ�� ���Խ����������͵ĵ�ַ
////void*���͵�ָ�� ���ܽ��н����ò���
////void* ���ܽ���+-�����Ĳ���
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
//	//*p = 0;//�Ƿ��ļ��Ѱַ
//	//void*���͵�ָ�� ���ܽ��н����ò���
//	
//	//p++;
//	//void* ���ܽ���+-�����Ĳ���
//
//	//p = &ch;
//	//void*���͵�ָ�� ���Խ����������͵ĵ�ַ
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
//	//�Ƚ���������ֵ��
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
//	//�Ƚ���������ֵ��
//	//����1
//	//if (*(float*)e1 == *(float*)e2)
//	//	return 0;
//	//else if (*(float*)e1 > *(float*)e2)
//	//	return 1;
//	//else
//	//	return -1;
//	//����2
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
//	//��һ����������������������Ԫ�ص�ַ
//	//�ڶ��������������������Ԫ�ظ���
//	//�����������������������ÿ��Ԫ�صĴ�С-��λ���ֽ�
//	//���ĸ��������Ǻ���ָ�� �Ƚ�����Ԫ�ص����ú����ĵ�ַ -�������ʹ�����Լ�ʵ��
//	//����ָ������������ǣ����Ƚϵ�����Ԫ�صĵ�ַ
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
//	//����
//	for (i = 0; i < sz - 1;i++)
//	{
//		//ÿһ�˱ȽϵĶ���
//		int j = 0;
//		for (j = 0; j < sz - i - 1;j++)
//		{
//			//����Ԫ�صıȽ�
//			if (cmp((char*)base + j*width, (char*)base + (j + 1)*width)>0)
//			{
//				//����
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
//	//һά����
//	int a[] = { 1, 2, 3, 4 };
//	printf("%d\n", sizeof(a));//16//sizeof(������)-����������ܴ�С-��λ���ֽ�-16
//	printf("%d\n", sizeof(a + 0));//4
//	printf("%d\n", sizeof(*a));//4
//	printf("%d\n", sizeof(a + 1));//4
//	printf("%d\n", sizeof(a[1]));//4
//	printf("%d\n", sizeof(&a));//4//&������-ȡ��������������Ĵ�С -16
//	printf("%d\n", sizeof(*&a));//16
//	printf("%d\n", sizeof(&a + 1));//4
//	printf("%d\n", sizeof(&a[0]));//4
//	printf("%d\n", sizeof(&a[0] + 1));//4
//	return 0;
//}

//int main()
//{
//	//�ַ�����
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
	//printf("%d\n", sizeof(p));//4 //����ָ�����p�Ĵ�С
	//printf("%d\n", sizeof(p + 1));//4 //p+1�õ������ַ�b�ĵ�ַ
	//printf("%d\n", sizeof(*p));//1 //*p�����ַ����ĵ�һ���ַ�
	//printf("%d\n", sizeof(p[0]));//1 //p[0]=*(p+0)='a'
	//printf("%d\n", sizeof(&p));//4
	//printf("%d\n", sizeof(&p + 1));//4 -b�ĵ�ַ
	//printf("%d\n", sizeof(&p[0] + 1));//4 -b�ĵ�ַ

	//printf("%d\n", strlen(p));//6
	//printf("%d\n", strlen(p + 1));//5 -b�ĵ�ַ
	//printf("%d\n", strlen(*p));//err -�Ƿ������ڴ�
	//printf("%d\n", strlen(p[0]));//err
	//printf("%d\n", strlen(&p));//���ֵ
	//printf("%d\n", strlen(&p + 1));//���ֵ
	//printf("%d\n", strlen(&p[0] + 1));//���ֵ

	return 0;
}




//int main()
//{
//	//��ά����
//	int a[3][4] = { 0 };
//
//	printf("%d\n", sizeof(a));//48
//	printf("%d\n", sizeof(a[0][0]));//4
//	printf("%d\n", sizeof(a[0]));//16//a[0]�൱�ڵ�һ����Ϊһά����������� sizeof(a[0])����������������sizeof()�� ������ǵ�һ�еĴ�С
//	printf("%d\n", sizeof(a[0] + 1));//4//��һ�еڶ���Ԫ�صĵ�ַ
//	printf("%d\n", sizeof(*(a[0] + 1)));//4//(*(a[0] + 1))�ǵ�һ�еڶ���Ԫ�� ��СΪ4
//	printf("%d\n", sizeof(a + 1));//4//a�Ƕ�ά����������� a����Ԫ�ص�ַ ��ά������Ԫ���ǵ�һ�У��Ѷ�ά���鿴��һά����ʱ ��ά�������Ԫ�������ĵ�һ�� a���ǵ�һ�еĵ�ַ��a+1���ǵڶ��еĵ�ַ
//	printf("%d\n", sizeof(*(a + 1)));//16 �ڶ��еĵ�ַ������ �ȼ���sizeof(a[1]) ����ڶ��еĴ�С ��λ���ֽ�
//	printf("%d\n", sizeof(&a[0] + 1));//4 �ڶ��еĵ�ַ
//	printf("%d\n", sizeof(*(&a[0] + 1)));//16 ����ڶ��еĴ�С ��λ���ֽ�
//	printf("%d\n", sizeof(*a));//16//a����Ԫ�ص�ַ-��һ�е�ַ-*a-��һ�� �����һ�еĴ�С
//	printf("%d\n", sizeof(a[3]));//16 //sizeof(���ڵı��ʽ��������ʵ���� 
//
//	return 0;
//}





