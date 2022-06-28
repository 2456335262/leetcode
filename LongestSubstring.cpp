#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int max = 0;
        int l = s.length();
        
        for(int i = 0; i < l - max; i++){
            
            if(longest(s.substr(i, l - i)) > max){
                max = longest(s.substr(i, l - i));
            }
        }
        return max;
        
    }
    
    int longest(string s){

    unordered_map<char, int> mp;
    int l = s.length() - 1;
    
    for(int i = 0; i < l; i++){
        
        mp[s[i]] = i;
        
        if ((mp.find(s[i + 1]) != mp.end())){
            return i + 1;
        }        
    }

    return l + 1;
}
};