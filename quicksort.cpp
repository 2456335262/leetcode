#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void swap(int&a, int& b){
    int temp = b;
    b = a;
    a = temp;
}

vector<int> dutchflag(vector<int>& v, int n, int l, int r){
 
    int small = l - 1;
    int large = r + 1;

    for(int i = l; i != large; i++){
        if(v[i] < n){
            swap(v[i], v[small + 1]);
            small++;
        }else if(v[i] > n){
            swap(v[i], v[large - 1]);
            large--;
            i--;
        }
    }
    return {small + 1, large - 1};
}

void quicksort(vector<int>& v, int l, int r){

    if(l < r){
        vector<int> p = dutchflag(v,v[r], l, r);

        quicksort(v, l, p[0] - 1);
        quicksort(v, p[1] + 1, r);
    }
}

int main(){
    vector<int> v = {1,6,3,6,9,5,7,4,6,3,5,6,7,9,8,0,1,3,76,2,8,2,9,5};


quicksort(v, 0, v.size() - 1);

for(int i = 0; i < v.size(); i++){
    cout << v[i] << " ";
}
}