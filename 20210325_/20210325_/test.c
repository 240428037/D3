#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include<assert.h>

//int main()
//{
//	int i = 0;
//	for (i = 0; i < 100;i++)
//	{
//		printf("%d ", i);
//	}
//	system("pause");
//	return 0;
//}


//int main()
//{
//	int i = 0;
//	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	for (i = 0; i <= 12;i++)
//	{
//		printf("hehe\n");
//		arr[i] = 0;
//	}
//	system("pause");
//	return 0;
//}



//int Add(int x, int y)
//{
//	return x + y;
//}
//int main()
//{
//	printf("hehe\n");
//	int a = 20;
//	int b = 10;
//	int c = Add(a, b);
//	return 0;
//}


//int main()
//{
//	int arr[10] = { 0 };
//	int i = 0;
//	for (i = 0; i < 10;i++)
//	{
//		arr[i] = i;
//	}
//	return 0;
//}



////1��+...n!
//
//int main()
//{
//	int i = 0;
//	int sum = 0;//�������ս��
//	int n = 0;
//	int ret = 1;//����n�Ľ׳�
//	scanf("%d", &n);
//	for (i = 1; i <= n;i++)
//	{
//		int j = 0;
//		ret = 1;
//		for (j = 1; j <= i;j++)
//		{
//			ret *= j;
//		}
//		sum += ret;
//	}
//	printf("%d\n", sum);
//	system("pause");
//	return 0;
//}


//int main()
//{
//	int i = 0;
//	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	for (i = 0; i <= 12;i++)
//	{
//		printf("hehe\n");
//		arr[i] = 0;
//	}
//	system("pasuse");
//	return 0;
//}
////arr[12]��iʹ�õ���ͬһ��ռ�
////ջ����Ĭ��ʹ��
////��ʹ�øߵ�ַ���Ŀռ�
////��ʹ�õ͵�ַ���Ŀռ�
//
////���������±������
////��ַ�ɵ͵��߱仯


////ģ��ʵ��strcpy
////����1
////void my_strcpy(char* dest,char* src)
////{
////	while (*src != '\0')
////	{
////		*dest = *src;
////		src++;//�ַ�ָ��
////		dest++;
////	}
////	*dest = *src;//'\0'
////}
////����2
////void my_strcpy(char* dest, char* src)
////{
////	assert(dest != NULL);//���� Ϊ��:ʲô�������� Ϊ�٣�����
////	assert(src != NULL);
////	while (*dest++ = *src++)
////	{
////		;
////	}
////}
////����3
//char* my_strcpy(char* dest, const char* src)
//{
//	char* ret = dest;
//	assert(dest != NULL);//���� Ϊ��:ʲô�������� Ϊ�٣�����
//	assert(src != NULL);
//	while (*dest++ = *src++)
//	{
//		;
//	}
//	return ret;
//	
//}
//int main()
//{
//	char arr1[] = "############";
//	char arr2[] = "bit";
//	my_strcpy(arr1, arr2);
//	printf("%s\n", arr2);
//	return 0;
//}

////ģ��ʵ��strlen
//int my_strlen(const char *str)
//{
//	int count = 0;
//	assert(str != NULL);//��ָ֤����Ч��
//	while (*str!='\0')
//	{
//		count++;
//		str++;
//	}
//	return count;
//}
//int main()
//{
//	char arr[] = "abcdef";
//	int len = my_strlen(arr);
//	printf("%d\n", len);
//}

int main()
{
	int num = 10;
	//int* p = &num;
	//*p = 20;
	//printf("%d\n", num);

	const int* p = &num;
	*p = 20;//err const����ָ�������*���ʱ ���ε���*p Ҳ����˵ ����ͨ��p���ı�*p(num)��ֵ
	printf("%d\n", num);//��

	//int* const p = &num;
	//*p = 20;
	//printf("%d\n", num);//�� 20
	//int n = 100;
	//p = &n;//err const����ָ�������*�ұ�ʱ ���ε�ָ�����p���� p���ܱ��ı�


	return 0;
}


