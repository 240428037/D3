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
//	//�ͷſռ�
//	//free����ʱ�����ͷŶ�̬���ٵĿռ��
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
//	int* p2 = realloc(p, 40);//Ҫ��һ���µı���������realloc�����ķ���ֵ
//	int i = 0;
//	for (i = 5; i < 10;i++)
//	{
//		*(p + i) = i;
//	}
//	for (i = 0; i < 10;i++)
//	{
//		printf("%d ", *(p2 + i));//0 1 2 3 4 5 6 7 8 9
//	}
//	//�ͷ��ڴ�
//	free(p);
//	p = NULL;
//	return 0;
//}


//�����Ķ�̬�ڴ����
//1.��NULLָ��Ľ����ò���
//2.�Զ�̬���ٿռ��Խ�����
//3.�ԷǶ�̬�����ڴ�ʹ��free�ͷ�
//4.ʹ��free�ͷ�һ�鶯̬�����ڴ��һ����
//5.��ͬһ�鶯̬�ڴ����ͷ�
//6.��̬�����ڴ������ͷţ��ڴ�й©��
//�����ͷŲ���ʹ�õĶ�̬���ٿռ������ڴ�й©


//int main()
//{
//	int* p = (int*)malloc(40);
//	//��һmallocʧ�� p�ͱ���ֵΪNULL Ҫ���з���ֵ���ж�
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
//			*(p + i) = i;//Խ�����
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
//	*p = 20;//p��ջ��
//	free(p);//freeֻ���ͷŶ�̬���ٵĿռ䣨�ڶ��ϣ�
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
//		*p++ = i;//������*(p+i)=i
//	}
//	//���տռ�
//	free(p);//p����ָ��̬�ڴ����ʼλ��
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



////����ջ�ռ��ַ������
//char* GetMemory(void)
//{
//	char p[] = "hello world";
//	return p;//�ֲ�����p��ջ�ϴ��� ���˺��� pָ��ĵ�ַ�ͱ�����
//}
//void Test(void)
//{
//	char* str = NULL;
//	str = GetMemory();//�Ƿ������ڴ�
//	printf(str);
//}
//int main()
//{
//	Test();
//	return 0;
//}


//int* test()
//{
//	static int a = 10;//ջ��
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
//	*p = (char *)malloc(num);//�����ͷŶ�̬���ٵ��ڴ浼���ڴ�й©
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
//	*p = (char *)malloc(num);//�����ͷŶ�̬���ٵ��ڴ浼���ڴ�й©
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
//	free(str);//free�ͷ�strָ��Ŀռ�� �������str��ΪNULL
//	if (str!=NULL)//����ж�ʧЧ free�ͷ�֮��û�а�str��ΪNULL
//	{
//		strcpy(str, "world");//str�Ѿ����ͷ� �ͷŵĿռ��ٴα�ʹ�� ���ڷǷ������ڴ������
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
//		printf(str);//�����
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
//	int arr[];//δ֪��С��
//};
//struct S
//{
//	int n;
//	int arr[0];//δ֪��С��-���������Ա-����Ĵ�С�ǿ��Ե�����
//};
//int main()
//{
//	struct S s;
//	printf("%d\n", sizeof(s));//4 ����ṹ���Сʱ,���������������Ա
//	
//	//���������ʹ��
//	struct S* ps = (struct S*)malloc(sizeof(struct S) + 5 * sizeof(int));
//	
//	return 0;
//}




//int main()
//{
//	char* p1 = "abcdef";
//	char* p2 = "def";
//	char* ret=strstr(p1, p2)��
//	if (ret == NULL)
//	{
//	      printf("�Ӵ�������\n");
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
//	      printf("�Ӵ�������\n");//��
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
//		printf("�Ӵ�������\n");
//	}
//	else
//	{
//		printf("%s\n", ret);//defabcdef
//		//���ص���p1�ַ�����p2��һ�γ��ֵ�λ��
//	}
//	return 0;
//}




char* my_strstr(const char* p1, const char* p2)
{
	assert(p1 != NULL);
	assert(p2 != NULL);
	char* s1 = (char*)p1;
	char* s2 = (char*)p2;
	char* cur = (char*)p1;//��Ϊp1��const���α��� ǿ������ת��
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
			return cur;//�ҵ��Ӵ�
		}
		cur++;
	}
	return NULL;//�Ҳ����Ӵ�
}
int main()
{
	char* p1 = "abcdefabcdef";
	char* p2 = "def";
	char* ret = my_strstr(p1, p2);
	if (ret == NULL)
	{
		printf("�Ӵ�������\n");
	}
	else
	{
		printf("%s\n", ret);//defabcdef
		//���ص���p1�ַ�����p2��һ�γ��ֵ�λ��
	}
	return 0;
}