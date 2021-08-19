/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x):
	val(x), 
    next(NULL) 
    {}
};*/
//解题思路
//1.迭代-三指针翻转
//while n3
//if n3
//return n1
//2.头插
//newhead
//cur
//while(cur)-next
class Solution {
public:
    ListNode* ReverseList(ListNode* head) {
        /*//1.迭代
        ListNode*n1=nullptr;
        ListNode*n2=head;
        ListNode*n3=head->next;
        while(n2){
            n2->next=n1;
            n1=n2;
            n2=n3;
            if(n3){
                n3=n3->next;
            }
        }
        return n1;
        */
        //2.头插
        ListNode*newhead=nullptr;
        ListNode*cur=head;
        while(cur){
            ListNode*next=cur->next;
            cur->next=newhead;
            newhead=cur;
            cur=next;
        }
        return newhead;
    }
};



/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x):
	val(x), 
    next(NULL) {}
};*/
//解题思路
//head-tail
//if-else对head-tail初始化
//while(&&)-if-else
//两个while
class Solution {
public:
    ListNode* Merge(ListNode* head1, ListNode* head2) {
        if(head1==nullptr||head2==nullptr){
            return head1==nullptr?head2:head1;
        }
        ListNode*head=nullptr;
        ListNode*tail=nullptr;
        if(head1->val<head2->val){
            head=tail=head1;
            head1=head1->next;
        }else{
            head=tail=head2;
            head2=head2->next;
        }
        while(head1&&head2){
            if(head1->val<head2->val){
                tail->next=head1;
                head1=head1->next;
            }else{
                tail->next=head2;
                head2=head2->next;
            }
            tail=tail->next;
        }
        while(head1){
            tail->next=head1;
            head1=head1->next;
            tail=tail->next;
        }
        while(head2){
            tail->next=head2;
            head2=head2->next;
            tail=tail->next;
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
//测试用例
//12345,k=2
//21435
//12345,k=3
//32145
//解题思路
//判断k是否大于链表长度+k个一组翻转+链接+递归翻转
//把反转链表写进主函数-不单独写子函数
//初始化-三指针迭代的写法
//for循环k判断k是否大于链表长度-大于return head
//判断完n2归位-n2=head
//for循环k-k个一组翻转-头插的写法
//链接head->next=reversegroup(n3,k)
//最后return n1
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==nullptr||head->next==nullptr){
            return head;
        }
        ListNode*n1=nullptr;
        ListNode*n2=head;
        ListNode*n3=head->next;
        for(int i=0;i<k;i++){
            if(n2==nullptr){
                return head;
            }
            n2=n2->next;
        }
        n2=head;
        for(int i=0;i<k;i++){
            n3=n2->next;
            n2->next=n1;
            n1=n2;
            n2=n3;
        }
        //12345,k=3
        //1<-2<-3->4->5
        //32145
        //1链接4
        //所以是head->next,参数为n3
        head->next=reverseKGroup(n3,k);
        //12345,k=3
        //32145-return n1
        return n1;
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
//判环-快慢指针
//快的一次两步-慢的一次一步
//有环-快指针先进环-慢指针后进环
//慢指针刚进环-快慢指针距离为N
//每各走一步-N-1..N-2..0最后一定相遇
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head==nullptr||head->next==nullptr){
            return false;
        }
        ListNode*slow=head;
        ListNode*fast=head;
        while(fast&&fast->next){
            slow=slow->next;
            fast=fast->next->next;
            //有环一定相遇
            if(slow==fast){
                return true;
            }
        }
        return false;//没相遇出了while循环就无环
    }
};


/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 * };
 */
//测试用例
//12345,n=2
//1235
//解题思路
//快慢指针先找到倒数第n个节点-链表的倒数第k个节点
//快指针先走k步-然后快慢指针一起走-快指针为空-慢指针指向节点即为倒数第k个
//将slow的前一个节点保存下来prev
//链接prev->next=slow->next;
//特殊情况!!!
//要删除的节点就是头节点
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode*slow=head;
        ListNode*fast=head;
        //12,2
        while(n--){
            fast=fast->next;
        }
        //12,2-要删除的节点就是头节点-返回头节点的下一个节点
        if(fast==nullptr){
            return head->next;
        }
        ListNode*prev=nullptr;
        while(fast){
            fast=fast->next;
            prev=slow;
            slow=slow->next;
        }
        prev->next=slow->next;
        return head;
    }
};



/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
//解题思路
//cur1-cur2计算l1-l2
//longlist-shortlist
//if-是否需要调整初始化的情况
//gap=abs(l1-l2)
//while(gap--)longlist先走gap步
//while(longlist)-if(==)return longlist
//除了循环没有找到return nullptr
class Solution {
public:
    ListNode* FindFirstCommonNode( ListNode* head1, ListNode* head2) {
        /*//优化后？
        if(head1==nullptr||head2==nullptr){
            return nullptr;
        }
        ListNode*cur1=head1;
        ListNode*cur2=head2;
        while(cur1!=cur2){
            cur1=cur1==nullptr?head2:cur1->next;
            cur2=cur2==nullptr?head1:cur2->next;
        }
        return cur1;
        */
        if(head1==nullptr||head2==nullptr){
            return nullptr;
        }
        ListNode*cur1=head1;
        ListNode*cur2=head2;
        int l1=0;
        int l2=0;
        while(cur1){
            l1++;
            cur1=cur1->next;
        }
        while(cur2){
            l2++;
            cur2=cur2->next;
        }
        ListNode*longlist=head1;
        ListNode*shortlist=head2;
        if(l2>l1){
            longlist=head2;
            shortlist=head1;
        }
        int gap=abs(l1-l2);
        while(gap--){
            longlist=longlist->next;
        }
        while(longlist){
            if(longlist==shortlist){
                return longlist;
            }
            longlist=longlist->next;
            shortlist=shortlist->next;
        }
        return nullptr;
    }
};