#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    
    unordered_map<int, int> mp;
    
    int s = nums.size();
    
    for(int i = 0; i <= s; i++){
        
        int tmp = target - nums[i];
        
        if(mp.find(tmp) != mp.end()){
            
            return {mp[tmp], i};
            
        }
        mp[nums[i]] = i;
    }

    return {-1, -1};

}

int main(){
    vector<int> v = {1, 2, 3, 4, 5};


    vector<int> r = twoSum(v, 9);
    for(int i = 0; i < r.size(); i++){
        cout << r[i];
    }
    

    

    
}