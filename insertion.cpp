#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

void Swap(int& a, int& b){

    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
    
}

void insertionsort(vector<int>& v){

    int s = v.size();
    
    for(int i = 1; i < s; i++){
        for(int j = i; j > 0 && v[j] < v[j - 1]; j--){
            //stop if already sorted
            if(v[j] < v[j - 1]){
                Swap(v[j], v[j - 1]);
            }
        }
    }
}

int main(){
    
    vector<int> v = {2,4,3,6,3,6,8,7,5,9,5,7,9,4,8};

    insertionsort(v);
    
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
    
}
