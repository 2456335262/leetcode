struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode* ptr = reverselist(slow->next);
        
        while(ptr){
            
            if(ptr->val != head->val){
                return false;
            }
            
            ptr = ptr->next;
            head = head->next;
            
            
        }
        return true;
        
        
    }
    ListNode* reverselist(ListNode* head){
        
        ListNode* nxt;
        ListNode* prev = nullptr;
        ListNode* curr = head;
        
        while(curr){
            
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
            
        }
        
        return prev;
    }
};