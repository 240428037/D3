//饿汉资源在程序初始化阶段完成加载-不涉及线程安全问题
//饿汉模式可能涉及初始化顺序问题
class Singleton{
private:
    //构造函数私有化private-在外部无法实例化
    //使用static修饰-成员变量静态化-实现资源共享  
    static int data;
public:
    //不管实例化多少个对象-访问的资源都是同一份-通过统一的接口进行获取
    int* getInstance(){
        return &data;
    }
}




//懒汉实现方式需要考虑线程安全问题
#include<iostream>
#include<mutex>
using namespace std;
template<class T>//模板T*
class Singleton{
private:
    //静态资源没有初始化data默认为0-static成员初始化要在类外初始化-编译器进行优化直接将将这个空的数据放到寄存器中去了-加volatile防止编译器过度优化
    //使用静态指针定义资源-资源共享延迟加载
    //初始化的是指针不初始化资源
    volatile static T* data;
    //在多线程场景下可能会导致资源重复加载
    //定义互斥锁-加锁保证线程安全
    static mutex _mutex;
public:
    T* getInstance(){
        //double check减少锁冲突提高效率
        if(data==nullptr){
            //加锁-但是如果后续使用进来还要加锁-多线程可能会存在锁冲突
            _mutex.lock();
            //如果资源为空初始化资源
            if(data==nullptr){
                data=new T()
                _mutex.unlock();//解锁
            }
        }
        return data;
    }
}