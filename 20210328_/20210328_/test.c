//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//
////char* my_strcpy(char* dest��const char* src)
//////1.дһ������ָ��pf �ܹ�ָ��my_strcpy
////char*(*pf)(char*, const char*);
//////2.дһ������ָ������pfarr �ܹ����4��my_strcpy�����ĵ�ַ
////char*(*pfarr[4])(char*, const char*);
//
////int Add(int x, int y)
////{
////	return x + y;
////}
////int main()
////{
////	int arr[10] = { 0 };
////	int(*p)[10] = &arr;//����ָ��
////	int(*pf)(int,int)//����ָ��
////	int(*pfarr[4])(int, int);//����ָ������
////	int(*(*ppfarr)[4]) = &pfarr;//ָ����ָ�������ָ��
////	//ppfarr��һ������ָ�� ָ��ָ���������4��Ԫ��
////	//ָ��������ÿ��Ԫ�ص�������һ������ָ��int(*)(int,int)
////	return 0;
////}
//
//
////void print(char* str)
////{
////	printf("hehe:%s", str);
////}
////void test(void(*p)(char*))
////{
////	printf("test\n");
////	p("bit");
////}
////int main()
////{
////	test(print);
////	return 0;
////}
//
//
//
//void menu()
//{
//	printf("*******************************\n");
//	printf("***  1.add        2.sub    ****\n");
//	printf("***  3.sub        4.div    ****\n");
//	printf("**** 5.xor        0.exit   ***\n");
//	printf("*******************************\n");
//}
//int add(int a, int b)
//{
//	return a + b;
//}
//int sub(int a, int b)
//{
//	return a - b;
//}
//int mul(int a, int b)
//{
//	return a*b;
//}
//int div(int a, int b)
//{
//	return a / b;
//}
//int xor(int a, int b)
//{
//	return a / b;
//}
//int main()
//{
//	int input = 0;
//	int x = 0;
//	int y = 0;
//	int(*pfarr[]) = (int, int) = { 0, add, sub, mul, div,xor };
//	do
//	{
//		menu();
//		printf("��ѡ��->");
//		scanf("%d", &input);
//		if (input >= 1 && input <= 5);
//		{
//			printf("������������������->");
//			scanf("%d%d", &x, &y);
//			int ret = pfarr[input](x, y);
//			printf("%d\n", ret);
//		}
//		else if(input == 0)
//		{
//			printf("�˳�\n");
//		}
//		else
//		{
//			printf("ѡ�����\n");
//		}
//
//
//		//switch (input)
//		//{
//		//case 1:
//		//	printf("������������������->");
//		//	scanf("%d%d", &x, &y);
//		//	printf("%d\n", add(x, y));
//		//	break;
//		//case 2:
//		//	printf("������������������->");
//		//	scanf("%d%d", &x, &y);
//		//	printf("%d\n", sub(x, y));
//		//	break;
//		//case 3:
//		//	printf("������������������->");
//		//	scanf("%d%d", &x, &y);
//		//	printf("%d\n", mul(x, y));
//		//	break;
//		//case 4:
//		//	printf("������������������->");
//		//	scanf("%d%d", &x, &y);
//		//	printf("%d\n", div(x, y));
//		//	break;
//		//case 0:
//		//	printf("�˳�\n");
//		//	break;
//		//default:
//		//	printf("ѡ�����\n");
//		//	break;
//		//}
//	} while (input);
//	return 0;
//}