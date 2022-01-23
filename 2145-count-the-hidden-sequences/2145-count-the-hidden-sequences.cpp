class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        long count = 0, mx = 0, mi =0;
        for(int i = 0; i<differences.size(); i++){
            count+= differences[i];
            mx = max(mx,count);
            mi = min(mi,count);
        }
        return max(0L, (upper - lower) - (mx - mi) + 1);
    }
};