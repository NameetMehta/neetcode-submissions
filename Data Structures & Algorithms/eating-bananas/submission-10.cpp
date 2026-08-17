class Solution {
public:
    bool calctime(int k, vector<int>& piles, int h){
        int time = 0;
        for(int i=0; i<piles.size(); i++){
            time += piles[i]/k;
            if(piles[i]%k != 0) time++;
        }
        if(time<=h) return true;
        else return false;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi=INT_MIN;
        int mini=1;
        for(int i=0; i<piles.size(); i++){
            maxi = max(maxi, piles[i]);
        }
        int ans=INT_MAX;
        while(mini<=maxi){
            int k = mini + (maxi-mini)/2;
            if(calctime(k, piles, h)){
                ans = min(ans, k);
                maxi = k-1;
            }
            else mini=k+1;
        }
        return ans;
    }
};
