#include <iostream>
using namespace std;



struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* p1 = l1;
        ListNode* p2 = l2;
        
        ListNode* p3 = new ListNode(0);
        ListNode* p4 = p3;
        
        int sum = 0;
        bool carry = false;
        
        while(p1 != nullptr || p2 != nullptr){
            
            sum = 0;
            
            if(p1 == nullptr){
                
                sum += p2->val;
                p2 = p2->next;
                
            }else if(p2 == nullptr){
                
                sum += p1->val;
                p1 = p1->next;
                    
            }else{
                
                sum = sum + p1->val + p2->val;
                p1 = p1->next;
                p2 = p2->next; 
            }
            
            if(carry){
                sum++;
                carry = false;
            }
            
            
            if(sum > 9){
                sum -= 10;
                carry = true;
            }
            
            p3->next = new ListNode(sum);
            p3 = p3->next;
        }
        
        if(carry){
            p3->next = new ListNode(1);
        }
        return p4->next;
    }
};