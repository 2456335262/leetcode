#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;


struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) : val(x), next(NULL) {};
    ListNode(int x, ListNode* y) : val(x), next(y) {};
};

ListNode* getLoopNode1(ListNode* head) {
    if (!head || !head->next || !head->next->next) return NULL;

    ListNode* n1 = head->next;
    ListNode* n2 = head->next->next;

    while (n1 != n2) {

        if (n2->next == NULL || n2->next->next == NULL) {
            return NULL;
        }

        n1 = n1->next;
        n2 = n2->next->next;
    }

    n2 = head;

    while (n1 != n2) {
        n1 = n1->next;
        n2 = n2->next;
    }

    return n1;
}

ListNode* getLoopNode2(ListNode* l) {

    unordered_set<ListNode*> s;

    while (l) {
        if (s.find(l) != s.end()) {

            return l;

        }
        else {

            s.insert(l);
            l = l->next;

        }
    }
    return NULL;
}

ListNode* noLoop(ListNode* head1, ListNode* head2) {

    ListNode* p1 = head1;
    ListNode* p2 = head2;

    int counter = 0;

    while (p1->next) {

        counter++;
        p1 = p1->next;

    }
    
    while (p2->next) {

        counter--;
        p2 = p2->next;

    }

    if (p1 != p2) {
        return NULL;
    }

    p1 = counter > 0 ? head1 : head2;
    p2 = p1 == head1 ? head2 : head1;

    counter = abs(counter);

    while(counter != 0) {
        counter--;
        p1 = p1->next;
    }

    while (p1 != p2) {
        p1 = p1->next;
        p2 = p2->next;
    }

    return p1;
}

ListNode* bothLoop(ListNode* head1, ListNode* head2) {

    ListNode* p1 = getLoopNode2(head1);
    ListNode* p2 = getLoopNode2(head2);

    if (p1 = p2) {
        
        ListNode* temp = p1;
        p1 = head1;
        p2 = head2;
        int c = 0;

        while (p1 != temp) {
            p1 = p1->next;
            c++;
        }
        while (p2 != temp) {
            p2 = p2->next;
            c--;
        }
        
        p1 = c > 0 ? head1 : head2;
        p2 = p1 == head1 ? head2 : head1;

        c = abs(c);

        while(c != 0) {
            c--;
            p1 = p1->next;
        }

        while (p1 != p2) {
            p1 = p1->next;
            p2 = p2->next;
        }
        
        return p1;
    }
    else {

        ListNode* temp = p2->next;
        

        while (temp != p2) {

            if (p2 == p1) {
                return p1;
            }
            temp = temp->next;
        }

        return NULL;
    }
}

ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {

    if (!headA || !headB) {
        return NULL;
    }
    
    ListNode* loop1 = getLoopNode2(headA);
    ListNode* loop2 = getLoopNode2(headB);

    if (loop1 && loop2) {
        return bothLoop(headA, headB);
    }
    
    if (!loop1 && !loop2) {
        return noLoop(headA, headB);
    }
    return NULL;
}