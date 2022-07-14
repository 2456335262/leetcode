#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// *Find Max
int process(vector<int>& v, int L, int R){

    if(L == R){
        return v[L];
    }
    
    int mid = L+((R-L) >> 1);
    int LM = process(v,L,mid);
    int RM = process(v,mid+1,R);
    return max(LM, RM);
}

int get_max(vector<int>& v){
    return process(v, 0, v.size() - 1);
}


// int main(){
//     vector<int> v = {1,2,3,4,2,3,4,2000,3,45,6,7,4,6,255};

//     cout << get_max(v);
// }

// *Rearrangement
void merge(vector<int>& v, int L,int M, int R){
    
    int p1 = L;
    int p2 = M+1;
    vector<int> help;
    for(int i = 0; p1 < M && p2 < R; i++){
        if (v[p1]< v[p2]){
            help.push_back(v[p1]);
            p1++;
        }
        else{
            help.push_back(v[p2]);
            p2++;
        }
    }

    while(p1 < M){
        help.push_back(v[p1++]);
    }

    while(p2 < R){
        help.push_back(v[p2++]);
    }

    for(int i = 0; i < help.size(); i++){
        v[L + i] = help[i];
    }
}

void process1(vector<int>& v, int L, int R){

    if(L == R){
        return;
    }
    
    int mid = L+((R-L) >> 1);
    process1(v,L,mid);
    process1(v,mid+1,R);
    merge(v, L, mid, R);
}

// int main(){
//     vector<int> v = {1,2,3,4,2,3,4,2000,3,45,6,7,4,6,255};

//     process1(v, 0, v.size() - 1);

//     for(int i = 0; i < v.size(); i++){
//         cout << v[i] << ' ';
//     }
// }