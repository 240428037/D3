class Solution {
public:
    ListNode* addInList(ListNode* head1, ListNode* head2) {
        stack<int>st1;
        stack<int>st2;
        while(head1){
            st1.push(head1->val);
            head1=head1->next;
        }
        while(head2){
            st2.push(head2->val);
            head2=head2->next;
        }
        ListNode*vhead=new ListNode(-1);
        int carry=0;
        while(!st1.empty()||!st2.empty()||carry){
            int x=0;
            int y=0;
            if(!st1.empty()){
                x=st1.top();
                st1.pop();
            }
            if(!st2.empty()){
                y=st2.top();
                st2.pop();
            }
            int z=(x+y+carry)%10;
            carry=(x+y+carry)/10;
            ListNode*cur=new ListNode(z);
            cur->next=vhead->next;
            vhead->next=cur;
        }
        return vhead->next;
    }
};


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//测试用例
//#937
//##63
//1000
//解题思路
//逐位相加-carry进位
//两个stack存储节点-相加的时候再出栈
//哨兵位头节点vhead
class Solution {
public:
    ListNode* addInList(ListNode* head1, ListNode* head2) {
        if(head1==nullptr||head2==nullptr){
            return head1==nullptr?head2:head1;
        }
        stack<ListNode*>st1;
        stack<ListNode*>st2;
        while(head1){
            st1.push(head1);
            head1=head1->next;
        }
        while(head2){
            st2.push(head2);
            head2=head2->next;
        }
        ListNode*vhead=new ListNode(-1);//vhead!!!
        int carry=0;
        while(!st1.empty()||!st2.empty()||carry){
            int x=0;
            int y=0;
            int z=0;
            if(!st1.empty()){
                x=st1.top()->val;
                st1.pop();
            }
            if(!st2.empty()){
                y=st2.top()->val;
                st2.pop();
            }
            z=(x+y+carry)%10;
            carry=(x+y+carry)/10;//(x+y+carry)!!!
            ListNode*cur=new ListNode(z);
            //#937
            //##63
            //1000
            cur->next=vhead->next;
            vhead->next=cur;
        }
        return vhead->next;
    }
};


class Solution {
public:
    ListNode*connectlist(ListNode*l1,ListNode*l2){
        if(l1==nullptr||l2==nullptr){
            return l1==nullptr?l2:l1;
        }
        if(l1->val<l2->val){
            l1->next=connectlist(l1->next,l2);
            return l1;
        }else{
            l2->next=connectlist(l1,l2->next);
            return l2;
        }
    }
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if(lists.size()==0){
            return nullptr;
        }
        ListNode*head=nullptr;
        for(int i=0;i<lists.size();i++){
            head=connectlist(head,lists[i]);
        }
        return head;
    }
};



/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//解题思路
//分治递归
//k个-一个个处理-heae=nullptr-(head,lists[i])
//子函数内部也是分治递归的思想
class Solution {
public:
    ListNode*connectlist(ListNode*l1,ListNode*l2){
        if(l1==nullptr||l2==nullptr){
            return l1==nullptr?l2:l1;
        }
        if(l1->val<l2->val){
            l1->next=connectlist(l1->next,l2);
            return l1;
        }else{
            l2->next=connectlist(l2->next,l1);
            return l2;
        }
    }
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if(lists.size()==0){
            return nullptr;
        }
        ListNode*head=nullptr;
        //两两合并-处理完一个再处理下一个
        for(int i=0;i<lists.size();i++){
            head=connectlist(head,lists[i]);
        }
        return head;
    }
};


//解题思路
//1.开一个数组遍历链表把链表的中节点的值放进去
//2.sort
//3.再把排序好的值放回链表
class Solution {
public:
    ListNode* sortInList(ListNode* head) {
        if(head==nullptr||head->next==nullptr){
            return head;
        }
        //1.开一个数组遍历链表把链表的中节点的值放进去
        vector<int>v;
        ListNode*cur=head;
        while(cur){
            v.push_back(cur->val);
            cur=cur->next;
        }
        cur=head;//cur归位
        //2.sort
        sort(v.begin(),v.end());
        //3.再把排序好的值放回链表
        for(int i=0;i<v.size();i++){
            cur->val=v[i]++;
            cur=cur->next;
        }
        return head;
    }
};



/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 * };
 */
//解题思路
//借助数组完成排序
//工作指针cur
//两次遍历
//第一次遍历将链表元素的值放进数组
//cur归位
//排序
//第二次遍历将数组的值再放回链表
//两次遍历都借助工作指针cur完成
//因为最后return head所以head不能动
class Solution {
public:
    ListNode* sortInList(ListNode* head) {
        if(head==nullptr||head->next==nullptr){
            return head;
        }
        vector<int>v;
        ListNode*cur=head;
        while(cur){
            v.push_back(cur->val);
            cur=cur->next;
        }
        cur=head;//归位
        sort(v.begin(),v.end());
        for(int i=0;i<v.size();i++){
            cur->val=v[i];
            cur=cur->next;
        }
        return head;
    }
};


class Solution {
public:
    bool isPail(ListNode* head) {
        //1.快慢指针找链表的中间节点
        ListNode*slow=head;
        ListNode*fast=head;
        while(fast&&fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        //翻转后半段链表
        ListNode*cur=slow;
        ListNode*newhead=nullptr;
        while(cur){
            ListNode*next=cur->next;
            cur->next=newhead;
            newhead=cur;
            cur=next;
        }
        //判断回文
        while(head&&newhead){
            if(head->val!=newhead->val){
                return false;
            }
            head=head->next;
            newhead=newhead->next;
        }
        return true;
    }
};


/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 * };
 */
//解题思路
//快慢指针找到链表的中间节点
//翻转后半段链表-写进主函数-不开辟子函数
//然后判断回文
class Solution {
public:
    bool isPail(ListNode* head) {
        if(head==nullptr||head->next==nullptr){
            return true;
        }
        ListNode*slow=head;
        ListNode*fast=head;
        while(fast&&fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode*cur=slow;
        ListNode*newhead=nullptr;
        while(cur){
            ListNode*next=cur->next;
            cur->next=newhead;
            newhead=cur;
            cur=next;
        }
        while(head&&newhead){
            //用val去比较!!!
            if(head->val!=newhead->val){
                return false;
            }
            head=head->next;
            newhead=newhead->next;
        }
        return true;
    }
};



/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 *	ListNode(int x) : val(x), next(nullptr) {}
 * };
 */
//解题思路
//快慢指针
//需要注意k大于链表长度的情况-放在while(k--)中处理
//-if(fast==nullptr)return nullptr;
class Solution {
public:
    ListNode* FindKthToTail(ListNode*head, int k) {
        if(head==nullptr){
            return nullptr;
        }
        ListNode*slow=head;
        ListNode*fast=head;
        while(k--){
            if(fast==nullptr){
                return nullptr;
            }
            fast=fast->next;
        }
        while(fast){
            slow=slow->next;
            fast=fast->next;
        }
        return slow;
    }
};



//解题思路
//lesshead-lesstail
//greaterhead-greatertail
//用哨兵位的头节点对less和greater进行初始化
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        //对less和greater定义
        //然后使用哨兵位头节点进行初始化
        ListNode*lesshead,*lesstail;
        ListNode*greaterhead,*greatertail;
        lesshead=lesstail=new ListNode(-1);
        greaterhead=greatertail=new ListNode(-1);
        //划分
        ListNode*cur=head;
        while(cur){
            if(cur->val<x){
                lesstail->next=cur;
                lesstail=lesstail->next;
            }else{
                greatertail->next=cur;
                greatertail=greatertail->next;
            }
            cur=cur->next;
        }
        //后面那个链表greater置空
        greatertail->next=nullptr;
        //链接
        lesstail->next=greaterhead->next;
        //return要注意哨兵位头节点
        return lesshead->next;
    }
};



//解题思路
//lesshead-lesstail
//greaterhead-greatertail
//用哨兵位的头节点对less和greater进行初始化
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        //对less和greater定义
        //然后使用哨兵位头节点进行初始化
        ListNode*lesshead,*lesstail;
        ListNode*greaterhead,*greatertail;
        lesshead=lesstail=new ListNode(-1);
        greaterhead=greatertail=new ListNode(-1);
        //划分
        ListNode*cur=head;
        while(cur){
            if(cur->val<x){
                lesstail->next=cur;
                lesstail=lesstail->next;
            }else{
                greatertail->next=cur;
                greatertail=greatertail->next;
            }
            cur=cur->next;
        }
        //后面那个链表greater置空
        greatertail->next=nullptr;
        //链接
        lesstail->next=greaterhead->next;
        //return要注意哨兵位头节点
        return lesshead->next;
    }
};