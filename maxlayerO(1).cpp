#include<iostream>
#include<queue>
#include<unordered_map>

using namespace std;

struct Node {

	int val;
	Node* left;
	Node* right;

	Node(int a) : val(a), left(NULL), right(NULL) {};
};

int getMax(int a, int b){
    return a > b ? a : b;
}

void printLevelOrder(Node* head){

    if(!head) return;

    queue<Node*> q;

    q.push(head);
    while(!q.empty()){

        head = q.front();
        q.pop();
        cout << head->val << " ";

        if(head->left) q.push(head->left);
        if(head->right) q.push(head->right);
    }
}

int maxwidth(Node* head){

    if(!head) return 0;

    queue<Node*> q;
    q.push(head);

    unordered_map<Node*, int> mp;
    mp[head] = 1;

    int curLevel = 1;
    int curCount = 0;
    int maxw = 0;

    while(!q.empty()){

        head = q.front();
        q.pop();

        if(mp[head] == curLevel){
            curCount++;
        }else{
            maxw = getMax(maxw, curCount);
            curLevel++;
            curCount = 1;
        }

        cout << head->val << " " << mp[head] << " " << curLevel << " " << curCount << " " << maxw << endl;

        if(head->left){
            mp[head->left] = curLevel + 1;
            q.push(head->left);
        }

        if(head->right){
            mp[head->right] = curLevel + 1;
            q.push(head->right);
        }
    }

    return max(maxw, curCount);
}

int maxwidth2(Node* head){

    if(!head) return 0;

    queue<Node*> q;
    q.push(head);

    Node* curEnd = head;
    Node* nextEnd = NULL;
    int maxw = 0;
    int curLevNode = 1;

    while(!q.empty()){

        head = q.front();
        q.pop();

        if(head->left){
            nextEnd = head->left;
            q.push(head->left);
        }
        if(head->right){
            nextEnd = head->right;
            q.push(head->right);
        }


        if(head != curEnd){
            curLevNode++;
        }else{
            maxw = max(curLevNode, maxw);
            curLevNode = 1;
            curEnd = nextEnd;
        }

        cout << head->val << " " << curLevNode << " "<< endl;

    }

    return maxw;

}


int main() {

	Node* head = new Node(1);
	head->left = new Node(2);
	head->right = new Node(3);
	head->left->left = new Node(4);
	head->left->right = new Node(5);
	head->right->left = new Node(6);
	head->right->right = new Node(7);
	head->left->left->left = new Node(8);
	head->left->left->right = new Node(9);
	head->left->right->left = new Node(10);
	head->left->right->right = new Node(11);
	head->right->left->left = new Node(12);
    cout << maxwidth2(head);
}
