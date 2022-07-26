#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;


struct ListNode{
    int val;
    ListNode* next;

    ListNode(int x) : val(x), next(NULL){};
    ListNode(int x, ListNode* y) : val(x), next(y){};
};

ListNode* getLoopNode1(ListNode *head) {
        if(!head || !head->next || !head->next->next) return NULL;
	
        ListNode* n1 = head->next;
        ListNode* n2 = head->next->next;

        while(n1 != n2){

            if(n2->next == NULL || n2->next->next == NULL){
                return NULL;
            }

            n1 = n1->next;
            n2 = n2->next->next;
        }

        n2 = head;

        while(n1 != n2){
            n1 = n1->next;
            n2 = n2->next;
        }

        return n1;
    }

ListNode* getLoopNode2(ListNode* l){

    unordered_set<ListNode*> s;

    while(l){
        if(s.find(l) != s.end()){
            
            return l;
            
        }else{
            
            s.insert(l);
            l = l->next;
            
        }
    }
    return NULL;
}