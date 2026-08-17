class Solution {
public:
    int characterReplacement(string s, int k) {
        map<char, int> mp;
        int n = s.size();
        int l=0, r=0;
        int len=0;
        int maxfreq=INT_MIN;
        while(r<n){
            mp[s[r]]++;
            maxfreq = max(maxfreq, mp[s[r]]);
            len++;
            while(len-maxfreq > k){
                mp[s[l]]--;
                len--;
                l++;
            }
            r++;
        }
        return len;
    }
};
