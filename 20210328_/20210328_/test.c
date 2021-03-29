//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//
////char* my_strcpy(char* dest，const char* src)
//////1.写一个函数指针pf 能够指向my_strcpy
////char*(*pf)(char*, const char*);
//////2.写一个函数指针数组pfarr 能够存放4个my_strcpy函数的地址
////char*(*pfarr[4])(char*, const char*);
//
////int Add(int x, int y)
////{
////	return x + y;
////}
////int main()
////{
////	int arr[10] = { 0 };
////	int(*p)[10] = &arr;//数组指针
////	int(*pf)(int,int)//函数指针
////	int(*pfarr[4])(int, int);//函数指针数组
////	int(*(*ppfarr)[4]) = &pfarr;//指向函数指针数组的指针
////	//ppfarr是一个数组指针 指针指向的数组有4个元素
////	//指向的数组的每个元素的类型是一个函数指针int(*)(int,int)
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
//		printf("请选择：->");
//		scanf("%d", &input);
//		if (input >= 1 && input <= 5);
//		{
//			printf("请输入两个操作数：->");
//			scanf("%d%d", &x, &y);
//			int ret = pfarr[input](x, y);
//			printf("%d\n", ret);
//		}
//		else if(input == 0)
//		{
//			printf("退出\n");
//		}
//		else
//		{
//			printf("选择错误\n");
//		}
//
//
//		//switch (input)
//		//{
//		//case 1:
//		//	printf("请输入两个操作数：->");
//		//	scanf("%d%d", &x, &y);
//		//	printf("%d\n", add(x, y));
//		//	break;
//		//case 2:
//		//	printf("请输入两个操作数：->");
//		//	scanf("%d%d", &x, &y);
//		//	printf("%d\n", sub(x, y));
//		//	break;
//		//case 3:
//		//	printf("请输入两个操作数：->");
//		//	scanf("%d%d", &x, &y);
//		//	printf("%d\n", mul(x, y));
//		//	break;
//		//case 4:
//		//	printf("请输入两个操作数：->");
//		//	scanf("%d%d", &x, &y);
//		//	printf("%d\n", div(x, y));
//		//	break;
//		//case 0:
//		//	printf("退出\n");
//		//	break;
//		//default:
//		//	printf("选择错误\n");
//		//	break;
//		//}
//	} while (input);
//	return 0;
//}