#include<iostream>
#include<vector>

using namespace std;

void swap(int& a,int& b) {
	int temp = b;
	b = a;
	a = temp;
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

int main() {
	vector<int> v = { 1,2,4,12,4,5,4,2,9,6,4,7,4,6,3,8,9,2,7,8,1,75,89,12,756 };

	heapsort(v);

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
}