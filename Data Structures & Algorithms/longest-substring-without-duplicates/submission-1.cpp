class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0;
        int r=0;
        int len=0;
        map<char, int> mp;
        while(r<s.size()){
            if(mp.find(s[r])!=mp.end()){
                if(mp[s[r]] >= l) l=mp[s[r]]+1;
            }
            len = max(len, r-l+1);
            mp[s[r]]=r;
            r++;
        }
        return len;
    }
};
