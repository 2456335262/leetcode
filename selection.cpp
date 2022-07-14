#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

void Swap(int& a, int& b){

    int temp = b;
    b = a;
    a = temp;
    
}

void selectionsort(vector<int>& v){

    int s = v.size();
    
    for(int i = 0; i < s - 1; i++){

        int min = i;
        
        for(int j = i + 1; j < s; j++){
            if(v[min] > v[j]){
                min = j;
            }
        }
        Swap(v[min], v[i]);
    }
}

int main(){
    
    vector<int> v = {2,4,3,6,3,6,8,7,5,9,5,7,9,4,8};

    selectionsort(v);
    
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
    
}
