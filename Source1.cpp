#include<iostream>
#include<stack>

using namespace std;

struct Node {

	int val;
	Node* left;
	Node* right;

	Node(int a) : val(a), left(NULL), right(NULL) {};
};

void preorderUnrecur(Node* head) {

	if (!head) return;

	stack<Node*> s;
	Node* temp;

	s.push(head);
	while (!s.empty()) {
		temp = s.top();
		cout << temp->val << " ";
		s.pop();

		if (temp->right) s.push(temp->right);
		if (temp->left) s.push(temp->left);
	}
}

void posOrderUnrecur(Node* head){

    if (!head) return;

	stack<Node*> s;
	stack<Node*> c;

	Node* temp;

	s.push(head);
	while (!s.empty()) {

		temp = s.top();
		c.push(temp);
		s.pop();

		if (temp->left) s.push(temp->left);
		if (temp->right) s.push(temp->right);
	}

	while(!c.empty()){
        cout << c.top()->val << " ";
        c.pop();
	}

}

void inOrderUnrecur(Node* head){

    if(!head) return;

    stack<Node*> s;

    while(!s.empty() || head){

        if(head){
            s.push(head);
            head = head->left;
        }else{
            head = s.top();
            s.pop();
            cout << head->val << " ";
            head = head->right;
        }
    }

}


int main() {

	Node* head = new Node(1);
	head->left = new Node(2);
	head->right = new Node(3);
	head->left->left = new Node(4);
	head->left->right = new Node(5);
	head->right->left = new Node(6);
	head->right->right = new Node(7);

	inOrderUnrecur(head);
}
