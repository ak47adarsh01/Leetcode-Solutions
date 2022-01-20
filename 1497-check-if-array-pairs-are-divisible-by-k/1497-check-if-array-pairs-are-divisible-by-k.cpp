class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        int mods[k];
        memset(mods, 0, sizeof(mods));
        for(int x : arr) {
            if(x < 0)
                ++mods[(k+(x%k))%k];
            else
                ++mods[x%k];
        }

        if(mods[0] & 1)
            return false;
        if(k%2==0 && mods[k/2] & 1)
            return false;

        for(int i=1; i<=k/2; ++i) {
            if(mods[i] != mods[k-i])
                return false;
        }
        return true;
    }
};