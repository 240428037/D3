//快排
//快排思想
//快排是一种交换排序-采用分治递归的思想完成排序
//首先从待排序的元素中取一个数作key
//遍历元素将比key大的放在key的右边-将比key小的放在key的左边
//遍历完成后数组被划分为左右两个区域左边的元素都比key小右边的元素都比key大
//然后再将左右两个区域递归求解
//-
//快排特点
//不稳定
//时间复杂度nlogn
//空间复杂度1
//-
//快排非递归
//递归调用太多导致栈帧开辟太多导致栈溢出
//非递归用stack在堆上开辟空间本质上非递归借助stack完成递归
//-
//快排什么时候效率最差？解决方法？
//数组有序或者接近有序的情况-此时时间复杂度为N^2
//优化-三数取中法选key
class Solution {
public:
    int partsort(vector<int>&nums,int left,int right){
        int key=nums[right];
        while(left<right){
            while(nums[left]<=key&&left<right){
                left++;
            }
            nums[right]=nums[left];
            while(nums[right]>=key&&left<right){
                right--;
            }
            nums[left]=nums[right];
        }
        nums[left]=key;
        return left;
    }
    void quicksort(vector<int>&nums,int left,int right){
        stack<int>st;
        st.push(left);
        st.push(right);
        while(!st.empty()){
            int right=st.top();
            st.pop();
            int left=st.top();
            st.pop();
            int pos=partsort(nums,left,right);
            if(left<pos-1){
                st.push(left);
                st.push(pos-1);
            }
            if(pos+1<right){
                st.push(pos+1);
                st.push(right);
            }
        }
    }
    vector<int> MySort(vector<int>& nums) {
        int left=0;
        int right=nums.size()-1;
        quicksort(nums,left,right);
        return nums;
    }
};




// #堆排
// #堆排思想
// 堆排是一种选择排序
// 堆排通过堆来选择数据
// 堆排升序-先把待排序元素建大堆-取出堆顶元素和最后一个元素交换-然后再调为大堆
// 然后重复这个过程-直到待排序元素全部排完
// -
// #堆排特点
// 不稳定
// 时间复杂度nlogn
// 空间复杂度1
// -
// 堆排升序建大堆
// priority_queue优先级队列默认大堆
// topk建小堆
class Solution {
public:
    void adjustdown(vector<int>&nums,int n,int root){
        int parent=root;
        int child=parent*2+1;
        while(child<n){
            //选出左右两个孩子中较大的那一个
            if(child+1<n&&nums[child+1]>nums[child]){
                child++;
            }
            //如果孩子比父亲大则交换然后继续向下调整
            if(nums[child]>nums[parent]){
                swap(nums[child],nums[parent]);
                parent=child;
                child=parent*2+1;
            }else{
                break;//如果孩子小于父亲则调整结束
            }
        }
    }
    void heapsort(vector<int>&nums,int n){
        //建堆
        //堆排升序建大堆
        //使用向下调整算法从倒数第一个非叶子节点的子树开始调整一直调整到根节点就可以建为大堆
        //建堆控制root-元素个数不变为n
        for(int i=((n-1)-1)/2;i>=0;i--){
            adjustdown(nums,n,i);
        }
        //交换
        //然后再调为大堆
        //调堆控制元素个数n-root不变为0
        for(int i=n-1;i>=0;i--){
            swap(nums[0],nums[i]);
            adjustdown(nums,i,0);
        }
    }
    vector<int> MySort(vector<int>&nums) {
        int n=nums.size();//堆排要的是元素个数-快排要的是下标
        heapsort(nums,n);
        return nums;
    }
};



// #冒泡
// 冒泡思想
// 冒泡排序是一种交换排序
// 一边比较一边向后两两交换将最大值冒到最后一位
// 优化
// 使用flag记录当前轮次是否发生过交换
// 如果没有发送交换则表示已经有序跳出循环
// -
// 冒泡特点
// 稳定
// 时间复杂度N^2
// 空间复杂度1
class Solution {
public:
    void bubblesort(vector<int>&nums,int n){
        for(int i=0;i<n;i++){
            int flag=0;
            for(int j=0;j<n-i;j++){
                if(nums[j]>nums[j+1]){
                    swap(nums[j],nums[j+1]);
                    flag=1;
                }
            }
            if(flag==0){
                break;
            }
        }
    }
    vector<int> MySort(vector<int>&nums) {
        int n=nums.size()-1;
        bubblesort(nums,n);
        return nums;
    }
};


class Solution {
public:
        void insertsort(vector<int>&nums){
               int n = nums.size();
               for (int i = 0; i<n - 2; i++){
                       int end = i;
                       int tmp = nums[end + 1];
                       while (end >= 0){
                              if (nums[end]>tmp){
                                      nums[end + 1] = nums[end];
                                      end--;
                              }
                              else{
                                      break;
                              }
                       }
                       nums[end + 1] = tmp;
               }
        }
        vector<int> sortArray(vector<int>& nums) {
               insertsort(nums);
               return nums;
        }
};


class Solution {
public:
    void shellsort(vector<int>&nums){
        int n=nums.size();
        //gap>1为预排序-接近有序
        //gap=1为插排-有序
        int gap=n;
        while(gap>1){//#插排gap=1 -相较于插排价了个while循环
            gap=gap/3+1;//+1是为了确保最后一次gap一定为1////#插排gap=1 -相较于插排多了个gap的定义
            for(int i=0;i<n-gap;i++){//#插排gap=1
                int end=i;
                int tmp=nums[end+gap];//#插排gap=1
                while(end>=0){
                    if(nums[end]>tmp){
                        nums[end+gap]=nums[end];//#插排gap=1
                        end-=gap;//#插排gap=1 end--
                    }
                    else{
                        break;
                    }
                }
                nums[end+gap]=tmp;//#插排gap=1
            }
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        shellsort(nums);
        return nums;
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