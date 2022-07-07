#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

void Swap(int& a, int& b){

    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
    
}

void bubblesort(vector<int>& v){

    int s = v.size() - 1;//最后一个不用换
    
    for(int i = 0; i < s; i++){
        for(int j = 0; j < s - i; j++){
            if(v[j] > v[j + 1]){
                Swap(v[j], v[j + 1]);
            }
        }
    }
}

int main(){
    
    vector<int> v = {2,4,3,6,3,6,8,7,5,9,5,7,9,4,8};

    bubblesort(v);
    
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
    
}
