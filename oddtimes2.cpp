#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

void Swap(int& a, int& b){//campare with itself

    int temp = b;
    b = a;
    a = temp;
    
}

void findoddtimes2(vector<int>& v, int& a, int& b){

    int res = 0;
    
    for(int i : v){
        res = res ^ i;
    }

    int right1 = (~res + 1) & res;

    int p = 0;

    for(int i : v){
        if((i & right1) == 0){
            p = p ^ i;
        }
    }

    a = p;

    b = res ^ p;
    
}

int main(){
    
    vector<int> v = {2,2,3,3,4,5,6,6};
    int a, b;
    
    findoddtimes2(v, a, b);
    
    cout << a << endl << b;
    
}
