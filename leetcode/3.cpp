class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int a[200] = {0};
        int l = 0, r = 0;
        int maxi = 0;
        int n = s.size();
        while(r < n){
            a[s[r++]-' ']++;
            if(a[s[r-1]-' '] > 1){
                while(s[l] != s[r-1]){
                    a[s[l]-' ']--;
                    l++;
                }
                a[s[l]-' ']--;
                l++;
                maxi = max(maxi,r-l);
            }
            else{
                maxi = max(maxi,r-l);
            }
        }
        return maxi;
    }
};
