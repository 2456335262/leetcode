#include<iostream>
#include <stack> 

using namespace std;

struct ListNode {
	int val;
	ListNode* next;

	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* ptr) : val(x), next(ptr) {}
};

ListNode* reverseList(ListNode* head) {

	ListNode* cur = head;
	ListNode* prev = nullptr;
	ListNode* temp;

	while (cur) {

		temp = cur->next;
		cur->next = prev;
		prev = cur;
		cur = temp;

	}
	return prev;

}


bool isPalindrome(ListNode* head) {

	ListNode* p1 = head;
	ListNode* p2 = head;

	while (p2->next && p2->next->next) {
		p1 = p1->next;
		p2 = p2->next->next;
	}

	if (p2) {
		p1 = p1->next;
	}

	p1 = reverseList(p1);

	for (ListNode* p = head; p1; p = p->next, p1 = p1->next) {
		if (p->val != p1->val) {
			return false;
		}
	}
	return true;
}

bool isPalindrome1(ListNode* head) {

	stack<int> sk;

	for (ListNode* p = head; p; p = p->next) {
		sk.push(p->val);
	}

	for (ListNode* p = head; p; p = p->next) {
		if (p->val == sk.top()) {
			sk.pop();
		}
		else {
			return false;
		}
	}
	return true;
}
