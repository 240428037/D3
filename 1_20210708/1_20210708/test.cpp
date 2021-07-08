#include<iostream>
#include<string>
#include"../mongoose.h"

using namespace std;

//c-��ǰ�����ӣ�ev-�¼���ev_data-������ϵ����ݣ�fn_data-��������ݣ�
void callback(struct mg_connection*c, int ev, void *ev_data, void *fn_data){
	switch (ev){
	case MG_EV_HTTP_MSG://��ʾ��ǰ������һ��httpЭ������
	{
							//http�������ݽṹ
							//struct mg_http_message {
							//struct mg_str method, uri, query, proto;  // Request/response line
							//struct mg_http_header headers[MG_MAX_HTTP_HEADERS];  // Headers
							//struct mg_str body;                       // Body
							//struct mg_str message;};                  // Request line + headers + body
							struct mg_http_message*hm = (struct mg_http_message*)ev_data;
							//���ն˴�ӡ������Ϣ
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
								mg_http_reply(c, 200, header.c_str(), "%s", body.c_str());//������֯����Ӧ
								//}
							}
							else if (mg_http_match_uri(hm, "/websocket")){
								//��ǰ����һ������websocketЭ�飬���´������ݵ��������ľ���WS_MSG�¼�
								mg_ws_upgrade(c, hm, NULL);//ȷ������websocketЭ��
							}
							else{
								struct mg_http_serve_opts opts = { .root_dir = "./web_root" };//�������Ը�Ŀ¼
								mg_http_serve_dir(c, hm, &opts);//��̬ҳ����Դ��Ӧ
							}
	}
		break;
	case MG_EV_WS_MSG://��ʾ��ǰ������һ��websocketЭ������
		//struct mg_ws_message {
		//struct mg_str data;
		//uint8_t flags;  // Websocket message flags};
		//struct mg_ws_message *wm=(struct mg_ws_message*)ev_data;
		break;
	case MG_EV_CLOSE://��ʾ��ǰ���ӶϿ�
		break;
	default:
		break;
	}
	return;
}

int main(){
	//������-struct mg_mgr mgr;
	struct mg_mgr mgr;
	//��ʼ�����-mg_mgr_init(struct mg_mgr*)
	mg_mgr_init(&mgr);
	//����http����
	struct mg_connection *lst_http;
	//http��������������-mg_connection*mg_http_listen
	//(struct mg_mgr*,const char* url,mg_event_handler_t fn,void*fn_data);
	//���������url-������ַ��fn-�ص�������fn_data-�������
	//����ֵ-�ɹ����ش���������/ʧ�ܷ���NULL
	lst_http = mg_http_listen(&mgr, "0.0.0.0:9000", callback, NULL);
	if (lst_http == NULL){
		return -1;
	}
	//��ʼ��ѯ����-void mg_mgr_poll(struct mg_ngr*mgr,int ms)
	while (1){
		mg_mgr_poll(&mgr, 1000);//1000ms�����������Ӿͽ���-while(1)������ѭ��
	}
	return 0;
}
