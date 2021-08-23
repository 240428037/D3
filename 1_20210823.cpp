class Solution {
public:
    int Add(int num1, int num2) {
        if(num1==0||num2==0){
            return num1==0?num2:num1;
        }
        //没有进位的时候退出循环
        while(num2){
            int sum=num1^num2;
            //cpp不允许负数进行左移操作，强转成无符号数
            int carry=(unsigned int)((num1&num2)<<1);
            num1=sum;
            num2=carry;
        }
        return num1;
    }
};


//测试用例
//1,2
//3
//001
//010
//011
//解题思路
//^
//&
//<<
class Solution {
public:
    int Add(int num1, int num2) {
        while(num2){
            int sum=num1^num2;
            int carry=(num1&num2)<<1;
            num1=sum;
            num2=carry;
        }
        return num1;
    }
};


class Solution {
public:
     int  NumberOf1(int n) {
         int count=0;
         for(int i=0;i<32;i++){
             if(n&(1<<i)){
                 count++;
             }
         }
         return count;
     }
};


//解题思路
//32个二进制位
//&
//1<<i
class Solution {
public:
     int  NumberOf1(int n) {
         int count=0;
         for(int i=0;i<32;i++){
             if(n&(1<<i)){
                 count++;
             }
         }
         return count;
     }
};



class Solution {
public:
    //位运算,利用^的性质
    //相同为0，相异为1
    //1.两个相同的数字^结果为0
    //2.0和任何数字^结果仍为那个数
    vector<int> FindNumsAppearOnce(vector<int>& array) {
        //遍历数组，用val=0和每一个元素^，val=num1^num2;
        int val=0;
        for(auto e:array){
            val^=e;
        }
        //val二进制位中的1要么是num1的要么是num2的
        //用i标记val的二进制位从右往左哪一位第一次出现1找到break
        int i=0;
        for(;i<32;i++){
            if(val&(1<<i)){
                break;
            }
        }
        //为1的第i要么是num1的要么是num2的
        //分组异或
        int num1=0;
        int num2=0;
        for(auto e:array){
            if(e&(1<<i)){
                num1^=e;
            }else{
                num2^=e;
            }
        }
        //处理小的在前大的在后这个条件
        int val1=num1>num2?num2:num1;
        int val2=num1>num2?num1:num2;
        vector<int>v;
        v.push_back(val1);
        v.push_back(val2);
        return v;
    }
};