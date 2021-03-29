#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//int main()
//{
//	//printf("%s\n", __FILE__);
//	//printf("%d\n", __LINE__);
//	//printf("%s\n", __DATE__);
//	//printf("%s\n", __TIME__);
//
//	//写日志文件
//	int i = 0;
//	int arr[10] = { 0 };
//	FILE* pf = fopen("log.txt", "w");
//	for (i = 0; i < 10;i++)
//	{
//		arr[i] = i;
//		fprintf(pf, "file:%s line:%d date:%s time:%s i=%d\n", __FILE__, __LINE__, __DATE__, __TIME__, i);
//		printf("%s\n", __FUNCTION__);
//	}
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}


////宏的参数不是传参 而是替换
//#define SQUARE(X) X*X()
//int main()
//{
//	//int ret = SQUARE(5);
//	////int ret=5*5
//	//printf("%d\n", ret);//25
//
//	int ret = SQUARE(5 + 1);
//	//#define SQUARE(X) X*X 
//	//5+1   5+1*5+1=11
//	printf("%d\n", ret);//11
//
//	return 0;
//}


//#define DOUBLE(X) ((X)+(X))
//int main()
//{
//	int a = 5;
//	int ret = 10 * DOUBLE(a);
//	printf("%d\n", ret);//100
//	return 0;
//}


//#define PRINT(X) printf("the value of"#X"is %d\n",X)
//int main()
//{
//	printf("hello world\n");//hello world
//	printf("hello"" world\n");//hello wold 
//	//字符串有自动连接的特点
//
//	int a = 10;
//	int b = 20;
//	PRINT(a);
//	//printf("the value of""a""is %d\n",a);
//	PRINT(b);
//
//	return 0;
//}



//#define CAT(X,Y) X##Y
//int main()
//{
//	int CLASS84 = 2019;
//	printf("%d\n", CLASS84);//2019
//	printf("%d\n", CAT(CLASS, 84));//2019
//	return 0;
//}

//#define MAX(X,Y)  (X)>(Y)?(X):(Y)
//
//int main()
//{
//	int a = 10;
//	int b = 11;
//
//	//int max = MAX(a,b);
//	//printf("%d\n", max);//11
//
//	int max = MAX(a++, b++);
//	//(a++)>(b++)?(11):(b++)
//	printf("%d\n", max);//12
//	printf("%d\n", a);//11
//	printf("%d\n", b);//13
//
//	return 0;
//}

//float Max2(float x, float y)
//{
//	return (x > y ? x : y);
//}
////int Max(int x, int y)
////{
////	return (x > y ? x : y);
////}
//#define MAX(X, Y) ((X)>(Y)?(X):(Y))
//int main()
//{
//	int a = 10;
//	int b = 20;
//
//	float c = 3.0f;
//	float d = 4.0f;
//
//	float max = Max2(c, d);
//	printf("max=%lf\n", max);
//
//	max = MAX(c, d);
//	printf("max=%lf\n", max);
//
//	//int max = Max(a, b);
//	//printf("max=%d\n", max);
//
//	//max = MAX(a, b);
//	//printf("max=%d\n", max);
//	return 0;
//}


//#define  SIZEOF(type) sizeof(type)
//int main()
//{
//	int ret = SIZEOF(int);
//	printf("%d\n", ret);
//	return 0;
//}

//#define MALLOC(num,type) (type*)malloc(num*sizeof(type))
//int main()
//{
//	int* p1 = (int*)malloc(10 * sizeof(int));
//	int* p2 = MALLOC(10, int);
//	//int*p2 =(int*)malloc(10*sizeof(int));
//}

//#define  DEBUG
//int main()
//{
//	int i = 0;
//	int arr[10] = { 0 };
//	for (i = 0; i < 10;i++)
//	{
//		arr[i] = i;
//#ifdef DEBUG
//		printf("%d ",arr[i]);
//#endif
//	}
//	return 0;
//}

//#define  DEBUG
//int main()
//{
//#if defined(DEBUG)
//	printf("hehe\n");//hehe
//#endif
//
//
//#ifdef DEBUG
//	printf("hehe\n");//hehe
//#endif
//
//#if !defined(DEBUG)
//	printf("hehe\n");//×
//#endif
//
//#ifndef DEBUG
//	printf("hehe\n");//×
//#endif
//	return 0;
//}


//int main()
//{
//#if 1==1
//	printf("haha\n");//√
//#elif 2==1
//	printf("hehe\n");//×
//#else
//	printf("heihei\n");//×
//#endif
//	return 0;
//}

#define OFFSEFOF(struct_name,member_name) (int)&(((member_name*)0)->member_name)
//#include <stddef.h>
struct S
{
	char c1;
	int a;
	char c2;
};
int main()
{
	//struct S s;
	printf("%d\n", OFFSEFOF(struct S,c1));//0
	printf("%d\n", OFFSEFOF(struct S,a));//4
	printf("%d\n", OFFSEFOF(struct S,c2));//8
	return 0;
}