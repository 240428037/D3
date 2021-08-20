//12345,2,4
//14325
//解题思路
//穿针引线-找到指定区间-断开-翻转-链接
//1.定义哨兵位的头节点vhead
//2.找到指定区间
//prev leftnode rightnode next
//3.断开
//prev->next=nullptr;
//rightnode->next=nullptr;
//4.翻转
//5.链接
//prev->next=rightnode;
//leftnode->next=next;
class Solution {
public:
    //翻转链表-void
    //定义节点-迭代-三指针
    //while(cur)-头插
    void reverselist(ListNode*head){
        ListNode*prev=nullptr;
        ListNode*cur=head;
        ListNode*next=head->next;
        while(cur){
            next=cur->next;
            cur->next=prev;
            prev=cur;
            cur=next;
        }
    }
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(head==nullptr||head->next==nullptr){
            return head;
        }
        //1.定义哨兵位头节点
        ListNode*vhead=new ListNode(-1);
        vhead->next=head;
        //2.找到指定区间
        //prev leftnode rightnode next
        ListNode*prev=vhead;
        for(int i=0;i<m-1;i++){//m-1!!!
            prev=prev->next;
        }
        ListNode*leftnode=prev->next;
        ListNode*rightnode=prev;
        for(int i=0;i<n-m+1;i++){
            rightnode=rightnode->next;
        }
        ListNode*next=rightnode->next;
        //3.断开
        //prev leftnode rightnode next
        prev->next=nullptr;
        rightnode->next=nullptr;
        //4.翻转
        reverselist(leftnode);
        //5.链接
        prev->next=rightnode;//翻转后的头节点为rightnode
        leftnode->next=next;
        return vhead->next;
    }
};



//测试用例
//1234
//1423
//-
//12345
//15243
//-
//12345
//123/45
//123/54
//15243
//解题思路
//1.快慢指针找到链表的中间节点
//2.从中间节点将链表断开
//3.翻转后半段链表
//4.合并链表
class Solution {
public:
    //反转链表
    ListNode*reverselist(ListNode*head){
        if(head==nullptr||head->next==nullptr){
            return head;
        }
        ListNode*cur=head;
        ListNode*newhead=nullptr;
        while(cur){
            ListNode*next=cur->next;
            cur->next=newhead;
            newhead=cur;
            cur=next;
        }
        return newhead;
    }
    void reorderList(ListNode *head) {
        if(head==nullptr||head->next==nullptr){
            return;
        }
        //1.快慢指针找到链表的中间节点
        ListNode*slow=head;
        ListNode*fast=head;
        while(fast&&fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        //2.从中间节点将链表断开
        ListNode*tmp=slow->next;
        slow->next=nullptr;//断开
        //3.翻转后半段链表
        ListNode*newhead=reverselist(tmp);
        //3.合并链表
        //head-123
        //newhead-54
        //15243
        ListNode*cur=head;
        int k=0;
        //循环控制条件&&-一个走完就结束
        while(cur&&newhead){
            if(k%2==0){
                ListNode*next=cur->next;
                cur->next=newhead;//链接
                cur=next;
            }else{
                ListNode*next=newhead->next;
                newhead->next=cur;//链接
                newhead=next;
            }
            k++;
        }
        return;
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
//1234
//1423
//-
//12345
//15243
//解题思路
//12345
//123
//54
//15243
//快慢指针找到链表的中间节点
//翻转后半段链表
//合并-k标记-k初识为0-每合并一次k++
class Solution {
public:
    ListNode*reverselist(ListNode*head){
        ListNode*cur=head;
        ListNode*newhead=nullptr;
        while(cur){
            ListNode*next=cur->next;
            cur->next=newhead;
            newhead=cur;
            cur=next;
        }
        return newhead;
    }
    void reorderList(ListNode *head) {
        if(head==nullptr||head->next==nullptr){
            return;
        }
        ListNode*slow=head;
        ListNode*fast=head;
        while(fast&&fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode*tmp=slow->next;
        slow->next=nullptr;
        ListNode* newhead=reverselist(tmp);
        int k=0;
        while(head&&newhead){
            if(k%2==0){
                ListNode*next=head->next;
                head->next=newhead;
                head=next;
            }else{
                ListNode*next=newhead->next;
                newhead->next=head;
                newhead=next;
            }
            k++;
        }
        return;
    }
};