#include<iostream>
#include<vector>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;

	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* ptr) : val(x), next(ptr) {}
};


void Swap(vector<ListNode*> v, int a, int b) {

	int temp = v[b]->val;
	v[b]->val = v[a]->val;
	v[a]->val = temp;

}

ListNode* listPartition(ListNode* head, int pivot) {

	vector<ListNode*> v;

	ListNode* p = head;

	v.push_back(p);
	do {
		v.push_back(p = p->next);
	} while (p);

	int p1 = -1;
	int p2 = v.size() - 1;

	for (int i = 0; i < p2; i++) {

		if (v[i]->val < pivot) {

			Swap(v, i, ++p1);

		}

		else if (v[i]->val > pivot) {

			Swap(v, i, --p2);
			i--;

		}

	}

	for (int i = 0; i < v.size() - 1; i++) {
		v[i]->next = v[i + 1];
	}

	return v[0];
}


ListNode* listPartition2(ListNode* head, int pivot) {

	ListNode* sH = nullptr;
	ListNode* sT = nullptr;
	ListNode* mH = nullptr;
	ListNode* mT = nullptr;
	ListNode* bH = nullptr;
	ListNode* bT = nullptr;

	ListNode* next = nullptr;

	while(head) {

		next = head->next;
		head->next = nullptr;

		if (head->val < pivot) {
			if (!sT) {
				sH = head;
				sT = head;
			}
			else {
				sT->next = head;
				sT = head;
			}
		}
		else if (head->val > pivot) {
			if (!bT) {
				bH = head;
				bT = head;
			}
			else {
				bT->next = head;
				bT = head;
			}
		}
		else {
			if (!mT) {
				mH = head;
				mT = head;
			}
			else {
				mT->next = head;
				mT = head;
			}
		}

		head = next;

	}

	if (sH) {
		sT->next = mH;
		mT = mT? mT : sT;
	}

	if (mT) {
		mT->next = bH;
	}

	return sH ? sH : (mH ? mH : bH);
}


int main() {

	ListNode* l = new ListNode(1, nullptr);
	l = new ListNode(87, l);
	l = new ListNode(26, l);
	l = new ListNode(85, l);
	l = new ListNode(87, l);
	l = new ListNode(43, l);
	l = new ListNode(315, l);
	l = new ListNode(88, l);
	l = new ListNode(222, l);

	l = listPartition2(l, 87);

	while (l) {
		cout << l->val << " ";
		l = l->next;
	}
}