#include "httplib.h"//""包含-在自己的路径下
using namespace httplib;//使用httplib命名空间
//
void helloworld(const Request& req, Response& res){
	res.set_content("hello wordld!", "text/plain");
}
int main(void)
{
	Server svr;//实例化一个server对象
	//svr.Get()-成员函数-注册请求与业务处理路由关系-告诉服务器哪个请求对应哪个函数进行业务处理
	//第一个参数："/hi"-URL中的path资源路径

	//svr.Get("/hi", helloworld);
	svr.Get("/hi", [](const Request& req, Response& res) {
		res.set_content("Hello World!", "text/plain");
	});
	//正则表达式
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
	svr.listen("0.0.0.0", 9000);//开始服务器监听
	//0.0.0.0是一个特殊IP地址，可以识别为本机上的任意网卡地址
	return 0;
}
