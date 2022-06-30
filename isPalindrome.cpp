#include <iostream>

using namespace std;


class Solution {
public:
    bool isPalindrome(int x) {
        
        int reverse = 0;
        
        if(x == 0) return true;
        
        if(x < 0 || x % 10 == 0) return false;
        
        while(x > reverse){
            
            reverse = reverse * 10 + x % 10;
            
            x = x / 10;
        }
        
        if(x == reverse || reverse / 10 == x) return true;
        
        return false;
    }
};