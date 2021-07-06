
#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<mysql/mysql.h>
int main(){
	//1.��ʼ��mysql���-mysql_init
	MYSQL *mysql = mysql_init(NULL);
	if (mysql == NULL){
		printf("init mysql error\n");
		return -1;
	}
	//2.����mysql������-mysql_real_connect
	if (mysql_real_connect(mysql, "127.0.0.1", "root", "", "db_blog", 0, NULL, 0) == NULL){
		printf("connect mysql server failed:%s\n,mysql_error(mysql)");
		return -1;
	}
	//3.���õ�ǰ�ͻ��˵��ַ���-mysql_set_character_set
	if (mysql_set_character_set(mysql, "utf8") != 0){
		printf("set character failed:%s\n", mysql_error(mysql));
		return -1;
	}
	//4.ѡ����������ݿ�-mysql_select_db
	if (mysql_select_db(mysql, "db_blog") != 0){
		printf("select db failed:%s\n", mysql_error(mysql));
		return -1;
	}




	//5.ִ��sql���-mysql_query
	//������
	char*sql_str = "create table if not exists tb_stu(id int,name varchar(32),info text,score  decimal(4,2),birth datetime);";
	int ret = mysql_query(mysql, sql_str);
	if (ret != 0){
		printf("query sql failed:%s\n", mysql_error(mysql));
		return -1;
	}
	//��inset
	char*sql = "insert tb_stu values(1,'zhangsan','shuai','99.456','2002-04-06 12:00:00');";
	//��update
	char*sql = "update tb_stu set name='lisi',info='better shuai'where name='zhangsan';";
	//ɾdelete
	char*sql = "delete from tb_stu where name='lisi';";
	//��select
	char*sql = "select *from tb_stu;";
	int ret = mysql_query(mysql, sql);
	if (ret != 0){
		printf("query sql failed:%s\n", mysql_error(mysql));
		return -1;
	}


	//6.�����ѯ���������-mysql_store_result
	MYSQL_RES*res = mysql_store_result(mysql);
	if (res == NULL){
		printf("store result failed:%s\n", mysql_error(mysql));
		return -1;
	}
	//7.��ȡ������е�����-mysql_num_rows
	int num_row = mysql_num_rows(res);//����
	//8.��ȡ������е�����-mysql_num_fields
	int num_col = mysql_num_fields(res);//����
	//9.���������-mysql_fetch_row
	int i = 0;
	for (i = 0; i < num_row; i++){
		MYSQL_ROW row = mysql_fetch_row(res);//res���ж�ȡλ�ÿ��ƣ�ÿ�λ�ȡ�Ķ�����һ������
		for (int j = 0; j < num_col; j++){
			printf("%s\t", row[j]);
		}
		printf("\n");
	}
	//10.�ͷŽ����-mysql_free_result
	mysql_free_result(res);
	//11.�ر����ݿ�ͻ������ӣ����پ��-mysql_close
	mysql_close(mysql);
	return 0;
}

��������������������������������
��Ȩ����������ΪCSDN������syc596����ԭ�����£���ѭCC 4.0 BY - SA��ȨЭ�飬ת���븽��ԭ�ĳ������Ӽ���������
ԭ�����ӣ�https ://blog.csdn.net/A240428037/article/details/118422661