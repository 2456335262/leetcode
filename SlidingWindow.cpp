#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int maxx = 0;
        int i = 0;
        int j = 0;
        
        unordered_map<char, int> mp;
        
        char l = s.length();
        
        for(int j = 0; j < l; j++){
            
            if(mp.find(s[j]) != mp.end()){
                
                i = max(mp[s[j]], i);
            }
            
            maxx = max(j - i + 1, maxx);
            mp[s[j]] = j + 1;
        }
        return maxx;
    }
};