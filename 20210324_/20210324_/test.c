#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>

////����һ���������� ��ɶ�����Ĳ���
////1.ʵ�ֺ���init()��ʼ������ȫΪ0
////2.ʵ��pirnt()��ӡ�����ÿ��Ԫ��
////3.ʵ��reverse() �����������Ԫ�ص�����
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

////��������
////������A�е����ݺ�����B�е����ݽ��н���
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
 

////ͳ�ƶ�������1�ĸ���
////дһ���������ز�����������1�ĸ���
////���� 15 0000 1111 4��1
//
////����1
////�������ڴ����Բ������ʽ���
////����Ķ������������м���1
//
////-1
////10000000 00000000 00000000 00000001
////11111111 11111111 11111111 11111110
////11111111 11111111 11111111 11111111
////-1%2=-1
////-1/2=0
////whileѭ����ֹ
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
////�Ľ���
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
////����2
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
////����3
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
////����ʣ�¶��������������ұߵ�1��ʧ
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
//	//system("pause");//system�⺯�� -ִ��ϵͳ���� -pause(��ͣ)
//	return 0;
//}


//��������в�ͬλ�ĸ���
//���ʵ�֣�����int(32λ)����m��n�� �ж��ٸ�bitλ��ͬ
//���� 1999 2999
//��� 7

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


////��ӡ�����Ƶ�����λ��ż��λ
////��ȡһ���������������������е�ż��λ������λ �ֱ��ӡ������������
//
//void print(int m)
//{
//	int i = 0;
//	printf("����λ��\n");
//	for (i = 30; i >= 0;i-=2)
//	{
//		printf("%d ", (m >> i) & 1);
//	}
//	printf("\n");
//	printf("ż��λ��\n");
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


////ʹ��ָ���ӡ��������
////дһ��������ӡarr��������� ��ʹ�������±� ʹ��ָ��
////arr��һ������һά����
//void print(int* p, int sz)
//{
//	//����
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


////�ú���ʵ�ִ�ӡ�˷��ھ���
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

////�ַ������򣨵ݹ�ʵ�֣�
////��дһ������ reverse_string(char* string)
////�������ַ����е��ַ���������
////Ҫ��ʹ�ÿ⺯��
//
//
//////ѭ���ķ���
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
////�ݹ�
////����a b c d e f
////1.a��f����
////2.����b c d e
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



////дһ���ݹ麯��Digitsum(n),����һ���Ǹ����������������������֮��
////���� ����1729 �����19
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


////��дһ������ʵ��n��k�η� ʹ�õݹ�ʵ��
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