#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

void bucketsort(vector<int>& v) {
	
	vector<int> bucket(100, 0);

	for (int i = 0; i < v.size(); i++) {
		bucket[v[i]]++;
	}

	int j = 0;

	for (int i = 0; i < bucket.size(); i++) {
		if (bucket[i] != 0) {
			while (bucket[i] > 0) {
				v[j++] = i;
				bucket[i]--;
			}
		}
	}
}

int getDigit(int n) {

	if (n == 0) return 0;
	
	return 1 + getDigit(n/10);
	
}

int dvalue(int n, int d) {
	
	n = n % (int)pow(10, d);
	n = n / pow(10, d - 1);

	return n;

}
void radixsort(vector<int>& v) {

	int maxdigit = 0;

	vector<int> bucket(v.size());

	for (int i : v) {

		if (getDigit(i) > maxdigit) {

			maxdigit = getDigit(i);

		}

	}

	for (int d = 0; d <= maxdigit; d++) {

		vector<int> count(10, 0);

		for (int i : v) {

			count[dvalue(i, d)]++;

		}

		for (int i = 1; i < count.size(); i++) {

			count[i] += count[i - 1];

		}

		for (int i = v.size() - 1; i >= 0; i--) {

			bucket[count[dvalue(v[i], d)] - 1] = v[i];
			count[dvalue(v[i], d)]--;

		}

		for (int i = 0; i < v.size(); i++) {

			v[i] = bucket[i];

		}
		
	}
	
}
//int main() {
//
//	vector<int> v = { 10000,10, 9078, 8, 780, 44, 70, 60, 50 };
//	
//	radixsort(v);
//
//	for (int i : v) {
//		cout << i << " ";
//	}
//}


