#include<iostream>
#include<vector>
#include<queue>

using namespace std;

void swap(int& a,int& b) {
	int temp = b;
	b = a;
	a = temp;
}

int min(int a, int b) {
	
	return a > b ? b : a;
}

void heapInsert(vector<int>& v, int index) {

	while (v[index] > v[(index - 1) / 2]) {

		swap(v[index], v[(index - 1) / 2]);
		index = (index - 1) / 2;

	}
}

void heapify(vector<int>& v, int index, int heapsize) {

	int left = index * 2 + 1;

	while (left < heapsize) {

		int largest = left + 1 < heapsize && v[left + 1] > v[left] ? left + 1 : left;

		largest = v[largest] > v[index] ? largest : index;

		if (largest == index) {

			break;

		}


		swap(v[index], v[largest]);
		index = largest;
		left = index * 2 + 1;

	}
}

void heapsort(vector<int>& v) {
	
	if (v.size() < 1) {
		return;
	}

	for (int i = 1; i < v.size(); i++) {
		heapInsert(v, i);
	}

	int heapsize = v.size();


	while (heapsize > 0) {

		swap(v[0], v[--heapsize]);
		heapify(v, 0, heapsize);
		
	}
}

void sortArrDistLessK(vector<int>& v, int k) {

	priority_queue <int, vector<int>, greater<int> > q;

	int ix = 0;
	for (; ix < min(k, v.size()); ix++) {
		q.push(v[ix]);
	}

	int i = 0;

	for (; ix < v.size(); i++, ix++) {

		q.push(v[ix]);
		v[i] = q.top();
		q.pop();
		
	}

	while (!q.empty()) {
		v[i++] = q.top();
		q.pop();
	}
}


int main() {
	vector<int> v = { 10, 9, 8, 7, 4, 70, 60, 50 };

	sortArrDistLessK(v,4);

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
}