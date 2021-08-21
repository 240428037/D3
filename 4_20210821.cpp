//测试用例
//They are students. 
//aeiou
//解题思路
//哈希映射
#include<iostream>
#include<string>
using namespace std;
int main(){
    string str1;
    string str2;
    getline(cin,str1);
    getline(cin,str2);
    int hash[256]={0};
    for(int i=0;i<str2.size();i++){
        hash[str2[i]]++;
    }
    string ret;
    for(int i=0;i<str1.size();i++){
        if(hash[str1[i]]==0){
            ret+=str1[i];
        }
    }
    cout<<ret<<endl;
    return 0;
}



//测试用例
//I like beijing.
//beijing. like I
//解题思路
//先翻转整个字符串
//再遍历字符串-使用迭代器遍历
//找出每个单词-对单词逆置
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(){
    string str;
    getline(cin,str);
    reverse(str.begin(),str.end());
    auto left=str.begin();
    while(left!=str.end()){
        auto right=left;
        while(right!=str.end()&&*right!=' '){
            right++;
        }
        reverse(left,right);
        if(right!=str.end()){
            left=right+1;
        }else{
            left=right;
        }
    }
    cout<<str<<endl;
    return 0;
}



//解题思路
#include<iostream>
#include<string>
using namespace std;
int main(){
    string str;
    cin>>str;
    string cur;
    string ret;
    //<=!!!
    for(int i=0;i<=str.size();i++){
        if(str[i]>='0'&&str[i]<='9'){
            cur+=str[i];
        }else{
            if(ret.size()<cur.size()){
                ret=cur;
            }else{
                cur.clear();
            }
        }
    }
    cout<<ret<<endl;
    return 0;
}




//解题思路
//众数非众数
class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> nums) {
        if(nums.empty()){
            return 0;
        }
        int result=nums[0];
        int times=1;
        //如果两个不相等就消去这两个数
        //如果存在众数最后剩下的数肯定是众数
        //i从1开始!!!
        for(int i=1;i<nums.size();i++){
            if(times==0){
                result=nums[i];
                times=1;
            }else{
                if(result==nums[i]){
                    times++;
                }else{
                    times--;
                }
            }
        }
        //判断result是不是众数
        int count=0;
        for(int i=0;i<nums.size();i++){
            if(result==nums[i]){
                count++;
            }
        }
        return count>nums.size()/2?result:0;
    }
};


//测试用例
//给定一个十进制数M，以及需要转换的进制数N。将十进制数M转化为N进制数
//7 2
//111
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(){
    string ret;
    string table="0123456789ABCDEF";
    int m;
    int n;
    cin>>m;
    cin>>n;
    bool flag=false;
    if(m<0){
        m=-m;
        flag=true;
    }
    while(m){
        ret+=table[m%n];
        m/=n;
    }
    if(flag){
        ret+='-';
    }
    reverse(ret.begin(),ret.end());
    cout<<ret<<endl;
    
}



//解题思路
//动规
#include<iostream>
#include<vector>
using namespace std;
int getmax(int a,int b){
    return a>b?a:b;
}
int main(){
    int size;
    cin>>size;
    vector<int>nums(size);
    for(int i=0;i<size;i++){
        cin>>nums[i];
    }
    int sum=nums[0];
    int max=nums[0];
    for(int i=0;i<size;i++){
        sum=getmax(sum+nums[i],nums[i]);
        if(sum>=max){
            max=sum;
        }
    }
    cout<<max<<endl;
    return 0;
}