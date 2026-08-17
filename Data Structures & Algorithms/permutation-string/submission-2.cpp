class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;

        map<char, int> mp;

        for (char c : s1)
            mp[c]++;

        int l = 0;
        int freq = s1.size();

        for (int r = 0; r < s2.size(); r++) {

            // Add s2[r] to window
            if (mp[s2[r]] > 0) {
                freq--;
            }
            mp[s2[r]]--;

            // Window too large
            if (r - l + 1 > s1.size()) {

                // Remove s2[l] from window
                mp[s2[l]]++;

                if (mp[s2[l]] > 0) {
                    freq++;
                }

                l++;
            }

            // All required characters matched
            if (freq == 0)
                return true;
        }

        return false;
    }
};