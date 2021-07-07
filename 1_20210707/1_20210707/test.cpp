#include "httplib.h"//""����-���Լ���·����
using namespace httplib;//ʹ��httplib�����ռ�
//
void helloworld(const Request& req, Response& res){
	res.set_content("hello wordld!", "text/plain");
}
int main(void)
{
	Server svr;//ʵ����һ��server����
	//svr.Get()-��Ա����-ע��������ҵ����·�ɹ�ϵ-���߷������ĸ������Ӧ�ĸ���������ҵ����
	//��һ��������"/hi"-URL�е�path��Դ·��

	//svr.Get("/hi", helloworld);
	svr.Get("/hi", [](const Request& req, Response& res) {
		res.set_content("Hello World!", "text/plain");
	});
	//������ʽ
	svr.Get(R"(/numbers/(\d+))", [&](const Request& req, Response& res) {
		auto numbers = req.matches[1];
		res.set_content(numbers, "text/plain");
	});
	svr.Get("/body-header-param", [](const Request& req, Response& res) {
		if (req.has_header("Content-Length")) {
			auto val = req.get_header_value("Content-Length");
		}
		if (req.has_param("key")) {
			auto val = req.get_param_value("key");
		}
		res.set_content(req.body, "text/plain");
	});
	svr.Get("/stop", [&](const Request& req, Response& res) {
		svr.stop();
	});
	svr.listen("0.0.0.0", 9000);//��ʼ����������
	//0.0.0.0��һ������IP��ַ������ʶ��Ϊ�����ϵ�����������ַ
	return 0;
}
