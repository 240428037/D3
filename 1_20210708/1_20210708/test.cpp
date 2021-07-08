#include<iostream>
#include<string>
#include"../mongoose.h"

using namespace std;

//c-当前的连接，ev-事件，ev_data-处理完毕的数据，fn_data-传入的数据；
void callback(struct mg_connection*c, int ev, void *ev_data, void *fn_data){
	switch (ev){
	case MG_EV_HTTP_MSG://表示当前请求是一个http协议请求
	{
							//http请求数据结构
							//struct mg_http_message {
							//struct mg_str method, uri, query, proto;  // Request/response line
							//struct mg_http_header headers[MG_MAX_HTTP_HEADERS];  // Headers
							//struct mg_str body;                       // Body
							//struct mg_str message;};                  // Request line + headers + body
							struct mg_http_message*hm = (struct mg_http_message*)ev_data;
							//在终端打印请求信息
							string method;
							method.assign(hm->method.ptr, hm->method.len);
							cout << method << endl;
							string uri;
							uri.assign(hm->uri.ptr, hm->uri.len);
							cout << uri << endl;
							if (mg_http_match_uri(hm, "/hello")){
								//if(hm->method.ptr=="GET"){
								string body = "<html><body><h1>Hello</h1></body></html>";
								string header = "Content-Type:text/html\r\n";
								mg_http_reply(c, 200, header.c_str(), "%s", body.c_str());//自助组织简单响应
								//}
							}
							else if (mg_http_match_uri(hm, "/websocket")){
								//当前连接一旦升级websocket协议，则下次有数据到来触发的就是WS_MSG事件
								mg_ws_upgrade(c, hm, NULL);//确认升级websocket协议
							}
							else{
								struct mg_http_serve_opts opts = { .root_dir = "./web_root" };//请求的相对根目录
								mg_http_serve_dir(c, hm, &opts);//静态页面资源响应
							}
	}
		break;
	case MG_EV_WS_MSG://表示当前请求是一个websocket协议请求
		//struct mg_ws_message {
		//struct mg_str data;
		//uint8_t flags;  // Websocket message flags};
		//struct mg_ws_message *wm=(struct mg_ws_message*)ev_data;
		break;
	case MG_EV_CLOSE://表示当前连接断开
		break;
	default:
		break;
	}
	return;
}

int main(){
	//定义句柄-struct mg_mgr mgr;
	struct mg_mgr mgr;
	//初始化句柄-mg_mgr_init(struct mg_mgr*)
	mg_mgr_init(&mgr);
	//创建http连接
	struct mg_connection *lst_http;
	//http服务器监听连接-mg_connection*mg_http_listen
	//(struct mg_mgr*,const char* url,mg_event_handler_t fn,void*fn_data);
	//操作句柄，url-监听地址，fn-回调函数，fn_data-传入参数
	//返回值-成功返回创建的连接/失败返回NULL
	lst_http = mg_http_listen(&mgr, "0.0.0.0:9000", callback, NULL);
	if (lst_http == NULL){
		return -1;
	}
	//开始轮询监听-void mg_mgr_poll(struct mg_ngr*mgr,int ms)
	while (1){
		mg_mgr_poll(&mgr, 1000);//1000ms监听不到连接就结束-while(1)设置死循环
	}
	return 0;
}
