#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

struct Node {
	int val;
	Node* random;
	Node* next;

	Node() : val(0), next(nullptr) {}
	Node(int x) : val(x), next(nullptr), random(nullptr) {}
	Node(int x, Node* ptr) : val(x), next(ptr) {}
};

Node* copyListWithRand(Node* head) {

	unordered_map<Node*, Node*> mp;
	
	for (Node* p = head; p; p = p->next) {
		mp[p] = new Node(p->val);
	}

	for (Node* p = head; p; p = p->next) {
		mp[p]->next = mp[p->next];
		mp[p]->random = mp[p->random];
	}
	
	return mp[head];
}

Node* copyListWithRand1(Node* head) {

	if (head == NULL) return NULL;

	Node* cur = head;
	Node* temp;
	while (cur) {					//add node

		temp = cur->next;
		cur->next = new Node(cur->val);
		cur->next->next = temp;
		cur = temp;

	}
	cur = head;
	while (cur) {					//link rand

		temp = cur->next->next;
		cur->next->random = cur->random ? cur->random->next : NULL;
		cur = temp;

	}

	cur = head;
	Node* res = head->next;
	while (cur->next) {

		temp = cur->next;
		cur->next = temp->next;
		cur = temp;

	}

	return res;
	
}