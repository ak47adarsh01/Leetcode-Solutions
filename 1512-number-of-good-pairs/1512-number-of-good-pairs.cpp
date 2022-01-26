class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        // support variables
        int res = 0, seen[101] = {};
        // populating seen with all the frequencies
        for (int n: nums) seen[n]++;
        // updating res based on the found frequencies
        for (int f: seen) if (f) res += f * (f - 1) / 2;
        return res;
    }
};