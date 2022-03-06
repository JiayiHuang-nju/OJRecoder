#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        vector<vector<bool> > dp(n, vector<bool>(n));
        for (int i = 0; i < n; i++) {
            dp[i][i] = true;
        }
        // cout << "1 element done." << endl;
        int maxLen = 1, begin = 0;
        for (int L = 1; L <= n; L++) {
            // cout << "L = " << L << endl;
            for (int i = 0; i < n; i++) {
                int j = L + i - 1;
                if (j >= n) break;

                if (s[i] != s[j]) dp[i][j] = false;
                else {
                    if (L < 4) dp[i][j] = true;
                    else dp[i][j] = dp[i+1][j-1];
                }
                if (dp[i][j] && L > maxLen) {
                    maxLen = L;
                    begin = i;
                }
            }
        }
        return s.substr(begin, maxLen);
    }
};

int main() {
    Solution so;
    string s;
    cin >> s;
    cout << so.longestPalindrome(s) << endl;
    return 0;
}