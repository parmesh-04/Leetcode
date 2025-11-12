/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
       stack<int> s1;
       stack<int> s2;
       while(l1!=nullptr){
        s1.push(l1->val);
        l1=l1->next;
       } 

       while(l2!=nullptr){
        s2.push(l2->val);
        l2=l2->next;
       }

       int c=0;
       ListNode* ans=nullptr;
       while(!s1.empty() || !s2.empty() || c){
        int t1=0;
        if(!s1.empty()){
            t1=s1.top();
            s1.pop();
        }
        int t2=0;
        if(!s2.empty()){
            t2=s2.top();
            s2.pop();
        }
        int sum=t1+t2+c;
        int digit=sum%10;
        c=sum/10;
        ListNode* node=new ListNode(digit);
        node->next=ans;
        ans=node;
       }
       return ans;
    }
};