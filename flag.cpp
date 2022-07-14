#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void swap(int&a, int& b){
    int temp = b;
    b = a;
    a = temp;
}

void dutchflag(vector<int>& v, int n){
 
    int small = -1;
    int large = v.size();

    for(int i = 0; i != large; i++){
        if(v[i] < n){
            swap(v[i], v[small + 1]);
            small++;
        }else if(v[i] > n){
            swap(v[i], v[large - 1]);
            large--;
            i--;
        }
    }
}



int main(){
    vector<int> v = {1,6,3,6,9,5,7,4,6,3,5,6,7,9,8,0,1,3,76,2,8,2,9,5};


dutchflag(v, 5);

for(int i = 0; i < v.size(); i++){
    cout << v[i] << " ";
}
}