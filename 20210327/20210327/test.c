#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <errno.h>

//int main()
//{
//	//char arr1[5] = "abc";
//	//char arr2[] = "hello bit";
//	//strncpy(arr1, arr2, 4);
//	//printf("%s\n", arr1);//hell
//
//	//char arr1[5] = "abcdef";
//	//char arr2[] = "hello bit";
//	//strncpy(arr1, arr2, 4);
//	//printf("%s\n", arr1);//helle������̠��?��
//
//	char arr1[5] = "abcdefgh";
//	char arr2[] = "bit";
//	strncpy(arr1, arr2, 6);
//	printf("%s\n", arr1);//debug errpr //bit //arr1:bit'\0''\0''\0'gh
//	return 0;
//}


//int main()
//{
//	char arr1[30] = "hello\0xxxxxxx";
//	char arr2[] = "world";
//	strncat(arr1, arr2, 3);
//	printf("%s\n", arr1);//hellowor //hellowor'\0'xxxx
//	//�ὫԴ�ַ�����'\0'׷�ӵ�Ŀ��ռ� 
//	return 0;
//}


//int main()
//{
//	const char* p1 = "abcdef";
//	char* p2 = "abcqwer";
//	int ret = strncmp(p1, p2,3);
//	printf("%d\n", ret);//0
//}


//int main()
//{
//	//char* p1 = "abcdef";
//	//char* p2 = "def";
//	//char* ret=strstr(p1, p2);
//	//if (ret == NULL)
//	//{
//	//	printf("�Ӵ�������\n");
//	//}
//	//else
//	//{
//	//	printf("%s\n", ret);//def
//	//}
//
//	//char* p1 = "abcdef";
//	//char* p2 = "defQ";
//	//char* ret = strstr(p1, p2);
//	//if (ret == NULL)
//	//{
//	//	printf("�Ӵ�������\n");//��
//	//}
//	//else
//	//{
//	//	printf("%s\n", ret);
//	//}
//
//	char* p1 = "abcdefabcdef";
//	char* p2 = "def";
//	char* ret = my_strstr(p1, p2);
//	if (ret == NULL)
//	{
//		printf("�Ӵ�������\n");
//	}
//	else
//	{
//		printf("%s\n", ret);//defabcdef
//		//���ص���p1�ַ�����p2��һ�γ��ֵ�λ��
//	}
//
//	return 0;
//}

//char* my_strstr(const char* p1, const char* p2)
//{
//	assert(p1 != NULL);
//	assert(p2 != NULL);
//	char* s1 = (char*)p1;
//	char* s2 = (char*)p2;
//	char* cur = (char*)p1;//��Ϊp1��const���α��� ǿ������ת��
//	if (*p2 == '\0')
//	{
//		return (char*)p1;
//	}
//	while (*cur)
//	{
//		s1 = cur;
//		s2 = (char*)p2;
//		while (*s1 && *s2 && (*s1 == *s2))//(*s1 != '\0') && (*s2 != '\0') && (*s1 == *s2)
//		{
//			s1++;
//			s2++;
//		}
//		if (*s2=='\0')
//		{
//			return cur;//�ҵ��Ӵ�
//		}
//		cur++;
//	}
//	return NULL;//�Ҳ����Ӵ�
//}
//int main()
//{
//	char* p1 = "abcdefabcdef";
//	char* p2 = "def";
//	char* ret = my_strstr(p1, p2);
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


//int main()
//{
//	//192.168.31.121 .
//	//192 168 31 121 
//	//zpw@bitedu.tech @ .
//	//zpw bitedu tech
//
//	//char arr[] = "zpw@bitedu.tech";
//	//char* p = "@.";
//
//	char arr[] = "192.168.31.121";
//	char* p = ".";
//
//	//zpw\0bitedu.tech
//	char buf[1024] = { 0 };
//	strcpy(buf, arr);
//	//�и�buf�е��ַ���
//
//
//	//char* ret = strtok(arr, p);
//	//printf("%s\n", ret);
//
//	//ret = strtok(NULL, p);
//	//printf("%s\n", ret);
//
//	//ret = strtok(NULL, p);
//	//printf("%s\n", ret);
//
//	char* ret = NULL;
//	for (ret = strtok(arr, p); ret != NULL; ret = strtok(NULL, p))
//	{
//		printf("%s\n", ret);
//	}
//
//	return 0;
//}


//int main()
//{
//	//char* str = strerror(0);
//	//printf("%s\n", str);//No error
//
//	//char* str = strerror(1);
//	//printf("%s\n", str);//Operation not permitted
//
//	//char* str = strerror(2);
//	//printf("%s\n", str);//No such file or directory
//
//	//������ ������Ϣ
//	//0		No error
//	//1		Operation not permitted
//	//2		No such file or directory
//	//...
//	//�Ѵ����뷭��Ϊ������Ϣ
//	//errno ��һ��ȫ�ֵĴ��������
//	//��C���ԵĿ⺯����ִ�й����� �����˴��� �ͻ�Ѷ�Ӧ�Ĵ����� ��ֵ��errno��
//
//
//	FILE* pf = fopen("test.txt", "r");
//	if (pf == NULL)
//	{
//		printf("%s\n", strerror(errno));//No such file or directory
//	}
//	else
//	{
//		printf("success\n");
//	}
//
//	return 0;
//}

//#include <ctype.h>
//int main()
//{
//	//char ch = 'W';
//	//int ret = islower(ch);
//	//printf("%d\n", ret);
//
//	//char ch = tolower('Q');
//	//putchar(ch);
//
//	char arr[] = "I AM A Student";
//	int i = 0;
//	while (arr[i])
//	{
//		if (isupper(arr[i]))
//		{
//			arr[i] = tolower(arr[i]);
//		}
//		i++;
//	}
//	printf("%s\n", arr);
//	return 0;
//}

//void* my_memcpy(void* dest, void* src, size_t num)
//{
//	void* ret = dest;
//	assert(dest != NULL);
//	assert(src != NULL);
//	while (num--)
//	{
//		*(char*)dest = *(char*)src;
//		++(char*)dest;
//		++(char*)src;
//	}
//	return ret;
//}
//int main()
//{
//	int arr1[] = { 1, 2, 3, 4, 5 };
//	int arr2[5] = { 0 };
//	my_memcpy(arr2, arr1,sizeof(arr1));
//	return 0;
//}


//void* my_memcpy(void* dest, void* src, size_t num)
//{
//	void* ret = dest;
//	assert(dest != NULL);
//	assert(src != NULL);
//	while (num--)
//	{
//		*(char*)dest = *(char*)src;
//		++(char*)dest;
//		++(char*)src;
//	}
//	return ret;
//}



//void* my_memmove(void* dest, const void* src, size_t num)
//{
//	void* ret = dest; 
//	assert(dest != NULL);
//	assert(src != NULL);
//	if (dest<src)
//	{
//		//ǰ->��
//		while (num--)
//		{
//			*(char*)dest = *(char*)src;
//			++(char*)dest;
//			++(char*)src;
//		}
//	}
//	else
//	{
//		//��->ǰ
//		while (num--)
//		{
//			*((char*)dest + num) = *((char*)src + num);
//		}
//	}
//	return ret;
//}


//void* my_memmove(void* dest, const void* src, size_t num)
//{
//	void* ret = dest;
//	assert(dest != NULL);
//	assert(src != NULL);
//	if (dest < src||dest>()src+num)
//	{
//		//ǰ->��
//	}
//	else
//	{
//		//��->ǰ
//	}
//	return ret;
//}
//int main()
//{
//	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	int i = 0;
//	my_memmove(arr + 2, arr, 20);
//	for (i = 0; i < 10;i++)
//	{
//		printf("%d ", arr[i]);//1 2 1 2 3 4 5 8 9 10					  
//	}
//	return 0;
//}


//int main()
//{
//	int arr1[] = { 1, 2, 3, 4, 5 };
//	int arr2[] = { 1, 2, 5, 4, 3 };
//	int ret = memcmp(arr1, arr2, 9);
//	printf("%d\n", ret);//-1
//}




int main()
{
	//char arr[10] = "";
	//memset(arr, '#', 10);

	int arr[10] = { 0 };
	memset(arr, 1, 10);

	return 0;
}
