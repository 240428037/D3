#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include <errno.h>

//int main()
//{
//	//1.const�������ָ������ ���ε���ָ��ָ������� ��ָ֤��ָ������ݲ���ͨ��ָ�����ı� ����ָ�������������ݿɱ�
//	int num = 10;
//	const int* p = &num;
//
//	*p = 20;//�� const����ָ�������*���ʱ ���ε���*p Ҳ����˵ ����ͨ��p���ı�*p(num)��ֵ
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
//	//2.const�������ָ����ұ� ���ε���ָ��������� ��֤��ָ����������ݲ����޸� ����ָ��ָ������� ����ͨ��ָ��ı�
//	int num = 10;
//	int* const p = &num;
//
//	*p = 20;
//	printf("%d\n", num);//�� 20
//
//	int n = 100;
//	p = &n;//�� const����ָ�������*�ұ�ʱ ���ε�ָ�����p���� p���ܱ��ı�
//	printf("%d\n", num);//10
//	printf("%d\n", *p);//100
//	return 0;
//}


//int main()
//{
//	//1.const�������ָ������ �����ε���ָ��ָ������ݣ���ָ֤��ָ������ݲ���ͨ��ָ�����ı䣬����ָ�������������ݿɱ䡣
//	int num = 10;
//
//	const int* p = &num;
//
//	//*p = 20;//�� const����ָ�������*���ʱ ���ε���*p��Ҳ����˵������ͨ��p���ı�*p(num)��ֵ
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
//	//2.const�������ָ����ұߣ����ε���ָ�����������֤��ָ����������ݲ����޸ģ�����ָ��ָ������ݣ�����ͨ��ָ��ı䡣
//	int num = 10;
//	int* const p = &num;
//
//	//*p = 20;
//	//printf("%d\n", num);//�� 20
//
//	int n = 100;
//	p = &n;//�� const����ָ�������*�ұ�ʱ ���ε�ָ�����p���� p���ܱ��ı�
//	printf("%d\n", num);//10
//	printf("%d\n", *p);//100
//
//	return 0;
//}


//int main()
//{
//	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };//arr-������������
//	int k = 6;//��6
//	int sz = sizeof(arr) / sizeof(arr[0]);//����Ԫ�ظ���
//	int left = 0;//���±�
//	int right = sz - 1;//���±�
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
//			printf("�ҵ���,�±��ǣ�%d\n", mid);
//			break;
//		}
//	}
//	if (left>right)
//	{
//		printf("�Ҳ���\n");
//	}
//	return 0;
//}


//int binary_search(int arr[], int k, int sz)
//{
//	//�㷨ʵ��
//	int left = 0;
//	int right = sz - 1;
//	while (left <= right)// =���ܶ�
//	{
//		int mid = (left + right) / 2;//������������whileѭ��֮�У���ΪmidҪ�仯
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
//	return -1;//return -1����whileѭ��������
//}
//int main()
//{
//	//���ֲ���
//	//��һ�����������в��Ҿ����ĳ����
//	//����ҵ��˷�����������±� �Ҳ�������-1
//	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	int k = 6;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int ret = binary_search(arr, k, sz);
//	if (ret == -1)
//	{
//		printf("�Ҳ���ָ��������\n");
//	}
//	else
//	{
//		printf("�ҵ��ˣ��±��ǣ�%d\n", ret);
//	}
//	return 0;
//}




//void bubble_sort(int arr[], int sz)
//{
//	//ȷ��ð�����������
//	int i = 0;
//	for (i = 0; i < sz - 1; i++)
//	{
//		//ÿһ��ð������
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
//	//��arr���������ų�����:��С����
//	bubble_sort(arr, sz);
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}




//strlen
//size_t strlen(const char* str)
//�ַ�����'\0'��Ϊ������־,strlen�������ص������ַ�����'\0'ǰ����ֵ��ַ�������������'\0'��
//����ָ����ַ�������Ҫ��'\0'����
//ע�⺯���ķ���ֵsize_t���޷��ŵ�

//int main()
//{
//	char arr[] = { 'a', 'b', 'c' };
//	int len = strlen(arr);
//	printf("%d\n", len);//15
//	return 0;
//}

//ģ��ʵ��strlen
//1.������
//2.�ݹ�
//3.ָ��-ָ��

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
//{	////3-6=-3 3.6�����޷���������õ������޷����� =3 hehe
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
//Դ�ַ���������'\0'����
//�ὫԴ�ַ����е�'\0'������Ŀ��ռ�
//Ŀ��ռ�����㹻�� ��ȷ���ܴ��Դ�ַ���
//Ŀ��ռ����ɱ�


////����1
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

////����2
//char* my_strcpy(char* dest, const char*src)
//{
//	assert(dest != NULL);
//	assert(src != NULL);
//	char* ret = dest;
//	//����srcָ����ַ�����destָ��Ŀռ� ����'\0'
//	while (*dest++ = *src++)//'\0'��ASCII��ֵΪ0
//	{
//		;
//	}
//	return ret;//����Ŀ�Ŀռ����ʼ��ַ
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
//	char arr2[] = { 'b', 'i', 't' };//�����Խ�����
//	strcpy(arr1, arr2);
//	printf("%s\n", arr1);
//}

//int main()
//{
//	char *arr1 = "abcdef";//Ŀ��ռ����ɱ�
//	char arr2[] = "bit";
//	strcpy(arr1, arr2);
//	printf("%s\n", arr1);//�����
//}

//stract -�ַ���׷��
//char* stract(char* destination,const char* source)
//Դ�ַ���������'\0'����
//Ŀ��ռ�����㹻�� ��������Դ�ַ���������
//Ŀ��ռ������޸�

//char* my_strcat(char* dest, const char* src)
//{
//	char* ret = dest;
//	assert(dest != NULL);
//	assert(src);
//	//1.�ҵ�Ŀ���ַ�����'\0'
//	while (*dest!='\0')
//	{
//		dest++;
//	}
//	//2.׷��
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



//strcmp -�Ƚ������ַ���
//int strcmp(const char* str1,const char* str2)
//��׼�涨��
//��һ���ַ������ڵڶ����ַ��� �򷵻ش���0������
//��һ���ַ������ڵڶ����ַ��� �򷵻�0
//��һ���ַ���С�ڵڶ����ַ��� �򷵻�С��0������

//int main()
//{
//	char* p1 = "abcdef";//6
//	char* p2 = "sqwer";//5
//	int ret = strcmp(p1, p2);//��Ӧ�ַ� �ֱ�Ƚ�ASCII��ֵ
//	printf("%d\n", ret);//-1
//	return 0;
//}



//int my_strcmp(const char* str1, const char* str2)
//{
//	assert(str1 &&str2);
//	//�Ƚ�
//	while (*str1 == *str2)
//	{
//		if (*str1=='\0')
//		{
//			return 0;//���
//		}
//		str1++;
//		str2++;
//	}
//	if (*str1 > *str2)
//		return 1;//����
//	else
//		return -1;//С��
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
//	//�Ƚ�
//	while (*str1 == *str2)
//	{
//		if (*str1 == '\0')
//		{
//			return 0;//���
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
//	//���ڴ�����10�����οռ�
//	int* p =(int*) malloc(10 * sizeof(int));
//	if (p == NULL)
//	{
//		//��ӡ����ԭ���һ����ʽ
//		printf("%s\n", strerror(errno));
//	}
//	else
//	{
//		//����ʹ�ÿռ�
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
//	//����̬����Ŀռ䲻��ʹ�õ�ʱ�� ��Ӧ�û�������ϵͳ
//	free(p);
//	p = NULL;//��Ϊ�ͷ�p֮�� p�ĵ�ַû�б仯
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
//      //ֻ��һ����� ��j=n��ʱ��Ż���������
//      //���Բ��ü�if(j==n)���ж�����
//      return 1;
//}
//int main()
//{
//      int i = 0;
//      for (i = 100; i <= 200;i++)
//      {
//             //�ж�i�Ƿ�Ϊ����
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
//		//�������ret=1 �����ν���ѭ��ret=2
//		ret = 1;
//		for (i = 1; i <= n; i++)
//		{
//			ret = ret*i;
//		}
//		//n�Ľ׳�
//		sum = sum + ret;
//	}
//	//�������ret=1
//	//ret=1*1=1
//	//ret=1*1*2=2
//	//ret=2*1*2*3=12
//	printf("sum=%d\n", sum);
//	return 0;
//}


//ѭ��

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
//      //��n�Ľ׳�
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
//	printf("%p\n", &arr);//0073FD64 //&arr-����ĵ�ַ
//	printf("%p\n", &arr[1]); //0073FD68
//	printf("%p\n", &arr + 1);//0073FD8C
//	printf("%d\n", *arr);//1
//	return 0;
//}