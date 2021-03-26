#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <errno.h>


//int main()
//{
//	int  a = 10000;
//	FILE* pf = fopen("text.txt", "wb");
//	fwrite(&a, 4, 1, pf);//二进制的形式写到文件中
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}


//FILE* fopen(const char* filename, const char* mode);
//int fclose(FILE* stream);


//int main()
//{
//	//打开文件test.txt
//	//路径分为绝对路径和相对路径
//	//绝对路径：D:\@work\C3\20210326\20210326
//	//相对路径 相对于当前位置下
//	//.表示当前路径
//	//..表示上一级路径
//	FILE* pf = fopen("test.txt", "w");
//	if (pf == NULL)
//	{
//		printf("%s\n", strerror(errno));
//		return 0;
//	}
//	//打开成功
//	//读文件
//	//关闭文件
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}


//int main()
//{
//	FILE* pfread = fopen("text.txt", "r");
//	if (pfread == NULL)
//	{
//		printf("%s\n", strerror(errno));
//		return 0;
//	}
//	//读文件
//	printf("%c", fgetc(pfread));
//
//	//关闭文件
//	fclose(pfread);
//	pfread = NULL;
//	return 0;
//}

////从键盘输入
////输出到屏幕
////键盘&屏幕都是外设
////
////键盘 标准输入设备 stdin
////屏幕 标准输出设备 stdout
////是一个程序默认打开两个流设备
////
////stdin FILE*
////stdout FILE*
////stderr FILE*
//
//int main()
//{
//	int ch=fgetc(stdin);
//	fputc(ch, stdout);
//	return 0;
//}


//int main()
//{
//	char buf[1024] = { 0 };
//	FILE* pf = fopen("text.txt", "r");
//	if (pf ==NULL)
//	{
//		return 0;
//	}
//	fgets(buf, 1024, pf);
//	//printf("%s\n", buf);
//	puts(buf);
//
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//}


//int main()
//{
//	//从键盘读取一行文本信息
//	char buf[1024] = { 0 };
//	//fgets(buf, 1024, stdin);//从标准输入流读取
//	//fputs(buf, stdout);//输出到标准输出流
//
//	gets(buf);
//	puts(buf);
//
//	return 0;
//}

//struct S
//{
//	int n;
//	float score;
//	char arr[10];
//};
//int main()
//{
//	struct S s = { 0};
//	FILE* pf = fopen("test.txt", "r");
//	if (pf ==NULL)
//	{
//		return 0;
//	}
//	//格式化的输入信息
//	fscanf(pf,"%d %f %s", &(s.n), &(s.score), s.arr);
//	printf("%d %f %s\n", s.n, s.score, s.arr);
//
//	fclose(pf);
//	pf = NULL;
//}


//struct S
//{
//	int n;
//	float score;
//	char arr[10];
//};
//int main()
//{
//	struct S s = { 0 };
//	
//	fscanf(stdin, "%d %f %s", &(s.n), &(s.score), s.arr);
//	fprintf(stdout,"%d %f %s\n", s.n, s.score, s.arr);
//
//}

//scanf/printf 是针对标准输入流/标准输出流的 格式化输入/输出语句
//fscanf/fprintf 是针对所有输入流/所有输出流的 格式化输入/输出语句
//sscanf /sprintf sscanf是从字符串中读取格式化的数据 sprintf是把格式化数据输出成（存储到）字符串

//struct S
//{
//	int n;
//	float score;
//	char arr[10];
//};
//int main()
//{
//	struct S s = { 100, 3.14f, "abcde" };
//	struct S tmp = { 0 };
//	char buf[1024] = { 0 };
//	//把格式化的数据转换成字符串存储到buf
//	sprintf(buf, "%d %f %s", s.n, s.score, s.arr);
//	//从buf中读取格式化的数据到tmp中
//	sscanf(buf, "%d %f %s", &(tmp.n), &(tmp.score), tmp.arr);
//	printf("%d %f %s\n", tmp.n, tmp.score, tmp.arr);
//	return 0;
//}


//struct S
//{
//	char name[20];
//	int age;
//	double score;
//};
//int main()
//{
//	//struct S s = { "张三", 20, 55.6 };
//	struct S tmp = { 0 };
//	FILE* pf = fopen("text.txt", "rb");
//	if (pf ==NULL)
//	{
//		return 0;
//	}
//	//二进制形式读文件
//	fread(&tmp, sizeof(struct S), 1, pf);
//	printf("%s %d %lf\n", tmp.name, tmp.age, tmp.score);
//
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}



int main()
{
	FILE* pf = fopen("test.txt", "r");
	if (pf == NULL)
		return 0;
	int ch = fgetc(pf);
	printf("%d\n", ch);

	fclose(pf);
	pf = NULL;

	return 0;
}
