#include<iostream>
#include<string>
#include<unordered_set>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = -1, right = 0;
        int len = s.length();
        int max_sublen = 1;
        unordered_set<char> occ;
        for (int i = 0; i < len; i++) {
            if (i != 0)
                occ.erase(i-1);
            
        }
    }
};