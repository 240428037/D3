class Solution {
public:
    static bool cmp(pair<int, int>& m, pair<int, int>& n) {
        return m.second > n.second;
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> occurrences;
        for (auto& v : nums) {
            occurrences[v]++;
        }

        // pair 的第一个元素代表数组的值，第二个元素代表了该值出现的次数
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(&cmp)> q(cmp);
        for (auto& [num, count] : occurrences) {
            if (q.size() == k) {
                if (q.top().second < count) {
                    q.pop();
                    q.emplace(num, count);
                }
            } else {
                q.emplace(num, count);
            }
        }
        vector<int> ret;
        while (!q.empty()) {
            ret.emplace_back(q.top().first);
            q.pop();
        }
        return ret;
    }
};


// 时间复杂度：O(nlogk)
// 空间复杂度：O(n)
class Solution {
public:
    // 小顶堆
    class mycomparison {
    public:
        bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs) {
            return lhs.second > rhs.second;
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // 要统计元素出现频率
        unordered_map<int, int> map; // map<nums[i],对应出现的次数>
        for (int i = 0; i < nums.size(); i++) {
            map[nums[i]]++;
        }

        // 对频率排序
        // 定义一个小顶堆，大小为k
        priority_queue<pair<int, int>, vector<pair<int, int>>, mycomparison> pri_que;

        // 用固定大小为k的小顶堆，扫面所有频率的数值
        for (unordered_map<int, int>::iterator it = map.begin(); it != map.end(); it++) {
            pri_que.push(*it);
            if (pri_que.size() > k) { // 如果堆的大小大于了K，则队列弹出，保证堆的大小一直为k
                pri_que.pop();
            }
        }

        // 找出前K个高频元素，因为小顶堆先弹出的是最小的，所以倒叙来输出到数组
        vector<int> result(k);
        for (int i = k - 1; i >= 0; i--) {
            result[i] = pri_que.top().first;
            pri_que.pop();
        }
        return result;

    }
};

//统计字符串各个字符出现的次数
#include<iostream>
#include<string>
#include<map>
using namespace std;
int main(){
    string str;
    map<char,int>map;
    while(cin>>str){
        for(int i=0;i<str.size();i++){
            map[str[i]]++;
        }
        auto it=map.begin();
        while(it!=map.end()){
            cout<<it->first<<":"<<it->second<<endl;
            it++;
        }
        map.clear();
    }
}



//不管实例化多少个对象-访问的资源都是同一份-通过统一的接口进行获取
//构造函数私有化private-在外部无法实例化
//资源在程序初始化阶段完成加载-不涉及线程安全问题
//可能涉及初始化顺序问题
class Singleton{
private:
    static int data;//使用static修饰-成员变量静态化-实现资源共享  
public:
    //向外提供一个统一接口
    int* getInstance(){
        return &data;
    }
}


使用静态指针定义资源-资源共享-延迟加载
使用volatile修饰-防止编译器过度优化
加锁保护-保证线程安全
二次检测doublecheck减少锁冲突概率-提高效率
#include<iostream>
#include<mutex>
using namespace std;
template<class T>
class Singleton{
private:
    volatile static T* data;//静态资源默认初始化为0-会直接放到寄存器中去-加volatile修饰
    static mutex _mutex;//定义个互斥锁-加锁保证线程安全
public:
    T* getInstance(){
        if(data==nullptr){//double check减少锁冲突提高效率
            _mutex.lock();//加锁-可能存在锁冲突-二次检测
            if(data==nullptr){
                data=new T()//使用时再去加载资源
            }
            _mutex.unlock();//解锁
         }
        return data;
    }
}

//懒汉实现方式需要考虑线程安全问题-在多线程场景下可能会导致资源重复加载-定义互斥锁-加锁保证线程安全
#include<iostream>
#include<mutex>
using namespace std;
template<class T>//模板T*
class Singleton{
private:
    //静态资源没有初始化data默认为0-static成员初始化要在类外初始化-编译器进行优化直接将将这个空的数据放到寄存器中去了-加volatile防止编译器过度优化
    volatile static T* data;//初始化的是指针不初始化资源
    static mutex _mutex;//加锁保证线程安全
public:
    T* getInstance(){
        //double check减少锁冲突提高效率
        if(data==nullptr){
            _mutex.lock();//加锁-但是如果后续使用进来还要加锁-多线程可能会存在锁冲突
            //如果资源为空初始化资源
            if(data==nullptr){
                data=new T()
                _mutex.unlock();//解锁
            }
        }
        return data;
    }
}