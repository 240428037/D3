
#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<mysql/mysql.h>
int main(){
	//1.初始化mysql句柄-mysql_init
	MYSQL *mysql = mysql_init(NULL);
	if (mysql == NULL){
		printf("init mysql error\n");
		return -1;
	}
	//2.连接mysql服务器-mysql_real_connect
	if (mysql_real_connect(mysql, "127.0.0.1", "root", "", "db_blog", 0, NULL, 0) == NULL){
		printf("connect mysql server failed:%s\n,mysql_error(mysql)");
		return -1;
	}
	//3.设置当前客户端的字符集-mysql_set_character_set
	if (mysql_set_character_set(mysql, "utf8") != 0){
		printf("set character failed:%s\n", mysql_error(mysql));
		return -1;
	}
	//4.选择操作的数据库-mysql_select_db
	if (mysql_select_db(mysql, "db_blog") != 0){
		printf("select db failed:%s\n", mysql_error(mysql));
		return -1;
	}




	//5.执行sql语句-mysql_query
	//创建表
	char*sql_str = "create table if not exists tb_stu(id int,name varchar(32),info text,score  decimal(4,2),birth datetime);";
	int ret = mysql_query(mysql, sql_str);
	if (ret != 0){
		printf("query sql failed:%s\n", mysql_error(mysql));
		return -1;
	}
	//增inset
	char*sql = "insert tb_stu values(1,'zhangsan','shuai','99.456','2002-04-06 12:00:00');";
	//改update
	char*sql = "update tb_stu set name='lisi',info='better shuai'where name='zhangsan';";
	//删delete
	char*sql = "delete from tb_stu where name='lisi';";
	//查select
	char*sql = "select *from tb_stu;";
	int ret = mysql_query(mysql, sql);
	if (ret != 0){
		printf("query sql failed:%s\n", mysql_error(mysql));
		return -1;
	}


	//6.保存查询结果到本地-mysql_store_result
	MYSQL_RES*res = mysql_store_result(mysql);
	if (res == NULL){
		printf("store result failed:%s\n", mysql_error(mysql));
		return -1;
	}
	//7.获取结果集中的行数-mysql_num_rows
	int num_row = mysql_num_rows(res);//行数
	//8.获取结果集中的列数-mysql_num_fields
	int num_col = mysql_num_fields(res);//列数
	//9.遍历结果集-mysql_fetch_row
	int i = 0;
	for (i = 0; i < num_row; i++){
		MYSQL_ROW row = mysql_fetch_row(res);//res中有读取位置控制，每次获取的都是下一条数据
		for (int j = 0; j < num_col; j++){
			printf("%s\t", row[j]);
		}
		printf("\n");
	}
	//10.释放结果集-mysql_free_result
	mysql_free_result(res);
	//11.关闭数据库客户端连接，销毁句柄-mysql_close
	mysql_close(mysql);
	return 0;
}

————————————————
版权声明：本文为CSDN博主「syc596」的原创文章，遵循CC 4.0 BY - SA版权协议，转载请附上原文出处链接及本声明。
原文链接：https ://blog.csdn.net/A240428037/article/details/118422661