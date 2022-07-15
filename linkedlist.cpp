# include <iostream>
using namespace std;

struct Node {
	int val;
	Node* next;
};

//Node* add(Node* l, int n) {
//
//	Node* tmp = new Node;
//
//	tmp->val = n;
//	tmp->next = l;
//
//	return tmp;
//
//}

void NodeAdd(int a, Node*& head) {

	Node* tmp = new Node;

	tmp->val = a;
	tmp->next = head;

	head = tmp;
}


int main() {
	Node* head = nullptr;

	NodeAdd(2, head);
	NodeAdd(3, head);
	NodeAdd(4, head);
	NodeAdd(35, head); 
	NodeAdd(27, head);
	NodeAdd(11, head);

	/*head = add(head, 12);*/

	/*tmp->val = 1;
	tmp->next = head;
	head = tmp;

	tmp = new Node;
	tmp->val = 2;
	tmp->next = head;

	head = tmp;*/
	
	int num = 27;

	while (head){
		if (head->val == num) {
			cout << "True";
		}
		cout << (*head).val  << " ";
		head = head -> next;
	}
}

