#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


int merge(vector<int>& v, int L, int mid, int R){

    int p1 = L;
    int p2 = mid + 1;

    int sum = 0;

    vector<int> help;

    while(p1 <= mid && p2 <= R){
        if(v[p2] > v[p1]){
            sum += v[p1] * ((R - p2) + 1);
            help.push_back(v[p1++]);
        }
        else{
            help.push_back(v[p2++]);
        }
    }
    while(p2 <= R){
        help.push_back(v[p2++]);
    }
    while(p1 <= mid){
        help.push_back(v[p1++]);
    }

    for(int i = 0; i < help.size(); i++){
        v[L + i] = help[i];
    }

    return sum;
}

int smallsum(vector<int>& v, int L, int R){

    if(L == R) return 0;

    int mid = L + ((R - L) >> 1);

    return smallsum(v, L, mid) + smallsum(v, mid + 1, R) + merge(v, L, mid, R);
    
}

int main(){

    vector<int> v = {1,3,4,2,5};

    cout << smallsum(v, 0, v.size()) << endl;

    for(int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
}