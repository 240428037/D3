class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==nullptr){
            return nullptr;
        }
        ListNode*cur=head;
        while(cur->next){
            if(cur->val==cur->next->val){
                cur->next=cur->next->next;
            }else{
                cur=cur->next;
            }
        }
        return head;
    }
};



class Solution {
public:
    ListNode* deleteDuplicates(ListNode* pHead) {
        if(pHead==nullptr){
            return nullptr;
        }
        //定义三个指针n1,n2,n3,使用n2和n3去找链表中重复区间，找到后删除n2到n3的重复区间
        //然后让n1链接到重复区间后面一段，然后继续往后遍历
        ListNode*n1=nullptr;
        ListNode*n2=pHead;
        ListNode*n3=pHead->next;
        while(n3){
            if(n2->val==n3->val){
                //使用n2和n3去找重复区间
                while(n3&&n2->val==n3->val){
                    n3=n3->next;
                }
                //删除重复区间
                while(n2!=n3){
                    ListNode*next=n2->next;
                    delete n2;
                    n2=next;
                }
                //将n1链接到重复区间后面一段
                if(n1){
                    n1->next=n2;
                }else{
                    pHead=n2;
                }
                if(n3){
                    n3=n3->next;
                }
            //迭代，继续往后遍历
            }else{
                n1=n2;
                n2=n3;
                n3=n3->next;
            }
        }
        return pHead;
    }
};



/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 * };
 */
//测试用例
//11233
//123
//保留一个重复节点
//解题思路
//遍历链表就可以
//while(cur->next)
//if-else
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==nullptr){
            return nullptr;
        }
        ListNode*cur=head;
        while(cur->next){
            if(cur->val==cur->next->val){
                cur->next=cur->next->next;
            }else{
                cur=cur->next;
            }
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
//11123
//23
//1233445
//125
//重复节点全部删除
//解题思路
//三指针遍历链表
//使用n2和n3去找链表的重复区间
//找到后删除n2到n3的重复区间
//然后让n1链接到重复区间的后面一段
//然后迭代n3继续向后遍历
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==nullptr||head->next==nullptr){
            return head;
        }
        ListNode*n1=nullptr;
        ListNode*n2=head;
        ListNode*n3=head->next;
        while(n3){
            if(n2->val==n3->val){
                //n2和n3去找重复区间
                while(n3&&n2->val==n3->val){
                    n3=n3->next;
                }
                //删除重复区间
                while(n2!=n3){
                    ListNode*next=n2->next;
                    delete n2;
                    n2=next;
                }
                //链接
                if(n1){
                    n1->next=n2;
                }else{
                    head=n2;
                }
                //迭代n3
                if(n3){
                    n3=n3->next;
                }
            }else{
                n1=n2;
                n2=n3;
                n3=n3->next;
            }
        }
        return head;
    }
};



//测试用例
//123456
//135246
//-
//14637
//16743
//奇偶指的的节点下标
//解题思路
//1.保存偶数链表头节点
//2.分离奇数链表和偶数链接
//3.然后奇数链表尾节点链接偶数链表头节点
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head==nullptr||head->next==nullptr){
            return head;
        }
        //1.保存偶数链表头节点
        ListNode*phead=head->next;//偶数链表头节点-后面链接使用
        ListNode*l1=head;//奇数
        ListNode*l2=phead;//偶数
        //2.分离奇数链表和偶数链接
        //l1 l2 l1 l2
        //循环控制条件-类似于快慢指针-fast&&fast->next
        //l2&&l2->next
        while(l2&&l2->next){
            //奇数迭代
            l1->next=l2->next;
            l1=l1->next;
            //偶数迭代
            l2->next=l1->next;
            l2=l2->next;
        }
        ////3.然后奇数链表尾节点链接偶数链表头节点
        l1->next=phead;
        return head;
    }
};



/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 *	ListNode(int x) : val(x), next(nullptr) {}
 * };
 */
//测试用例
//123456
//135246
//14637
//16743
//奇偶是指下标
//解题思路
//l1-l2/phead-保存偶数链表头节点
//while(l2&&l2->next)分离奇数和偶数链表
//奇数链表尾节点链接vhead偶数链表头节点
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head==nullptr){
            return nullptr;
        }
        ListNode*l1=head;//奇数
        ListNode*l2=head->next;//偶数
        ListNode*phead=head->next;
        //123456
        //135 246
        //135246
        while(l2&&l2->next){
            l1->next=l2->next;//1->3
            l1=l1->next;//l1=3
            l2->next=l1->next;//2->4
            l2=l2->next;//l2=4
        }
        l1->next=phead;
        return head;
    }
};




class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead) {
        if(pHead==nullptr){
            return nullptr;
        }
        //1.拷贝原链表的每个节点链接到原节点的后面
        //cur copy next
        RandomListNode*cur=pHead;
        while(cur){
            RandomListNode*next=cur->next;
            RandomListNode*copy=new RandomListNode(cur->label);
            cur->next=copy;
            copy->next=next;
            cur=next;
        }
        //2.处理拷贝节点的random
        //cur copy
        cur=pHead;
        while(cur){
            RandomListNode*copy=cur->next;
            if(cur->random){
                copy->random=cur->random->next;
            }else{
                copy->random=nullptr;
            }
            cur=copy->next;
        }
        //3.拆解
        //cur copy next
        cur=pHead;
        RandomListNode*copyhead=cur->next;
        while(cur){
            RandomListNode*copy=cur->next;
            RandomListNode*next=copy->next;
            cur->next=next;
            if(next){
                copy->next=next->next;
            }else{
                copy->next=nullptr;
            }
            cur=next;
        }
        return copyhead;
    }
};


/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==nullptr){
            return nullptr;
        }
        //1.拷贝原链表的每个节点链接到原节点的后面
        //cur copy next1
        Node*cur=head;
        while(cur!=nullptr){
            Node*copy=new Node(cur->val);
            Node*next1=cur->next;
            cur->next=copy;
            copy->next=next1;
            cur=next1;//迭代
        }
        //2.处理拷贝节点的random
        //cur copy
        cur=head;
        while(cur!=nullptr){
            Node*copy=cur->next;
            if(cur->random){
                copy->random=cur->random->next;
            }
            else{
                copy->random=nullptr;
            }
            cur=copy->next;//迭代
        }
        //3.拆解
        //cur copy next1
        cur=head;
        Node*copyhead=cur->next;
        while(cur!=nullptr){
            Node*copy=cur->next;
            Node*next1=copy->next;
            cur->next=next1;
            if(next1){
                copy->next=next1->next;
            }
            else{
                copy->next=nullptr;
            }
            cur=next1;//迭代
        }
        return copyhead;
    }
};