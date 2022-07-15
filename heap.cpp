#include<iostream>
#include<vector>

using namespace std;

void heapInsert(vector<int> v, int index) {

	while (v[index] > v[(index - 1) / 2]) {

		swap(v[index], v[(index - 1) / 2]);
		index = (index - 1) / 2;

	}
}

void heapify(vector<int> v, int index, int heapsize) {

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