#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <errno.h>


//int main()
//{
//	int  a = 10000;
//	FILE* pf = fopen("text.txt", "wb");
//	fwrite(&a, 4, 1, pf);//�����Ƶ���ʽд���ļ���
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}


//FILE* fopen(const char* filename, const char* mode);
//int fclose(FILE* stream);


//int main()
//{
//	//���ļ�test.txt
//	//·����Ϊ����·�������·��
//	//����·����D:\@work\C3\20210326\20210326
//	//���·�� ����ڵ�ǰλ����
//	//.��ʾ��ǰ·��
//	//..��ʾ��һ��·��
//	FILE* pf = fopen("test.txt", "w");
//	if (pf == NULL)
//	{
//		printf("%s\n", strerror(errno));
//		return 0;
//	}
//	//�򿪳ɹ�
//	//���ļ�
//	//�ر��ļ�
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
//	//���ļ�
//	printf("%c", fgetc(pfread));
//
//	//�ر��ļ�
//	fclose(pfread);
//	pfread = NULL;
//	return 0;
//}

////�Ӽ�������
////�������Ļ
////����&��Ļ��������
////
////���� ��׼�����豸 stdin
////��Ļ ��׼����豸 stdout
////��һ������Ĭ�ϴ��������豸
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
//	//�Ӽ��̶�ȡһ���ı���Ϣ
//	char buf[1024] = { 0 };
//	//fgets(buf, 1024, stdin);//�ӱ�׼��������ȡ
//	//fputs(buf, stdout);//�������׼�����
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
//	//��ʽ����������Ϣ
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

//scanf/printf ����Ա�׼������/��׼������� ��ʽ������/������
//fscanf/fprintf ���������������/����������� ��ʽ������/������
//sscanf /sprintf sscanf�Ǵ��ַ����ж�ȡ��ʽ�������� sprintf�ǰѸ�ʽ����������ɣ��洢�����ַ���

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
//	//�Ѹ�ʽ��������ת�����ַ����洢��buf
//	sprintf(buf, "%d %f %s", s.n, s.score, s.arr);
//	//��buf�ж�ȡ��ʽ�������ݵ�tmp��
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
//	//struct S s = { "����", 20, 55.6 };
//	struct S tmp = { 0 };
//	FILE* pf = fopen("text.txt", "rb");
//	if (pf ==NULL)
//	{
//		return 0;
//	}
//	//��������ʽ���ļ�
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
