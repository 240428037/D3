#include<iostream>
#include<vector>
using namespace std;
int split(string &str,string &sep,vector<string>&v){
    //substr(pos,x)//截取字符串-从pos位置开始截取x长度的字符串
    //find(sep,pos)//查找字符串--从pos位置开始查找sep字符串
    int count=0;
    int pos=0;
    int idx=0;
    while(1){
        pos=str.find(sep,idx);
        if(pos==npos){
            break;
        }
        v.push_back(str.substr(idx,pos-idx));
        idx+=sep.size();
        count++;
    }
    if(idx<str.size()){
        v.push_back(str.substr(idx));
        count++;
    }
    return count;
}
int main(){
    string str="fwefwaefepfewfeew";
    vector<string>v;
    int count=split(str,"e",v);
    for(auto s:v){
        cout<<s<<endl;
    }
    return 0;
}